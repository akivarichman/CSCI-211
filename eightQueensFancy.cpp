#include <iostream>
using namespace std;

// I use strings (\u2588) and not characters (char(219)).

int i,j,k,l;
typedef string box[5][7]; // box now refers to a 2D array of strings (5x7)   
box bb, wb, *board[8][8]; // two boxes called bb and wb and a 2D array called board that containes pointers to boxes
// fill in bq
box bq = {
        {"\u2588", "\u2588", "\u2588", "\u2588", "\u2588", "\u2588", "\u2588"},
        {"\u2588", " ", "\u2588", " ", "\u2588", " ", "\u2588"},
        {"\u2588", " ", " ", " ", " ", " ", "\u2588"},
        {"\u2588", " ", " ", " ", " ", " ", "\u2588"},
        {"\u2588", "\u2588", "\u2588", "\u2588", "\u2588", "\u2588", "\u2588"}
    };

// fill in wq
box wq = {
        {" ", " ", " ", " ", " ", " ", " "},
        {" ", "\u2588", " ", "\u2588", " ", "\u2588", " "},
        {" ", "\u2588", "\u2588", "\u2588", "\u2588", "\u2588", " "},
        {" ", "\u2588", "\u2588", "\u2588", "\u2588", "\u2588", " "},
        {" ", " ", " ", " ", " ", " ", " "}
    };

bool ok(int q[], int c){
    for (int i = 0; i < c; i++) {
        if(q[i] == q[c] || c - i == abs(q[i] - q[c])){
            return false;
        }
    }
    return true;
}

void print(int q[]){
    static int counter = 0;
    counter++;
    cout << "Solution Number: " << counter << endl;
    for(int x = 0; x < 8; x++){
        cout << q[x] << " ";
    }
    cout << endl;

    // fill in board with pointers to bb, wb, bq, and wq in the correct positions
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if((i + j) % 2 == 0){
                if(q[i] == j){
                    board[j][i] = &bq;
                }
                else{
                    board[j][i] = &wb;
                }
            }
            else{
                if(q[i] == j){
                    board[j][i] = &wq;
                }
                else {
                    board[j][i] = &bb;
                }
            }
        }
    }

    // print the board via the pointers in 2D array board
    for(i = 0; i < 8; i++){
        for(k = 0; k < 5; k++){
            for(j = 0; j < 8; j++){
                for(l = 0; l < 7; l++){
                    cout << (*board[i][j])[k][l];
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}

int main(){

    // fill in bb and wb
    for(i = 0; i < 5; i++){
        for(j = 0; j < 7; j++){
            bb[i][j] = " ";
            wb[i][j] = "\u2588";
        }
    }

    int q[8], c = 0;
    q[0] = 0;
    while(c > -1) { // code runs until we cant backtrack anymore
        c++;
        if(c == 8){ // prints the solution if we made it through all 7 columns succesfully, then backtrack
            print(q);
            c--;
        }
        else{ // set row to -1 so goes to 0 when we increase it
            q[c] = -1;
        }
        while(c > -1){
            q[c]++; // next row
            if(q[c] == 8) { // if we run out of rows
                c--; // backtrack
            }
            else if (ok(q, c)) { // if we can put a queen in this spot, break out of the loop and go to the next column
                break;
            }
        }
    }
    return 0;
}