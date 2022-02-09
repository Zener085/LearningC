#include <iostream>

#define ll long long

namespace fibonacci {
//    ll easy_find(const ll& number) {
//        if (number <= 1) return number;
//        return easy_find(number - 1) + easy_find(number - 2);
//    }

    ll numbers[100000] = {0};

    ll find(const ll& number) {
        if (number == 0)
            return 0;
        if (number == 1 || number == 2)
            return (numbers[number] = 1);

        if (numbers[number])
            return numbers[number];

        ll k = (number & 1)? (number + 1) / 2 : number / 2;

        numbers[number] = (number & 1)
                        ? (find(k)*find(k) + find(k-1)*find(k-1))
                        : (2*find(k-1) + find(k))*find(k);

        return numbers[number];
    }
}

int main() {
    ll a;
    std::cin >> a;
    std::cout << fibonacci::find(a);
    return 0;
}
