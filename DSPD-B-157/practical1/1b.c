#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    if(arr == NULL || n == 0)
        return -1;
    int start = 0, end = n - 1;
    while(start <= end) {
        int mid = (start + end) / 2;
        printf("Checking element at index %d: %d\n", mid, arr[mid]);
        if(arr[mid] == key)
            return mid;
        else if(key > arr[mid]) {
            start = mid + 1;
            printf("Key is greater, moving start to index %d\n", start);
        } else {
            end = mid - 1;
            printf("Key is smaller, moving end to index %d\n", end);
        }
    }
    return -1;
}

int main() {
    int n, key, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements in sorted order:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    int pos = binarySearch(a, n, key);
    if(pos == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", pos);
    return 0;
}