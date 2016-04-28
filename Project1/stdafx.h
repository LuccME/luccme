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
#define LINEARREGRESSION					6
#define SPATIALLAGREGRESSION				7
#define SPATIALLAGLINEARROADS				8

//Allocation Components
#define ALLOCATIONBYSIMPLEORDERING		1
#define ALLOCATIONCLUESLIKE				2
#define ALLOCATIONCLUELIKE				3
#define ALLOCATIONCLUELIKESATURATION	4

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
#define NUMDISCPOTCOMP 5
#define NUMDISCALLOCCOMP 2

// TODO: reference additional headers your program requires here
