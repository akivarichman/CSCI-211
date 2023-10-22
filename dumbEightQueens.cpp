#include <iostream>
using namespace std;

bool ok(int board[]){
    for(int c = 7; c >= 0; c--){
        for(int i = 0; i < c; i++){
            if(board[i] == board[c] || c - i == abs(board[i] - board[c])){
                return false;
            }
        }
    }
    return true;
}

void print(int solution[], int &sol){
    cout << "Solution Number: " << sol++ << endl;
    for(int i = 0; i < 8; i++){
        cout << solution[i] << " ";
    }
    cout << endl << endl;
}

int main(){
    int sol = 1;
    int board[8];
    for(int a = 0; a < 8; a++){
        for(int b = 0; b < 8; b++){
            for(int c = 0; c < 8; c++){
                for(int d = 0; d < 8; d++){
                    for(int e = 0; e < 8; e++){
                        for(int f = 0; f < 8; f++){
                            for(int g = 0; g < 8; g++){
                                for(int h = 0; h < 8; h++){
                                    board[0] = a;
                                    board[1] = b;
                                    board[2] = c;
                                    board[3] = d;
                                    board[4] = e;
                                    board[5] = f;
                                    board[6] = g;
                                    board[7] = h;
                                    if(ok(board)){
                                        print(board, sol);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}