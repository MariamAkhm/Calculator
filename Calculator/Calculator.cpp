#include <iostream>
#include <string>
#include <sstream>
#include "Token.h"
#include "Token_stream.h"
#include "Calculator.h"
#include "std_lib_facilities.h"

Token_stream ts;
Calculator it;
const std::string prompt = "> ";
const std::string result = "= ";
const char quit = 'q';
const char print = ';';
const char number = '8';

void clean_up_mess() {
    ts.ignore(print);
}
double Calculator::calculate(Token t) {
   //std::stringstream str_stream{s};
    //const std::string& s
    try {
            std::cout << prompt;
            //Token t = ts.get();
            while (t.kind == print) t = ts.get();
            if (t.kind == quit)
                return 0;
            ts.putback(t);
            double res = it.expression();
            return res;
    }
    catch (exception& e) {
        cerr << e.what() << '\n';
        clean_up_mess();
        return 0;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    //std::stringstream str_stream{ };
    Token t = ts.get();
    try {
        std::cout<<it.calculate(t);
        return 0;
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "Исключение \n";
        return 2;
    }
}

double Calculator::primary() {
   Token t = ts.get();
    switch (t.kind) {
    case '(': {
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

double Calculator::term() {
    double left = primary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/': {
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

double Calculator::expression() {
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


