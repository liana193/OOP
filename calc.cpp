#include "std_lib_facilities.h"

const char number = '#';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";

class Token{
public:
    char kind;
    double value;
};
void print_token(Token t);

void print_token(Token t){
    cout << "Token.kind: " << t.kind << " Token.value: " << t.value << "\n";
}


class Token_stream{
public:
    Token get();
    void putback(Token t);
    void ignore(char c);
private:
    Token buffer;
    bool full{false};
};

void Token_stream::putback(Token t){
    buffer = t;
    full = true;
}

void Token_stream::ignore(char c)
{
    if(full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while(cin >> ch)
        if(ch == c) return;
}

Token Token_stream::get(){
    if(full){
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;
    switch(ch){
    case quit: case print: case '(': case ')': case '+': case '-': case '*': case '/': case '%':
        return Token{ch};
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        {
           cin.putback(ch);
           double val;
           cin >> val;
           return Token{number, val};
        }
    default:
        return Token{ch, 1};

    }
    return Token{quit};
}

Token_stream ts;

double expression();
double term();
double primary();

double expression(){
    double left = term();
    Token t = ts.get();
    while(true){
        switch(t.kind){
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

double term(){
    double left = primary();
    Token t = ts.get();
    while(true){
        switch(t.kind){
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
         {
            double d = primary();
            if (d == 0)error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = primary();
            if (d == 0)error("divide by zero");
            left = fmod(left, d);
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

double primary(){
    Token t = ts.get();
    switch(t.kind){
        case '(':
        {
          double d = expression();
          t = ts.get();
          if (t.kind != ')') error("')' expected");
          return d;
        }
        case number:
            return t.value;
        case '-':
            return -primary();
        case '+':
            return primary();
        default:
            string s = "primary expected ";
            s.push_back(t.kind);
            error(s);

    }
}

void clean_up_mess(){
    ts.ignore(print);
}

void calculate(){
    while (cin)
        {
            cout << prompt;
            try{
                Token t = ts.get();
                while(t.kind == print) t = ts.get();
                if(t.kind == quit)
                    return;
                ts.putback(t);
                cout << result << expression() << '\n';
            }
            catch(exception& e){
                cout << e.what() << '\n';
                clean_up_mess();
            }
        }
}

/*
Grammer:
Expression:
    Term
    Expression "+" Term
    Expression "-" Term
Term:
    Primary
    Term "*" Primary
    Term "/" Primary
Primary:
    Number
    "("Expression")"
    "-" Primary
    "+" Primary

*/

int main(){
    calculate();
}
