#include <iostream>

int find_max(int arr[], int size) {
    int value = 0;

    for (int i = 0; i < size; i++)
        value = value < arr[i] ? arr[i] : value;

    return value;
}

void counting_sort(int size, int* arr) {
    int value = find_max(arr, size);
    int* count = new int[value];

    for (int i = 0; i < size; i++)
        count[arr[i]]++;

    int act = 0;
    for (int i = 0; i < value; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[act++] = i;
        }
    }
}

int main() {
    int number;
    std::cin >> number;

    int* array = new int[number];

    for (int i = 0; i < number; i++)
        std::cin >> array[i];

    counting_sort(number, array);

    for (int i = 0; i < number; i++)
        std::cout << array[i] << " ";

    return 0;
}
