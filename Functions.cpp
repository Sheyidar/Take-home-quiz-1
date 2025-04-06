#include <iostream>

// 1. Check if number is power of two (loop method)
bool is_power_of_two_loop(int n) {
    if (n < 1) return false;
    while (n > 1) {
        if (n % 2 != 0) return false;
        n /= 2;
    }
    return true;
}

// 1. Check if number is power of two (non-loop method using bitwise)
bool is_power_of_two_bitwise(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// 2. Check if number is prime
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// 3. Reduce fraction
class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    std::string to_string() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    bool operator==(const Fraction &other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }
};

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

Fraction reduce(Fraction input) {
    int divisor = gcd(input.numerator, input.denominator);
    input.numerator /= divisor;
    input.denominator /= divisor;
    return input;
}

// Test functions
void test_is_power_of_two() {
    int test_values[] = {1, 2, 4, 8, 16, 3, 5, 10, 0, -2};
    bool expected[]    = {true, true, true, true, true, false, false, false, false, false};

    for (int i = 0; i < 10; ++i) {
        if (is_power_of_two_loop(test_values[i]) == expected[i] &&
            is_power_of_two_bitwise(test_values[i]) == expected[i]) {
            std::cout << "PASS" << std::endl;
        } else {
            std::cout << "FAIL" << std::endl;
        }
    }
}

void test_is_prime() {
    int test_values[] = {2, 3, 4, 5, 7, 9, 11, 13, 1, 0, -5};
    bool expected[]   = {true, true, false, true, true, false, true, true, false, false, false};

    for (int i = 0; i < 11; ++i) {
        if (is_prime(test_values[i]) == expected[i]) {
            std::cout << "PASS" << std::endl;
        } else {
            std::cout << "FAIL" << std::endl;
        }
    }
}

void test_reduce_fraction() {
    Fraction inputs[] = {
        Fraction(2, 4),
        Fraction(2, 3),
        Fraction(3, 2),
        Fraction(12, 14),
        Fraction(12, 18)
    };

    Fraction expected[] = {
        Fraction(1, 2),
        Fraction(2, 3),
        Fraction(3, 2),
        Fraction(6, 7),
        Fraction(2, 3)
    };

    for (int i = 0; i < 5; ++i) {
        Fraction reduced = reduce(inputs[i]);
        if (reduced == expected[i]) {
            std::cout << "PASS" << std::endl;
        } else {
            std::cout << "FAIL" << std::endl;
        }
    }
}

int main() {
    test_is_power_of_two();
    test_is_prime();
    test_reduce_fraction();
}

