#include <iostream>
using namespace std;

bool isAnagram(string str1,string str2) {
    if (str1.length() != str2.length()) {
        cout << "not valid anagrams\n";
        return false;
    }

    int count[26] = {0};
    for(int i = 0; i<str1.length();i++) {
        int idx = str1[i]-'a';
        count[idx]++;
    }
    
    for (int i = 0; i<str2.length(); i++) {
        int idx = str2[i] -  'a';
        if (count[idx] == 0) {
            cout << "not valid anagrams\n";
            return false;
        }
        count[idx]--;
    }

    cout << "valid anagrams\n";
    return true;
}

int main() {
    string string1 = "anagram";
    string string2 = "nagaram";
    isAnagram(string1, string2);
    
    return 0;
}