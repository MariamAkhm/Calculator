//#include <iostream>
//#include <vector>
//#include "Token.h"
//#include "Token_stream.h"
//#include "std_lib_facilities.h"
//
//Token_S::Token_stream ts;
//const std::string prompt = "> ";
//const std::string result = "= ";
//const char quit = 'q';
//const char print = ';';
//const char number = '8';
//double primary();
//double term();
//double expression();
//void calculate();
//void clean_up_mess();
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	try
//	{
//		calculate();
//		keep_window_open();
//		return 0;
//	}
//	catch (runtime_error& e)
//	{
//		cerr << e.what() << endl;
//		keep_window_open("--");
//		return 1;
//	}
//	catch (...)
//	{
//		cerr << "исключение \n";
//		keep_window_open("--");
//		return 2;
//	}
//}
//
//double primary() {
//	Token t = ts.get();
//	switch (t.kind) {
//	case '(': {
//		double d = expression();
//		t = ts.get();
//		if (t.kind != ')') error( "требуется скобка ')'");
//		return d;
//	}
//	case '8': 
//		return t.value;
//	case '-': 
//		return -primary();
//	case '+':
//		return primary();
//	default:
//		error( "Требуется первичне выражение!");
//	}
//}
//double term() {
//	double left = primary();
//	Token t = ts.get();
//	while (true) {
//		switch (t.kind) {
//		case '*':
//			left *= primary();
//			t = ts.get();
//			break;
//		case '/': {
//			double d = primary();
//			if (d == 0) error ("Деление на ноль!");
//			left /= d;
//			t = ts.get();
//		}
//		break;
//		default:
//			ts.putback(t);
//			return left;
//		}
//	}
//}
//double expression() {
//	double left = term();
//	Token t = ts.get();
//	while (true) {
//		switch (t.kind) {
//		case '+':
//			left += term();
//			t = ts.get();
//			break;
//		case '-':
//			left -= term();
//			t = ts.get();
//			break;
//		default:
//			ts.putback(t);
//			return left;
//		}
//	}
//}
//void calculate()
//{
//	try
//	{
//		while (std::cin)
//		{
//			std::cout << prompt;
//			Token t = ts.get();
//			while (t.kind == print) t = ts.get();
//			if (t.kind == quit) return;
//			ts.putback(t);
//			std::cout << result << expression() << '\n';
//		}
//	}
//	catch (exception& e)
//	{
//		cerr << e.what() << '\n';
//		clean_up_mess();
//	}
//
//}
//void clean_up_mess()
//{
//	ts.ignore(print);
//}



#include <iostream>
#include <vector>
#include "std_lib_facilities.h"
using namespace std;

double expression();   
double term();         
double primary();     

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

class Token_stream
{
private:
    bool full;      
    Token buffer;   
public:
    Token_stream() :full(false), buffer(0) {};
    Token get();
    void putback(Token t);
    void ignore(char с);

};


void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer.");
    buffer = t;         
    full = true;        
}

Token Token_stream::get()
{
    if (full) {   
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;       
    switch (ch)
    {
    case ';':
    case 'q':
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return Token(ch);
        break;
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        cin.putback(ch); 
        double val;
        cin >> val;
        return Token('8', val);

    default:
        error("Bad Token");
        break;
    }
}
void Token_stream::ignore(char c) {
    if (full && c == buffer.kind)
        full = false;
    return;
    full = false;
    char ch = 0;
    while (std::cin >> ch)
        if (ch == c) return;
}

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
        cerr << "исключение \n";
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
        if (t.kind != ')') error("')' expected");
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
        error("primary expected");
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
            if (d == 0) error("divided by zero");
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

