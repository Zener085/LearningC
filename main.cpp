#include <iostream>

namespace pyramid {
    void draw(const int &height) {
        for (int i = 2; i <= height * 2; i += 2) {
            for (int j = 0; j < (height * 2 - i) / 2; j++)
                cout << " ";
            for (int j = 0; j < i; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }
}

int main() {
    int a;
    std::cin >> a;
    pyramid::draw(a);

    return 0;
}
