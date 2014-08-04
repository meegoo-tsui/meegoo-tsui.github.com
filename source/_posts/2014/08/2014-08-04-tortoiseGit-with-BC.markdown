---
layout: post
title: "TortoiseGit With Beyond Compare 3"
date: 2014-08-04 22:33
comments: true
categories: git
---

<!---
################################################################################
-->

### Diff ###

*	Launch TortoiseGit | Settings

*	Switch to the Diff Viewer section under External Programs

*	Change the radio buttons from TortoiseMerge to External.In the path edits, enter:

	*	"D:\Program Files (x86)\Beyond Compare 3\BComp.exe" %base %mine /title1=%bname /title2=%yname /leftreadonly

### Merge ###

*	Launch TortoiseGit | Settings

*	Switch to the Merge Tool section under External Programs

*	Change the radio buttons from TortoiseMerge to External.In the path edits, enter:

	*	"D:\Program Files (x86)\Beyond Compare 3\BComp.exe" %mine %theirs %base %merged /title1=%yname /title2=%tname /title3=%bname /title4=%mname

<hr />

