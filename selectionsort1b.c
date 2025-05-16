#include <stdio.h>
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
int main() {
    int arr[] = {10, 80, 12, 22, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
//output
// Sorted array: 10 12 22 45 80
