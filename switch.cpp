#include "std_lib_facilities.h"

int main(){
    cout << "Enter Grade \n";
    char grade;
    cin >> grade;

    switch(grade){
        case 'A':
            cout << "Keep up the good work";
            break;
        case 'B':
            cout << "Not Bad";
            break;
        case 'C':
            cout << "You might want to put in more work";
            break;
        case 'D':
            cout << "Pass!, but almost failing :(";
            break;
        case 'F':
            cout << "FAILED";
            break;

    }

}