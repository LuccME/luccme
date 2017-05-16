// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
#pragma once

//Target
//#define LUCCME	1

//Language
#define DEFAULTLANGUAGE "br"

//Mode
#define NEWSCRIPT  1
#define OPENSCRIPT 2

//List TYPES
#define RASTERLIST		7
#define POLYGONLIST		13
#define NONPOLYGONLIST	12

//Raster
#define COVERAGE	0
#define AVERAGE		1
#define MODE		2
#define MAXIMUM		3
#define MINIMUM		4
#define SUM			5
#define STDEV		6

//Polygon
#define P_COVERAGE  0
#define P_AVERAGE	1
#define P_AREA		2
#define P_DISTANCE	3
#define P_PRESENCE	4
#define P_MODE		5
#define P_MAXIMUM	6
#define P_MINIMUM	7
#define P_SUM		8
#define P_COUNT		9
#define P_LENGTH	10
#define P_STDEV		11
#define P_NEAREST	12

//Non Polygon
#define NP_COVERAGE 0
#define NP_AVERAGE	1
#define NP_DISTANCE	2
#define NP_PRESENCE	3
#define NP_MODE		4
#define NP_MAXIMUM	5
#define NP_MINIMUM	6
#define NP_SUM		7
#define NP_COUNT	8
#define NP_LENGTH	9
#define NP_STDEV	10
#define NP_NEAREST	11

//TabPages
#define ATTRFULFILL  2
#define RUNSCRIPT	 3

//Data values
#define TRUE	1
#define FALSE	0
#define NONE	0

//Attributes Structure
#define AS_ATTRIBUTE	0
#define AS_OPERATION	1
#define AS_SELECT		2
#define AS_AREA			3
#define AS_DEFAULT		4
#define AS_OUTPUT		5
#define AS_DUMMY		6
#define AS_SHPTYPE		7

//Parameters
#define PARAMETERSNUMBER 6
#define SCRIPTFOLDER	 0
#define SCRIPTNAME		 1
#define SHPADDRESS		 2
#define SHPOUTNAME		 3
#define SHPRESOLUTION	 4
#define SCRIPTATTRIBUTES 5

//Miscellaneous
#define ROOTDIR		4
#define SECOND		1000
#define EXTENSION	4



// TODO: reference additional headers your program requires here
