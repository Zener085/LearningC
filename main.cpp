#include <iostream>

void insertion_sort(int* a, int n){
    int key, j, i;
    for (i = 1; i < n; i++){
        key = a[i];
        j = i - 1;
        while (j >= 0 and a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}
