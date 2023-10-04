#include <iostream>

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}

int main() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    std::cout << "GCD of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << std::endl;
    std::cout << "LCM of " << num1 << " and " << num2 << " is " << lcm(num1, num2) << std::endl;

    return 0;
}
