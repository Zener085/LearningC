#include <iostream>
#include <string>

std::string get_middle(const std::string& str) {
    if ((str.length() % 2) == 0)
        return str.substr(str.length() / 2 - 1, 2);

    else
        return str.substr(str.length() / 2, 1);
}

int main() {
    std::string f;
    getline(std::cin, f);
    std::cout << get_middle(f) << std::endl;
    return 0;
}
