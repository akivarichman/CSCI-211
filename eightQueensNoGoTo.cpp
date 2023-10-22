#include <iostream>
using namespace std;

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
    for(int i = 0; i < 8; i++){
        cout << q[i] << " ";
    }
    cout << endl << endl;
}

int main() {

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