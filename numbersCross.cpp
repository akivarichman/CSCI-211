#include <iostream>
using namespace std;

int main() {
    int cross[8] = {0};
    int helper[8][5] = { {-1}, {0, -1}, {0, -1}, {0, 1, 2, -1}, {0, 1, 3, -1}, {1, 4, -1}, {2, 3, 4, -1}, {3, 4, 5, 6, -1} };
    
    int index = -1;
    int num = 0;
    int counter = 1;

nextindex:
    index++;
    if(index == 8) {
        goto print;
    }
nextnum:
    if(num == 8){
        goto backtrack;
    }
    num++;

    // OK function
    for(int c = 0; c < index; c++){ // check to make sure this number isn't already placed somewhere
        if(cross[c] == num){
            goto nextnum;
        }
    }
    for(int c = 0; c < 5; c++){
        if(helper[index][c] == -1){ // see if there is another index adjacent to check
            break;
        }
        if(abs(cross[helper[index][c]] - num) == 1){ // check to see if the number can be placed
            goto nextnum;
        }
    }

    // placement
    // reset for next index
    cross[index] = num;
    num = 0;
    goto nextindex;

backtrack:
    index--;
    if(index == -1){
        return 0;
    }
    num = cross[index];
    goto nextnum;

print:
    cout << "Solution Number: " << counter << endl;
    for(int c = 0; c < 8; c++){
        cout << cross[c] << " ";
    }
    cout << endl;
    counter++;
    goto backtrack;

    return 0;
}