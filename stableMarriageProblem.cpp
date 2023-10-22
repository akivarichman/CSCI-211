#include<iostream>
using namespace std;

bool ok(int q[], int newman){
    // oldman = old man   q[oldman] = old woman   newman = new man   q[newman] = new woman
    int mp[3][3] = {0,2,1,
                    0,2,1,
                    1,2,0};
    int wp[3][3] = {2,1,0,
                    0,1,2,
                    2,0,1};
    for(int oldman = 0; oldman < newman; oldman++){
        if(q[newman] == q[oldman]){
            return false;
        }
        if(mp[newman][q[oldman]] < mp[newman][q[newman]] && wp[q[oldman]][newman] < wp[q[oldman]][oldman]){
            return false;
        }
        if(mp[oldman][q[newman]] < mp[oldman][q[oldman]] && wp[q[newman]][oldman] < wp[q[newman]][newman]){
            return false;
        }
    }
    return true;
}

void print(int q[]){
    static int counter = 0;
    counter++;
    cout << "Solution #" << counter << ": " << endl;
    cout << q[0] << " " << q[1] << " " << q[2] << endl;
}

int main() {
    int q[3] = {};
    int man = 0;
    q[man] = 0;
    while(man > -1){ // code runs until we can't backtrack anymore
        man++;
        if(man==3){ // prints the solution if we made it past man 2 succesfully being paired, then backtrack
            print(q);
            man--;
        }
        else { // set woman to -1 so goes to 0 when we increase it
            q[man] = -1;
        }
        while(man > -1){ 
            q[man]++; // next woman
            if(q[man]==3){ // if we ran out of women to try for the man
                man--; // backtrack
            }
            else if(ok(q, man)){ // if the pair works, break out of loop and go to next man
                break;
            }
        }
    }
/* Dumb Version
        for(int man0 = 0; man0 < 3; man0++){
            for(int man1 = 0; man1 < 3; man1++){
                for(int man2 = 0; man2 < 3; man2++){
                    q[0] = man0;
                    q[1] = man1;
                    q[2] = man2;
                    if(ok(q, 1)){
                        cout << q[0] << " " << q[1] << " " << q[2] << endl;
                    }
                }
            }
        }
*/
    return 0;
}