#pragma once
#include "Token_stream.h"
#include "std_lib_facilities.h"

class Calculator
{
public:
	double expression(Token t);
	double term(Token t);
	double primary(Token t);
};

