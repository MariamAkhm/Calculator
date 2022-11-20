#pragma once
#include "Token.h"
class Token_stream
{
private:
    bool full;
    Token buffer;
public:
    Token_stream() :full(false), buffer(0) {};
    Token get();
    void putback(Token t);
    void ignore(char ñ);

};



