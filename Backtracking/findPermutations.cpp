#include<iostream>
using namespace std;
// //All possible arrangements

// void permutation (string str, string ans) {
//     int n = str.size();
//     if (n == 0) {
//         cout << ans << "\n";
//     }

//     for (int i = 0; i<str.size(); i++) {
//         char ch = str[i];
//         string nextChar = str.substr(0, i) + str.substr(i+1, n-i-1);
//         permutation(nextChar, ans+ch);
//     }
// }

// int main() {
//     string str = "abc";
//     string ans = "";
//     permutation(str, ans);
//     return 0;
// }


int permutation(string str, string permute) {
    int n = str.size();
    if(n == 0) {
        cout << permute << "\n";
        return 1; // found one base case 
    }

    int count = 0;
    for(int i = 0; i<n; i++) {
        char ch = str[i];
        string nextChar = str.substr(0, i) + str.substr(i+1, n - i - 1);
        count += permutation(nextChar, permute + ch);
    }

    return count;
}   
int main() {
    string str = "AAA";
    string permute = "";
    int totalcount = permutation(str, permute);
    cout << "All possible permutation: " << totalcount << endl;
    return 0;
}



// unqieu permutation
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Function to generate unique permutations
void uniquePermutation(string str, string permute, set<string> &result) {
    if (str.empty()) {
        result.insert(permute);  // store unique permutation
        return;
    }

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        string nextStr = str.substr(0, i) + str.substr(i + 1);
        uniquePermutation(nextStr, permute + ch, result);
    }
}

int main() {
    string str = "AAA";
    set<string> result;

    uniquePermutation(str, "", result);

    // Print all unique permutations
    for (auto &s : result) {
        cout << s << endl;
    }

    return 0;
}

