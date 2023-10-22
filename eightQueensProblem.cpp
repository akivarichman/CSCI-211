#include <iostream>
using namespace std;

int main() {
    int b[8][8] = {0}, row, col = 0, sol = 1; // initializing the data structure for the 2D board, row, and column
    b[0][0] = 1; // putting a queen in the top right square

nextcol:
    col++; // go to next column 

    if(col == 8){ // once a queen is placed in each column
        goto print;
    }
    row =-1;

nextrow:
    row++; // go to next row
    if(row == 8){ // once no queen can be placed in any of the rows
        goto backtrack;
    }

    for(int i = 0; i < col; i++){ // row test
        if(b[row][i]==1){
            goto nextrow;
        }
    }
    for(int i = 1; (row - i) >= 0 && (col - i) >= 0; i++){ // up-diagonal test
        if(b[row-i][col-i] == 1){
            goto nextrow;
        }
    }
    for(int i = 1; (row + i) < 8 && (col - i) >= 0; i++) { // down-diagonal test
        if(b[row+i][col-i] == 1) {
            goto nextrow;
        }
    }

    b[row][col] = 1; // places a queen in the square once it passes all the tests
    goto nextcol;

backtrack:
    col--;
    if(col==-1) return 0; // we can no longer backtrack, have found all the solutions, and are done
    row = 0;
    while(b[row][col] != 1){ // find which row in that column the queen is in
        row++;
    }
    b[row][col] = 0; // remove the queen
    goto nextrow;

print:
    cout << "Solution Number: " << sol++ << endl;
    for(int r = 0; r < 8; r++){
        for(int c = 0; c < 8; c++){
            cout << b[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
    goto backtrack;
}