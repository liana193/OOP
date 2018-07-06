#include "std_lib_facilities.h"

int main(){
    int num_words = 0;
	string previous = " ";
	string current;
	while (cin >> current){
	    if(previous == current){
	         ++num_words;
	        cout << "word number: " << num_words << " repeated: " << current;
	    }
	    previous = current;
	}
}