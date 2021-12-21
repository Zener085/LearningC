#include <iostream>
#include <vector>

/// My own solution from CodeWars
void maps(std::vector<int> & values) {
    for (int & value : values)
        value = value * 2;
}

int main() {
    std::vector<int> numbers;
    int c;

    do {
        std::cin >> c;
        numbers.push_back(c);
    } while (c != 0);

    maps(numbers);

    for (int number : numbers)
        std::cout << number << " ";
    return 0;
}
