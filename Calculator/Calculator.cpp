#include <iostream>
#include <vector>
#include "Token.h"
#include "Token_stream.h"
#include "std_lib_facilities.h"

double expression();   
double term();         
double primary();     

Token_stream ts;
const std::string prompt = "> ";
const std::string result = "= ";
const char quit = 'q';
const char print = ';';
const char number = '8';

void clean_up_mess()
{
    ts.ignore(print);
}
void calculate()
{
    try
    {
        while (std::cin)
        {
            std::cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t = ts.get();
            if (t.kind == quit) return;
            ts.putback(t);
            std::cout << result << expression() << '\n';
        }
    }
    catch (exception& e)
    {
        cerr << e.what() << '\n';
        clean_up_mess();
    }

}
int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
        calculate();
        return 0;
    }
    catch (runtime_error& e)
    {
        cerr << e.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "Исключение \n";
        return 2;
    }

}

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("Ожидалась ')'");
        return d;
    }
    case '8':
        return t.value;
        break;
    case '-':
        return -primary();
    case '+':
        return primary();
    default:
        error("Требуется первичное выражение!");
    }

}

double term()
{
    double left = primary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("Деление на ноль!");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }

}

double expression()
{
    double left = term();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

