#include <iostream>
#include <string>

/// The best solution from CodeWars
int string_to_number(const std::string& s) {
    return std::stoi(s);
}

/// My solution
int own_string_to_number(const std::string& s) {
    return std::atoi(s.c_str());
}

int main() {
    std::string a;
    std::cin >> a;
    std::cout << string_to_number(a) << std::endl;
    return 0;
}
