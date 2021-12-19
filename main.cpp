#include <iostream>
#include <string>

///The best solution from CodeWars
int get_sum(int a, int b)
{
    return ((a < b ? b - a : a - b) + 1) *(a + b)/ 2;
}

/// My solution
int own_get_sum(int a, int b)
{
    int sum = 0;
    for (int i = std::min(a, b); i <= std::max(a, b); i++)
        sum += i;
    return sum;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << get_sum(a, b) << std::endl;
    return 0;
}
