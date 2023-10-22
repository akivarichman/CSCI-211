#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 6;

int main() {


    int prob[rows][cols] = {
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4},
    };
/*
    int prob[rows][cols] = {
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,1,2,3},
    };
*/
    int a[rows][cols];

    // get the shortest path out of each cell on the left
    for(int i = 0; i < rows; i++) {
        a[i][0] = prob[i][0];
    }
    for(int j = 1; j < cols; j++) {
        for(int i = 0; i < rows; i++) {
            // function that finds smallest of 3 options and returns it
            int opt1 = prob[i][j] + a[i][j-1];
            int opt2 = prob[i][j] + a[(i+(rows-1))%5][j-1];
            int opt3 = prob[i][j] + a[(i+1)%5][j-1];

            int min = opt1;
            if(opt2 < opt1 || opt3 < opt1) {
                if(opt2 < opt3) {
                    min = opt2;
                }
                else {
                    min = opt3;
                }
            }
            a[i][j] = min;
        }
    }

    /* print a
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    */

    // now find the smallest of them
    int min = a[0][cols-1];

    for(int i = 1; i < rows; i++) {
        if(a[i][cols-1] < min) {
            min = a[i][cols-1];
        }
    }

    // print answer
    cout << "The shortest path is of length " << min << endl;
    
    return 0;
}