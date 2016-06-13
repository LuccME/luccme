// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
#pragma once

//Language
#define DEFAULTLANGUAGE "br"

//Mode
#define NEWMODEL  1
#define OPENMODEL 2

//Demand Components
#define PCVINPE		1
#define CITWODM		2
#define CITHREEDM	3

//Potential Components
#define NEIGHSIMPLERULE						1
#define NEIGHINVERSEDISTANCERULE			2
#define INVERSEDISTANCERULE					3
#define LOGISTICREGRESSION					4
#define NEIGHATTRACTIONLOGISTICREGRESSION	5
#define DMAXENTLIKE							6
#define ATTRACTREPULSELOGISTICREGRESSION	7
#define LINEARREGRESSION					8
#define SPATIALLAGREGRESSION				9
#define SPATIALLAGLINEARROADS				10
#define CMAXENTLIKE							11

//Allocation Components
#define ALLOCATIONBYSIMPLEORDERING		1
#define ALLOCATIONCLUESLIKE				2
#define ALLOCATIONCLUESNEIGHBORORDERING	3
#define ALLOCATIONCLUELIKE				4
#define ALLOCATIONCLUELIKESATURATION	5

//TabPages
#define	SAVEPARAM	4	//Save Parameters
#define ADVRES		6	//Advanced Resources
#define VALIDATION	7

//Data values
#define TRUE	1
#define FALSE	0
#define NONE	0

//Regression
#define REGRESSIONNUMBER 9		 //Starts in 0
#define INITIALREGRESSIONSHOW 2  //Absolute value

//Components Number
#define NUMDISCPOTCOMP 7
#define NUMDISCALLOCCOMP 3

//Miscellaneous
#define ROOTDIR	4
#define SECOND	1000

// TODO: reference additional headers your program requires here
