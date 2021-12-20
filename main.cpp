#include <iostream>
#include <vector>

/// The best solution from CodeWars
std::vector<int> maps(const std::vector<int> & values) {
    std::vector<int> result;
    for(int a:values)
        result.push_back(a*2);

    return result;
}

int main() {
    std::vector<int> numbers;
    int c;
    do {
        std::cin >> c;
        numbers.push_back(c);
    } while (c != 0);
    std::cout << maps(numbers)[0] << std::endl;
    return 0;
}
