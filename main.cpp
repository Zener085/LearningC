#include <iostream>

#define ll long long

namespace fibonacci {
    ll easy_find(const ll& number) {
        if (number <= 1) return number;
        return easy_find(number - 1) + easy_find(number - 2);
    }

//    ll* numbers;
//
//    ll find(const ll& number) {
//        if (numbers[number] > 0) return numbers[number];
//        ll answer = find(number - 1) + find(number - 2);
//        numbers[number] = answer;
//        return answer;
//    }
//
//    ll find_number(const ll& number) {
//        numbers = new ll[number];
//        numbers[0] = numbers[1] = 1;
//        for (int i = 2; i < number; i++)
//            numbers[i] = 0;
//        return find(number);
//    }
}

int main() {
    ll a;
    std::cin >> a;
    std::cout << fibonacci::easy_find(a);
    return 0;
}
