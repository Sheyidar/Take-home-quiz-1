#include <iostream>
using namespace std;

// class for holding fractions
class Fraction {
public:
    int n, d;
    Fraction(int a, int b) { n = a; d = b; }
    bool operator==(Fraction &o) { return n == o.n && d == o.d; } // check if two fractions are the same
    string to_string() { return std::to_string(n) + "/" + std::to_string(d); } // turn into a string
};

// get greatest common divisor
int gcd(int a, int b) { while (b) { int t = b; b = a % b; a = t; } return a; }

// reduce the fraction using gcd
Fraction reduce(Fraction f) {
    int g = gcd(f.n, f.d);
    return Fraction(f.n / g, f.d / g);
}

// check if number is power of 2 using a loop
bool is_power_of_two_loop(int x) {
    while (x > 1) {
        if (x % 2) return false;
        x /= 2;
    }
    return x == 1;
}

// check if number is power of 2 using bitwise
bool is_power_of_two_bitwise(int x) {
    return x > 0 && (x & (x - 1)) == 0;
}

// check if number is prime
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i < x; i++) if (x % i == 0) return false;
    return true;
}

// test if reduce works
void test_reduce() {
    Fraction in[] = { {2,4},{6,8},{3,9},{5,10},{10,5} };
    Fraction out[] = { {1,2},{3,4},{1,3},{1,2},{5,1} };
    for (int i = 0; i < 5; i++)
        cout << (reduce(in[i]) == out[i] ? "PASS" : "FAIL") << endl;
}

// test power of two functions
void test_power() {
    int in[] = {2,4,5,16};
    bool out[] = {true,true,false,true};
    for (int i = 0; i < 4; i++)
        cout << ((is_power_of_two_loop(in[i]) == out[i] && is_power_of_two_bitwise(in[i]) == out[i]) ? "PASS" : "FAIL") << endl;
}

// test prime function
void test_prime() {
    int in[] = {2,3,9,11};
    bool out[] = {true,true,false,true};
    for (int i = 0; i < 4; i++)
        cout << (is_prime(in[i]) == out[i] ? "PASS" : "FAIL") << endl;
}

// run all the tests
int main() {
    test_power();
    test_prime();
    test_reduce();
}
