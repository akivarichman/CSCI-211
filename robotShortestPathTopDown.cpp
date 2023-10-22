#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 6;

int cost(int i, int j) { // i is the row, j is the column
   int weight[rows][cols] = {
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4},
    };
/*    int weight[rows][cols] = {
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,1,2,3},
    };
*/

    static int memo[rows][cols] = {
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
    };

    // base case
    if(memo[i][j]!=0){
        return memo[i][j];
    }
    if(j==0) {
        memo[i][j] = weight[i][j];
        return weight[i][0];
    }

    // recursive call
    int left = weight[i][j] + cost(i,j-1);
    int up = weight[i][j] + cost((i+(rows-1))%5, j-1);
    int down = weight[i][j] + cost((i+1)%5,j-1);

    // find the value of the shortest path through cell (i,j)
    int min = left;
    if(up < left || down < left) {
        if(up < down) {
            min = up;
        }
        else {
            min = down;
        }
    }

    memo[i][j] = min;

    return min;
}

int main() {

    int ex[rows];
    
    // get the shortest path out of each cell on the right
    for(int i = 0; i < rows; i++) {
        ex[i] = cost(i,cols-1);
    }

    // now find the smallest of them
    int min = ex[0];

    for(int i = 1; i < rows; i++) {
        if(ex[i] < min) {
            min = ex[i];
        }
    }

    cout << "The shortest path is of length " << min << endl;
    
    return 0;
}