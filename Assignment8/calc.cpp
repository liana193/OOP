#include "std_lib_facilities.h"
#include "token.h"
#include "vars.h"
#include "funcs.h"

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
    if(t.kind == root){
        double d = primary();
        return pow(d, 1.0/left);
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
                d = exec_func(t.name, d);
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
    double ans;
    while (cin)
        {
            try{
                cout << prompt;
                Token t = ts.get();
                while(t.kind == print) t = ts.get();
                if(t.kind == quit)
                    return;
                else if(t.kind == arrow) {
                    int count = 2;

                    Token next_t = ts.get();
                    while(next_t.kind != ';'){
                        count++;
                        next_t = ts.get();
                    }

                    int c = ts.prev_calcs.size()-count;
                    if(c < 0)
                       cout << "error: out of range " << c << '\n';
                    else{
                        string s = ts.prev_calcs[c];
                        cout << prompt << s << '\n';
                        ts.create_input(s);
                    }
                }
                else{
                    ts.putback(t);
                    ans = statement();
                    set_value("ans", ans);
                    cout << result << setprecision(10) << ans << '\n';
                }
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
    set_value("pi", 3.1415926535);
    set_value("e", 2.7182818284);

    ts.prev_calcs.push_back("");
    calculate();
}

