#include "std_lib_facilities.h"

class vect{
    int sz;
    double* elem;
public:
    vect(int s)
        :sz{s}, elem{new double [s]} {/* */}
    ~vect(){delete[] elem;}
    double get(int i) {return elem[i];}
    void set(int i, double d){elem[i] = d;}
    vect(const vect& arg)
    :sz{arg.sz}, elem{new double[arg.sz]}
    {
        copy(arg.elem, arg.elem + arg.sz, elem);
    }
    vect& operator=(const vect& a)
    {
        double* p = new double[a.sz];
        copy(a.elem, a.elem + a.sz, p);
        delete[] elem;
        elem = p;
        sz = a.sz;
        return *this;
    }
    double& operator[](int n) {return elem[n];}
};


void f(int n){
    vect v(3);
    v.set(2, 2.2);
    vect v2 = v;
    v.set(1, 9.9);
    v2.set(0, 8.8);
    cout << v.get(0) << ' ' << v2[1] << ' ' << v2.get(2) << '\n';
}

int main(){
    int i;
    while(i < 10000){
        f(10);
        i++;
    }
}


