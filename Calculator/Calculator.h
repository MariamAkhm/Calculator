#pragma once
#include "Token_stream.h"
#include "std_lib_facilities.h"

class Calculator
{
public:
	double expression();
	double term();
	double primary();
};

