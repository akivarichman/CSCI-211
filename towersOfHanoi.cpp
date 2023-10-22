#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> t[3]; // 3 towers A, B, and C represented as an array of 3 vectors
    int n, candidate = 1, to, from = 0, move = 0;
    
    cout << "Please enter an ODD number of rings to move: ";
    cin >> n;
    
    // initialize the 3 towers
    for(int i = n+1; i > 0; i--){
        t[0].push_back(i);
    }
    t[1].push_back(n+1);
    t[2].push_back(n+1);

    if(n % 2 == 1){
        to = 1;
        while(t[1].size() < n+1){ // as long as there are still rings left to transfer to tower B
            cout << "Move number " << ++move << ": Transfer ring " << candidate << " from tower " << char(from+65) << " to tower " << char(to+65) << endl;
            t[to].push_back(t[from].back()); // push the top of the "from" tower onto the "to" tower
            t[from].pop_back(); // remove the top of the "from" tower

            if(t[(to+1)%3].back() < t[(to+2)%3].back()){ // find the next "from" tower
                from = (to+1)%3;
            }
            else{
                from = (to+2)%3;
            }

            candidate = t[from].back(); // set the new candidate

            if(t[(from+1)%3].back() > candidate){ // find the next "to" tower
                to = (from+1)%3;
            }
            else{
                to = (from+2)%3;
            }
        }
    }
    else{
        to = 2;
        while(t[1].size() < n+1){ // as long as there are still rings left to transfer to tower B
            cout << "Move number " << ++move << ": Transfer ring " << candidate << " from tower " << char(from+65) << " to tower " << char(to+65) << endl;

            t[to].push_back(t[from].back()); // push the top of the "from" tower onto the "to" tower
            t[from].pop_back(); // remove the top of the "from" tower

            if(t[(to+1)%3].back() < t[(to+2)%3].back()){ // find the next "from" tower
                from = (to+1)%3;
            }
            else{
                from = (to+2)%3;
            }

            candidate = t[from].back(); // set the new candidate

            if(t[(from+2)%3].back() > candidate){ // find the next "to" tower
                to = (from+2)%3;
            }
            else{
                to = (from+1)%3;
            }
        }
    }

    return 0;
}