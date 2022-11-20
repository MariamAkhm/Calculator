#pragma once
class Token
{
public:
    char kind;
    double value;
    Token(char ch)
        :kind(ch) {}
    Token(char ch, double val)
        :kind(ch), value(val) {}
};


