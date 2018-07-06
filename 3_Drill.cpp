#include "std_lib_facilities.h"

int main(){
	cout << "Pleae enter your name:\n";
	string first_name; //variable of type string
	cin >> first_name; //reads chracters into first name
	cout << "Dear " << first_name << "\n";

	cout << "Pleae enter your friend's name:\n";
	string friend_name;
	cin >> friend_name;
	cout << "Have you seen  " << friend_name << " lately?" << "\n";

	cout << "Enter Age: \n";
	int age;
	cin >> age;
	if(age < 0)
	    simple_error("That is not an age! \n");
    else if(age > 110)
        simple_error("That is too old! \n");
	cout << "I hear you had a birthday and you are now  " << age << " years old" << "\n";



}