#include "std_lib_facilities.h"

int main()
{
    vector<string> words;
    for(string s; cin>>s; )
        words.push_back(s);
    sort(words);
    cout << "Number of Words in List: " << words.size() << "\n";
    cout << "Sorted: \n";
    for(string s: words)
        cout << s << "\n";

    cout << "Delete Duplicates: \n";

    vector<int> count = {1};
    string dup = words[0];
    vector<string> noDup = {dup};

     int j = 0;
     for(int i = 1; i < words.size(); i++){
        if(dup.compare(words[i]) != 0){
            noDup.push_back(words[i]);
            dup = words[i];
            j++;
            count.push_back(1);
        }
        else{
            count[j]++;
        }
     }

     int c = 0;
     for(string s: noDup){
        cout << s << ": " << count[c] << "\n";
        c++;
     }
    keep_window_open();
}
