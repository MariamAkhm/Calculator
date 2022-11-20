#include <iostream>
#include <string>
#include "Token_stream.h"
//#include "Token.h"
//#include "std_lib_facilities.h"
//
//namespace Token_S {
//	const char quit = 'q';
//	const char print = ';';
//	const char number = '8';
//
//	void Token_stream::ignore(char c)
//	{
//		if (full && c == buffer.kind)
//			full = false;
//		return;
//		full = false;
//		char ch = 0;
//		while (std::cin >> ch)
//			if (ch == c) return;
//	}
//
//	Token Token_stream::get() {
//		if (full) {
//			full = false;
//			return buffer;
//		}
//		char ch = 0;
//		std::cin >> ch;
//		switch (ch) {
//		case quit:
//		case print:
//		case ')' :
//		case '(':
//		case '+':
//		case '-':
//		case '*':
//		case '/':
//			return Token{ ch };
//		case '.':
//		case '0': case '1': case '2': case 'З': case '4':
//		case '5': case '6': case '7': case '8': case '9': {
//			std::cin.putback(ch);
//			double val;
//			std::cin >> val;
//			return Token{ number, val };
//		}
//		default:
//			error("Неверная лексема!");
//		}
//	}
//	void Token_stream::putback(Token t) {
//		if (full)
//			error("putback(): буфер заполнен!");
//		buffer = t;
//		full = true;
//	}
//	void Token_stream::ignore(char c) {
//		if (full && c == buffer.kind)
//			full = false;
//		return;
//		full = false;
//		char ch = 0;
//		while (std::cin>>ch)
//			if (ch == c) return;
//	}
//}
