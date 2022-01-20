#include <iostream>

void selection_sort(int a[], int n){
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;

        std::swap(a[min_idx], a[i]);
    }
}

int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    selection_sort(arr, n);
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    return 0;
}
