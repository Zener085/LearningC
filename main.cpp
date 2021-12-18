#include <iostream>

/// My algorithm
int centuryFromYear(int year) {
    if (year % 100 != 0)
        return year / 100 + 1;

    return year / 100;
}

/// The best algorithm from answers
int centuryFromYearEdited(int year) {
    return (year + 99) / 100;
}

int main() {
    int a;
    std::cin >> a;
    std::cout << centuryFromYear(a) << centuryFromYearEdited(a) << std::endl;
    return 0;
}
