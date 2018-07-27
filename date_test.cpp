#include "std_lib_facilities.h"
#include "date.h"

int main(){
    cout << "Please enter a date in format (YYYY,MM,DD): ";
    Date input;
    cin >> input;

    Date tomorrow = input;
    tomorrow.add_day(1);
    cout << "Date of day after input(tomorrow): " << tomorrow << '\n'<< '\n';

    cout << "Testing << operator overloading:\n" << "Date: " << input << '\n'<< '\n';

    cout << "Testing == operator overloading:\n";
    cout << "input == tomorrow: " <<(input == tomorrow) << '\n';
    cout << "input == input: " <<(input == input) << '\n'<< '\n';

    cout << "Testing != operator overloading:\n";
    cout << "input != tomorrow: " <<(input != tomorrow) << '\n';
    cout << "input != input: " <<(input != input) << '\n'<< '\n';

    int n;
    cout << "Testing adding days:\n";
    cout << "Enter # days to add to input date: ";
    cin >> n;
    cout << "Before: " << input << '\n';
    input.add_day(n);
    cout << "After: " << input << '\n' << '\n';

    cout << "Testing adding months:\n";
    cout << "Enter # months to add to input date: ";
    cin >> n;
    cout << "Before: " << input << '\n';
    input.add_month(n);
    cout << "After: " << input << '\n' << '\n';

    cout << "Testing adding years:\n";
    cout << "Enter # years to add to input date: ";
    cin >> n;
    cout << "Before: " << input << '\n';
    input.add_year(n);
    cout << "After: " << input << '\n' << '\n';

    Date def;
    cout << "Testing Default Value:\n";
    cout << def << '\n' << '\n';

    cout << "Testing Long Form of Tomorrow's Date: \n";
    tomorrow.longForm();
    cout << '\n' << '\n';

    cout << "Testing Leap Year (2000, 2, 28):\n";
    Date leap{2000, Month::February, 28};
    cout << leap.leapYear() << '\n' << '\n';

    cout << "Testing Leap Year (2003, 2, 28):\n";
    Date noLeap{2003, Month::February, 28};
    cout << noLeap.leapYear() << '\n' << '\n';

    cout << "Testing for Valid Date (2020, January, 40):\n";
    Date invld{2020, Month::January, 40};


    return 0;
}
