#include <iostream>
#include <string>
#include <fstream>
#include <limits>

/// calculate actual size of array
///@param arr array of numbers, bad array
///@param n size of bad array
///@return size of good array
int actual_size(const int* (arr), const int n) {
    int size = 0; // actual size

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) size++; // increase size till finding first 0 in array
    }

    return size;
}

/// parsing string to create array of numbers
///@param str string with numbers
///@param size (reference) size of string
///@return array of numbers
int* parse_string(const std::string str, int& size) {
    int* long_arr = new int[size]; // temporal array, save only numbers, but with large size, call it bad array
    int sign = 1; // sign of number which is needed to store
    int k = 0; // index in temporal array

    for (int i = 0; i < str.length(); i++) long_arr[i] = 0; // make 0s to all array

    // take symbols one by one and store numbers from the string
    for (char c : str) {
        if (c == '-') sign = -1;
        if ('0' <= c && c <= '9') {
            long_arr[k++] = (c - '0') * sign;
            sign = 1;
        }
    }

    size = actual_size(long_arr, (int) str.length()); // calculate normal size of array
    int* right_arr = new int[size]; // create array with good size, call it good array

    for (int i = 0; i < size; i++) right_arr[i] = long_arr[i]; // copy elements from the bad array to the good array

    return right_arr;
}


/// find maximum sum from numbers array
///@param arr string from input.txt file
///@return maximum sum from array
int max_sum_subarray(const std::string& arr) {
    int sum = INT_MIN, temp_sum = 0; // maximum sum and temporal sum

    int size = arr.length(); // size of array
    int* nums = parse_string(arr, size); // parsed array of numbers

    // find the maximum sum
    for (int i = 0; i < size; i++) {
        temp_sum += nums[i];
        if (sum < temp_sum) sum = temp_sum;
        if (temp_sum < 0) temp_sum = 0;
    }

    return sum;
}

/// read string from input.txt and write maximum sum to the output.txt
void in_out_file() {
    std::ifstream input; // input file
    std::ofstream output; // output file
    std::string numbers; // string of numbers

    input.open("input.txt");
    std::getline(input, numbers); // read string of numbers
    input.close();

    output.open("output.txt");
    output << max_sum_subarray(numbers); // write maximum sum of numbers array
    output.close();
}

int main() {
    in_out_file();

    return 0;
}