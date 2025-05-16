INSERTION SORT
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

      
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; 
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10], n;
    printf("Enter size of array:");
    scanf("%d", &n);
    
    printf("Enter array elements:");
    for(int i=0;i<n; i++){
    	scanf("%d",&arr[i]);
	}
    printf("Unsorted Array:");
    printArray(arr,n);

    insertionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

/*Output:
Enter size of array:5
Enter array elements:10 40 33 67 7 
Unsorted Array:10 40 33 67 7 
Sorted array: 
7 10 33 40 67 */

