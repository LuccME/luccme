#pragma once
using namespace System;
using namespace System::Collections::Generic;

/*
Struct to create or edit a Model Form
*/
public ref class cReturn
{
public:
	String^ Return;
	String^ Language;
	cReturn()
	{
		Return = "";
		Language = "";
	}
};

/*
Struct to create or edit a Model Form
*/
public ref class cReturnExtModel
{
public:
	String^ Return;
	String^ Language;
	bool Empty;
	cReturnExtModel()
	{
		Return = "";
		Language = "";
		Empty = true;
	}
};

/*
Struct for Pre Computed Value Demand Component
*/
public ref class cReturnPCVINPE
{
public:
	String^ Return;
	int YearsForSimulation;
	bool Empty;
	bool ActiveComponent;
	String^ StartTime;
	String^ LUT;
	String^ Language;
	cReturnPCVINPE()
	{
		Return = "";
		YearsForSimulation = 0;
		Empty = true;
		ActiveComponent = true;
		StartTime = "";
		LUT = "";
		Language = "";
	}
};

/*
Struct for Computed Input Two Maps Demand Component
*/
public ref class cReturnCITwoMP
{
public:
	String^ Return;
	int FinalYear;
	bool Empty;
	bool ActiveComponent;
	String^ LUT;
	String^ Language;
	cReturnCITwoMP()
	{
		Return = "";
		FinalYear = 0;
		Empty = true;
		ActiveComponent = true;
		LUT = "";
		Language = "";
	}
};

/*
Struct for Computed Input Three Maps Demand Component
*/
public ref class cReturnCIThreeMP
{
public:
	String^ Return;
	int MiddleYear;
	int FinalYear;
	bool Empty;
	bool ActiveComponent;
	String^ LUT;
	String^ Language;
	cReturnCIThreeMP()
	{
		Return = "";
		FinalYear = 0;
		MiddleYear = 0;
		Empty = true;
		ActiveComponent = true;
		LUT = "";
		Language = "";
	}
};

/*
Struct for Potential Components
*/
public ref class cReturnPotential
{
public:
	String^ Return;
	String^ LUT;
	String^ Language;
	int Component;
	int Regression;

	cReturnPotential()
	{
		Return = "";
		LUT = "";
		Language = "";
		Component = 0;
		Regression = 1;
	}
};

/*
Struct for Allocation Components
*/
public ref class cReturnAllocation
{
public:
	String^ Return;
	String^ LUT;
	String^ Language;
	int Component;
	int Regression;
	bool PotRegression;

	cReturnAllocation()
	{
		Return = "";
		LUT = "";
		Component = 0;
		Language = "";
		Regression = 1;
		PotRegression = false;
	}
};
