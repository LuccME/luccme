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
#define POTENTIALDNEIGHSIMPLERULE							1
#define POTENTIALDNEIGHINVERSEDISTANCERULE					2
#define POTENTIALDINVERSEDISTANCERULE						3
#define POTENTIALDLOGISTICREGRESSION						4
#define POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT			5
#define POTENTIALDSAMPLEBASED								6
#define POTENTIALDLOGISTICREGRESSIONNEIGHATTRACTREPULSION	7
#define POTENTIALCLINEARREGRESSION							8
#define POTENTIALCSPATIALLAGREGRESSION						9
#define POTENTIALCSPATIALLAGLINEARREGRESSIONMIX				10
#define POTENTIALCSAMPLEBASED								11

//Allocation Components
#define ALLOCATIONDSIMPLEORDERING		1
#define ALLOCATIONDCLUESLIKE			2
#define ALLOCATIONDCLUESNEIGHORDERING	3
#define ALLOCATIONCCLUELIKE				4
#define ALLOCATIONCCLUELIKESATURATION	5

//TabPages
#define COMPONENT   3
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

//Discrete Components Number
#define NUMDISCPOTCOMP 7
#define NUMDISCALLOCCOMP 3

//Validation Methods
#define EXTVALIDATION	0
#define DIFFVALIDATION	1

//Miscellaneous
#define ROOTDIR	4
#define SECOND	1000

// TODO: reference additional headers your program requires here
