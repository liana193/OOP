#include "std_lib_facilities.h"
#include "vars.h"

int main()
{
    set_value("a", 12.7);
    set_value("b", 13.5);
    set_value("c", 240.0);
    set_value("d", 145.3);
    set_value("a", 7.8);

    double d;
    d = get_value("a");
    cout << "a = " << d << endl;
    d = get_value("b");
    cout << "b = " << d << endl;
    d = get_value("c");
    cout << "c = " << d << endl;
    d = get_value("d");
    cout << "d = " << d << endl;
}

