#include <iostream>
#include <vector>
#include <string>
#include "Token.h"
#include "Token_stream.h"
#include "Calculator.h"
#include "std_lib_facilities.h"

Token_stream ts;
Token tn = ts.get();
Calculator it;
const std::string prompt = "> ";
const std::string result = "= ";
const char quit = 'q';
const char print = ';';
const char number = '8';

void clean_up_mess() {
    ts.ignore(print);
}
void calculate() {
    try {
        while (std::cin) {
            std::cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t = ts.get();
            if (t.kind == quit)
                return;
            ts.putback(t);
            double res = it.expression(t);
            std::cout << result << res << '\n';
        }
    }
    catch (exception& e) {
        cerr << e.what() << '\n';
        clean_up_mess();
    }

}
int main() {
    setlocale(LC_ALL, "Russian");
    try {
        calculate();
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

double Calculator::primary(Token t) {
    t = ts.get();
    switch (t.kind) {
    case '(': {
        double d = expression(tn);
        t = ts.get();
        if (t.kind != ')') error("Ожидалась ')'");
        return d;
    }
    case '8':
        return t.value;
        break;
    case '-':
        return -primary(t);
    case '+':
        return primary(t);
    default:
        error("Требуется первичное выражение!");
    }

}

double Calculator::term(Token t) {
    double left = primary(t);
    t = ts.get();
    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary(t);
            t = ts.get();
            break;
        case '/': {
            double d = primary(t);
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

double Calculator::expression(Token t) {
    double left = term(t);
    t = ts.get();
    while (true) {
        switch (t.kind) {
        case '+':
            left += term(t);
            t = ts.get();
            break;
        case '-':
            left -= term(t);
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}


