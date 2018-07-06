#include "std_lib_facilities.h"

int main(){
    //double to int
    double d = 100000.66;                               //100001
    int i = d;                                          //100000
    cout << "double to int:\n";
    cout << "Before: d=" << d << " i=" << i << "\n";
    d = i;                                              //100000
    cout << "Ater: d=" << d << "\n";
    cout << "\n";

    //double to char
    d = 1000.66;                                        //1000.66
    char c = d;                                         //
    cout << "double to char:\n";
    cout << "Before: d=" << d << " c=" << c << "\n";
    d = c;                                              //-24
    cout << "Ater: d=" << d << "\n";
    cout << "\n";

    //double to bool
    d = 100.66;                                        //100.66
    bool b = d;                                        //1
    cout << "double to bool:\n";
    cout << "Before: d=" << d << " b=" << b << "\n";
    d = b;                                             //1
    cout << "Ater: d=" << d << "\n";
    cout << "\n";

    //int to char
    i = 1000;                                         //1000
    c = i;                                       //
    cout << "int to char:\n";
    cout << "Before: i=" << i << " c=" << c << "\n";
    i = c;                                            //-24
    cout << "Ater: i=" << i << "\n";
    cout << "\n";

    //int to bool
    i = 100;                                         //100
    b = i;                                           //1
    cout << "int to bool:\n";
    cout << "Before: i=" << i << " b=" << b << "\n";
    i = b;                                           //1
    cout << "Ater: i=" << i << "\n";
    cout << "\n";


    //char to bool
    c = 'a';                                        //a
    b = c;                                          //1
    cout << "char to bool:\n";
    cout << "Before: c=" << c << " b=" << b << "\n";
    c = b;                                          //empty square
    cout << "Ater: c=" << c << "\n";
    cout << "\n";

}