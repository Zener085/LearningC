#include <iostream>
#include <vector>
#include <string>

/// Best solution from CodeWars
std::string likes(const std::vector<std::string> &names){
    switch(names.size()){
        case 0: return "no one likes this";
        case 1: return names[0] + " likes this";
        case 2: return names[0] + " and " + names[1] + " like this";
        case 3: return names[0] + ", " + names[1] + " and " + names[2] + " like this";
        default: return names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> names;
    for (int i = 0; i < n; i++){
        std::string a;
        std::cin >> a;
        names.push_back(a);
    }
    std::cout << likes(names) << std::endl;
    return 0;
}
