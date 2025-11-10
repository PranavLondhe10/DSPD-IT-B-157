#include <stdio.h>
int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    int sumOdd = 0, sumEven = 0;
    for(i = 0; i < n; i++) {
        if(i % 2 == 0)
            sumEven += a[i];
        else
            sumOdd += a[i];
    }
    printf("Sum of even position elements: %d\n", sumEven);
    printf("Sum of odd position elements: %d\n", sumOdd);
    return 0;
}