#include "std_lib_facilities.h"
#include "token.h"
#include "vars.h"

const string prompt = "> ";
const string result = "= ";


Token_stream ts;

double statement();
double expression();
double term();
double expon();
double primary();

double statement(){
    Token t = ts.get();
    if(t.kind == name){
        Token var = t;
        t = ts.get();
        if(t.kind == '='){
            double d = expression();
            set_value(var.name, d);
            return d;
        }
        else if(t.kind == print){
            ts.putback(t);
            return get_value(var.name);
        }
        ts.putback(t);
        ts.putback(var);
        return expression();
    }
    ts.putback(t);
    return expression();

}

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
    double left = expon();
    Token t = ts.get();
    while(true){
        switch(t.kind){
        case '*':
            left *= expon();
            t = ts.get();
            break;
        case '/':
         {
            double d = expon();
            if (d == 0)error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = expon();
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

double expon(){
    double left = primary();
    Token t = ts.get();
    if(t.kind == power){
        double d = primary();
        return pow(left, d);
    }
    else{
        ts.putback(t);
        return left;
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
        case name:{
            Token next_t = ts.get();
            if(next_t.kind == '('){
                double d = expression();
                t = ts.get();
                if (t.kind != ')') error("')' expected");
                return d;
            }
            else{
                ts.putback(next_t);
                return get_value(t.name);
            }
        }
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
            try{
                cout << prompt;
                Token t = ts.get();
                while(t.kind == print) t = ts.get();
                if(t.kind == quit)
                    return;
                ts.putback(t);
                cout << result << setprecision(10) << statement() << '\n';
            }
            catch(exception& e){
                cout << e.what() << '\n';
                clean_up_mess();
            }
        }
}

/*
Grammer:
Statement:
    Var "=" Expression
    Var ";"
    Expression
Expression:
    Term
    Expression "+" Term
    Expression "-" Term
Term:
    Primary
    Term "*" Primary
    Term "/" Primary
    Term "%" Primary
Exp:
    Primary
    Primary "^" Primary
Primary:
    Number
    "("Expression")"
    "-" Primary
    "+" Primary
*/

int main(){
    calculate();
}

