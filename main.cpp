#include <iostream>
#include <string>

int getCount(const std::string& inputStr){
    int num_vowels = std::count(inputStr.begin(), inputStr.end(), 'a');
    num_vowels += std::count(inputStr.begin(), inputStr.end(), 'e');
    num_vowels += std::count(inputStr.begin(), inputStr.end(), 'u');
    num_vowels += std::count(inputStr.begin(), inputStr.end(), 'i');
    num_vowels += std::count(inputStr.begin(), inputStr.end(), 'o');
    return num_vowels;
}

int main() {
    std::string f;
    getline(std::cin, f);
    std::cout << getCount(f) << std::endl;
    return 0;
}
