#include <iostream>
using namespace std;

class Rat {
    private:
    int n;
    int d;

    public:
    //constructors

    // default constructor
    Rat() {
        n = 0;
        d = 1;
    }

    // 2 parameter constructor
    Rat(int i, int j) {
        n = i;
        d = j;
    }

    // int conversion construction
    Rat(int i){
        n = i;
        d = 1;
    }

    // accessor functions
    int getN() {return n;}
    int getD() {return d;}
    void setN(int i) {n=i;}
    void setD(int i) {d = i;}

    // arithmetic operations
    Rat operator+(Rat r) {
        Rat t;
        t.n = n*r.d+d*r.n;
        t.d = d*r.d;
        int gcd = findGCD(t.n, t.d);
        t.n = t.n / gcd;
        t.d = t.d / gcd;
        return t;
    }
    Rat operator-(Rat r) {
        Rat t;
        t.n = n*r.d-d*r.n;
        t.d = d*r.d;
        int gcd = findGCD(t.n, t.d);
        t.n = t.n / gcd;
        t.d = t.d / gcd;
        return t;
    }
    Rat operator*(Rat r) {
        Rat t;
        t.n = n*r.n;
        t.d = d*r.d;
        int gcd = findGCD(t.n, t.d);
        t.n = t.n / gcd;
        t.d = t.d / gcd;
        return t;
    }
    Rat operator/(Rat r) {
        Rat t;
        t.n = n*r.d;
        t.d = d*r.n;
        int gcd = findGCD(t.n, t.d);
        t.n = t.n / gcd;
        t.d = t.d / gcd;
        return t;
    }

    int findGCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return findGCD(b, a % b);
   }

    // 2 overloads i/o operators
    friend ostream& operator<<(ostream& os, Rat r);
    friend istream& operator>>(istream& is, Rat& r);
};

    ostream& operator<<(ostream& os, Rat r){
        os << r.n << "/" << r.d << endl;
        return os;
    }
    istream& operator>>(istream& is, Rat& r){
        is >> r.n >> r.d;
        return is;
    }

int main() {
    Rat x(1,2), y(4,5), z, a, b , c;
    z = x + y;
    a = x - y;
    b = x * y;
    c = x / y;
    cout << z << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}