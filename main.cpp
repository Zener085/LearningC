#include <iostream>

int basicOp(char op, int val1, int val2) {
    switch (op) {
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        default: return val1 / val2;
    }
}

int main() {
    char c;
    int a, b;
    std::cin >> c >> a >> b;
    std::cout << basicOp(c, a, b) << std::endl;
    return 0;
}
