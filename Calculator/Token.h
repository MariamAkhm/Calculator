#pragma once
class Token
{
public:
    char kind;
    double value;
    Token() {}
    Token(char ch)
        :kind(ch) {}
    Token(char ch, double val)
        :kind(ch), value(val) {}
};


