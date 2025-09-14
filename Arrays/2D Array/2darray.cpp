#include <iostream>
using namespace std;

// SPIRAL MATRIX
void spiralMatrix(int mat[][4], int n, int m) {
    int srow = 0, scol = 0;
    int erow = n-1, ecol = m-1;

    while(srow<=erow && scol<=ecol) {  
        //for odd matrix write both condition 
        // top
        for (int j = scol; j<=ecol; j++) {
            cout << mat[srow][j] << " ";
        }
        
        // right
        for (int i = srow+1; i<=erow; i++) {
            cout << mat[i][ecol] << " ";
        }
        
        // bottom
        for (int j = ecol-1; j>=scol; j--) {
            
            if (srow == erow) { // corner case for add matrix

                break;
            }
            cout << mat[erow][j] << " ";
        }
        
        // left
        for (int i = erow-1; i>=srow+1; i--) {
            
            if (scol == ecol) { // corner case for add matrix
                break;
            }
            cout << mat[i][scol] << " ";
        }

        srow++; scol++;
        erow--; ecol--;
    }
}

// DIAGONAL SUM OF A MATRIX
int diagonalSum(int mat[][4], int n) {
    int sum = 0;
    
    // O(N)
    for (int i = 0; i<n; i++)  {
        sum += mat[i][i]; //pd
        if(i != n-i-1) {
            sum += mat[i][n-i-1]; // sd
        }
    }

    cout << "SUM = " << sum << endl;
    return sum;
}



// FROM GFG



int main() {
    int matrix[4][4] = { {1, 2, 3,},
                            {4, 5,6},
                            {7, 8, 9},
                            };
    int n = 3, m = 4;


    // spiralMatrix(matrix, n, m);
    diagonalSum(matrix, n);

    return 0;
}