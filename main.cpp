#include <iostream>
#include <vector>
/*
std::vector<int> quick_sort(std::vector<int> arr) {
    if (arr.size() <= 1) return arr;

    if (arr.size() == 2) {
        if (arr[0] > arr[1]) {
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
        return arr;
    }

    std::vector<int> smaller(0);
    std::vector<int> bigger(0);
    std::vector<int> middle(0);
    middle.push_back(arr.back()); arr.pop_back();

    for (int a : arr) {
        if (middle[0] > a) smaller.push_back(a);
        else if (middle[0] < a) bigger.push_back(a);
        else middle.push_back(a);
    }

    smaller = quick_sort(smaller);
    bigger = quick_sort(bigger);

    int k = 0;
    for (int small : smaller)
        arr[k++] = small;

    for (int mid : middle)
        arr[k++] = mid;

    for (int big : bigger)
        arr[k++] = big;

    return arr;
}
*/

int find_max(std::vector<int> &arr) {
    int num = INT_MIN;
    for (int a : arr)
        if (num < a) num = a;

    return num;
}

void countSort(std::vector<int> &arr) {
    int max_value = find_max(arr);
    std::vector<int> values(max_value);

    for (int i = 0; i < max_value; i++)
        values[i] = 0;

    for (int num : arr)
        values[num-1]++;

    for (int i = 1; i < values.size(); i++)
        values[i] += values[i-1];

    std::vector<int> temp_arr(arr.size());

    for (int i : arr) {
        temp_arr[values[i-1]-- - 1] = i;
    }

    arr = temp_arr;
}



int main() {
/*
    int size, num;
    std::cin >> size;
    std::vector<int> arr(0);
    for (int i = 0; i < size; i++) {
        std::cin >> num;
        arr.push_back(num);
    }

    arr = quick_sort(arr);

    for (int a : arr)
        std::cout << a << " ";
*/

    int n, min_bid, max_bid;
    std::cin >> n;
    std::vector<int, int> bids;

    for (int i = 0; i < n; i++) {
        std::cin >> min_bid >> max_bid;
        bids.
    }

    return 0;
}
