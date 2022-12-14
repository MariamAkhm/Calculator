#include <iostream>
#include <string>
#include "Token_stream.h"
#include "Token.h"
#include "std_lib_facilities.h"

void Token_stream::putback(Token t) {
   if (full) error("putback() контейнер заполнен!");
    buffer = t;
    full = true;
}

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch (ch) {
    case ';': case 'q': case '(': case ')':
    case '+': case '-': case '*': case '/':
        return Token(ch);
        break;
    case '.': case '0': case '1': case '2':
    case '3': case '4': case '5': case '6':
    case '7': case '8': case '9':
        cin.putback(ch);
        double val;
        cin >> val;
        return Token('8', val);
    default:
        error("Неверная лексема!");
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
