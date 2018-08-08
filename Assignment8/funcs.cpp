#include "std_lib_facilities.h"
#include "funcs.h"
#include <functional>
#include <map>

using namespace std;

std::map<const string, std::function<double(double)> > dispTable {
    {"sin", [](double a) { return sin(a); }},
    {"cos", [](double a) { return cos(a); }},
    {"tan", [](double a) { return tan(a); }},
    {"asin", [](double a) { return asin(a); }},
    {"acos", [](double a) { return acos(a); }},
    {"atan", [](double a) { return atan(a); }},
    {"log", [](double a) { return log(a); }},
    {"log2", [](double a) { return log2(a); }},
    {"log10", [](double a) { return log10(a); }},
    {"sqrt", [](double a) { return sqrt(a); }},
};

double exec_func(string fname, double arg)
{
    try {
        return dispTable[fname](arg);
    }
    catch(exception) {
        cout << "Error: undefined function " << fname << '\n';
    }
}
