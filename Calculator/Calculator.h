#pragma once
#include <string>
#include "Token_stream.h"
#include "std_lib_facilities.h"

class Calculator
{
public:
	double calculate(const std::string& s);
	double expression();
	double term();
	double primary();
};

