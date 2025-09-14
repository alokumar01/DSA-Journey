#include<iostream>
using namespace std;

// getIthBit

// int getIthBit(int num, int i) {
//     int bitMask = 1 << i;
//     if ( !(num & bitMask)) {
//         return 0;
//     }else {
//         return 1;
//     }
// }

// int main() {
//     cout << getIthBit(7, 1) << endl;
//     return 0;
// }


// set ith bit
// int setIthBit(int num, int i) {
//     int bitMask = 1 << i;
//     return (num | bitMask);
// }

// int main() {
//     cout << setIthBit(6, 3) << endl;
//     return 0;
// }


// clear ith bit
// int clearIthBit(int num, int i) {
//     int bitMask = ~(1 << i);
//     return (num & bitMask);
// }
// int main() {
//     cout << clearIthBit(6, 1) << endl;
//     return 0;
// }

// check for power of 2
// bool isPower(int num) {
//     if (!(num & (num - 1) )) {
//         return true;
//     } else {
//         return false;
//     }
// }
// int main() {
//     cout << isPower(4) << endl;
//     return 0;
// }

// COUNT SET BIT

// void countSetBit(int num) {
//     int count = 0;
//     while(num > 0) {
//         int lastDig = num & 1;
//         count+=lastDig;
//         num = num >> 1;
//     }

//     cout <<  count;
// }

// int main() {
//     countSetBit(10);
//     return 0;
// }

// FAST EXPONENTIAL

void fastExpo(int x, int n) {
    int ans = 1;
    while ( n > 0) {
        int lastBit = n & 1;
        if(lastBit) {
            ans = ans * x;
        }
        x = x*x;
        n = n >> 1;
    }
    
    cout << ans; 
}

int main() {
    fastExpo(3, 5);
    return 0;
}