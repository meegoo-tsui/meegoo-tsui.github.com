/********************** (C) COPYRIGHT 2012 Forsafe ****************************/
/*!
 * @file      tstamp.c
 * @brief     Purpose of this utility is to timestamp each line coming over stdin
 * @author    meegoo tsui
 * @version   1.0
 * @date      2012/06/07
 * USAGES:
 *    1. tstamp.exe < /dev/ttyS0
 *    2. <commands> | tstamp.exe
 */
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>
#include <sys/signal.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MAX_BUF_SIZE	(10*1024)

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
char         buf[MAX_BUF_SIZE]; /*< 数据缓冲 */
sig_atomic_t graceful_quit = 0; /*< 标志    */

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/******************************************************************************/
/*!
 * @fn     void SIGINT_handler (int signum)
 * @brief  Signal handler for SIGINT
 * @param signum signal number
 */
void SIGINT_handler(int signum)
{
	assert (signum == SIGINT);
	graceful_quit = 1;
}

/******************************************************************************/
/*!
 * @fn     void SIGQUIT_handler(int signum)
 * @brief  Signal handler for SIGQUIT
 * @param signum signal number
 */
void SIGQUIT_handler(int signum)
{
	assert (signum == SIGQUIT);
	graceful_quit = 1;
}

/******************************************************************************/
/*!
 * @fn     void main(int argc)
 * @brief  main
 */
void main(int argc)
{
	struct timeval tv;
	double time_start,time_now,time_prev;
	int first = 1;
	struct sigaction sa;

	sigemptyset (&sa.sa_mask);
	sa.sa_flags = 0;

	/* as of now no arguments are allowed. print usage */
	if (argc != 1){
		printf(
			"Timestamps each line coming over stdin\n"
			"\tUSAGES:\n"
			"\t\ttstamp.exe < /dev/ttyS0\n"
			"\t\t<commands> | tstamp.exe\n"
		);

		return;
	}

	/* Register the handler for SIGINT */
	sa.sa_handler = SIGINT_handler;
	sigaction (SIGINT, &sa, 0);

	/* Register the handler for SIGQUIT */
	sa.sa_handler =  SIGQUIT_handler;
	sigaction (SIGQUIT, &sa, 0);

	printf(
		"\tcolumn1 is elapsed time since first message\n"
		"\tcolumn2 is elapsed time since previous message\n"
		"\tcolumn3 is the message\n"
	);

	/* main loop */
	while (graceful_quit == 0){
		if (fgets(buf, MAX_BUF_SIZE, stdin)){
			gettimeofday(&tv, NULL); /* get system time */
			time_now = tv.tv_sec + (tv.tv_usec*(1.0/1000000.0)); /* convert to double */
			if(first){ /* if first time, notedown the time_start */
				first      = 0;
				time_start = time_prev = time_now;
			}
			fprintf(stdout
				,"%03.3f %02.3f: %s"
				,(float)(time_now-time_start)
				,(float)(time_now-time_prev)
				,buf
			);
			time_prev = time_now;
		}
	}

	fflush(stdout);
	return;
}

/********************** (C) COPYRIGHT 2012 Forsafe  *************END OF FILE***/

