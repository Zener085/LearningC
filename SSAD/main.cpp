#include <iostream>
#include <string>
#include <vector>

int actual_size(const int* (arr), const int n) {
    int size = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) size++;
    }

    return size;
}

int* parse_string(const std::string str, int& size) {
    int* long_arr = new int[size];
    int sign = 1;
    int k = 0;

    for (int i = 0; i < str.length(); i++) long_arr[i] = 0;

    for (char c : str) {
        if (c == '-') sign = -1;
        if ('0' <= c && c <= '9') {
            long_arr[k++] = (c - '0') * sign;
            sign = 1;
        }
    }

    size = actual_size(long_arr, (int) str.length());
    int* right_arr = new int[size];

    for (int i = 0; i < size; i++) right_arr[i] = long_arr[i];

    return right_arr;
}


int max_sum_subarray(const std::string arr) {
    int sum = 0;
    int* nums = parse_string(arr, sum);

//    code here

    return sum;
}

int main() {
    std::string arr;
    int size;
    int* test;

    std::getline(std::cin, arr);

    size = arr.length();
    test = parse_string(arr, size);

    for (int i = 0; i < size; i++) {
        std::cout << test[i] << " ";
    }

//    std::cout << max_sum_subarray(arr) << std::endl;

    return 0;
}
