#include "std_lib_facilities.h"
#include "token.h"

std::ostream &operator<<(std::ostream &os, Token const &t) {
    return os << t.kind;
}

void Token_stream::ignore(char c)
{
    while(buffer.size() > 0) {
        Token t = popback();
        if(t.kind == c) return;
    }

    char ch = 0;
    while(cin>>ch)
        if(ch == c) return;
}

void Token_stream::putback(Token t){
    buffer.push_back(t);
}

Token Token_stream::popback()
{
    Token t = buffer.back();
    buffer.pop_back();
    return t;
}

void Token_stream::create_input(string s){
    string reversed(s.rbegin(), s.rend());
     for(char c : reversed)
        cin.putback(c);
}

Token Token_stream::get(){
    if(buffer.size() > 0) {
        Token t = popback();
        return t;
    }

    char ch;
    cin >> ch;
    switch(ch){
    case quit: case '(': case ')': case '+': case '-': case '*': case '/': case mod: case '=': case power: case root:
    {
        prev_calcs[(prev_calcs.size())-1] += ch;
        return Token{ch};
    }
    case print:
    {
        if(prev == 0){
            prev_calcs[(prev_calcs.size())-1] += ch;
            prev_calcs.push_back("");
        }
        else
            prev = 0;
        return Token{ch};
    }
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        {
           prev_calcs[(prev_calcs.size())-1] += ch;
           cin.putback(ch);
           double val;
           cin >> val;
           return Token{number, val};
        }
    case arrow:
    {
        prev = 1;
        return Token{ch};
    }
    default:
        if(isalpha(ch)){
            string s;
            s += ch;
            while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+= ch;
            cin.putback(ch);
            prev_calcs[(prev_calcs.size())-1] += s;
            return Token{name, s};
        }
        return Token{invalid, ch};
    }
    return Token{quit};
}


