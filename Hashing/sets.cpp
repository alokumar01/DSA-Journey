#include <iostream>
using namespace std;
#include <set>

int main() {
    set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(2);



    for(auto el : s) {
        cout << el << " ";
    }
    cout << endl;
    
    return 0;
}