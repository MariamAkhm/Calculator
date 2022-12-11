#pragma once
#include "Token_stream.h"
#include "std_lib_facilities.h"

class Calculator
{
public:
	void calculate();
	double expression();
	double term();
	double primary();
};

