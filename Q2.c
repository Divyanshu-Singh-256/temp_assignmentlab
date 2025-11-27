//WAP to merge 2 unsorted arrays into a single sorted array without using duplicates
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to merge two arrays into a third, remove duplicates, and sort
void mergeRemoveSort(int arr1[], int size1, int arr2[], int size2, int result[], int *resultSize) {
    int count = 0;

    // Add elements from first array (skip duplicates in result)
    for (int i = 0; i < size1; i++) {
        int found = 0;
        for (int k = 0; k < count; k++) {
            if (result[k] == arr1[i]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            result[count] = arr1[i];
            count++;
        }
    }

    // Add elements from second array (skip duplicates in result)
    for (int i = 0; i < size2; i++) {
        int found = 0;
        for (int k = 0; k < count; k++) {
            if (result[k] == arr2[i]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            result[count] = arr2[i];
            count++;
        }
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (result[i] > result[j]) {
                int tmp = result[i];
                result[i] = result[j];
                result[j] = tmp;
            }
        }
    }

    *resultSize = count;
}

int main() {
    int size1, size2;

    printf("Enter size of first array: ");
    scanf("%d", &size1);
    int arr1[size1];
    printf("Enter elements of first array:\n");
    for (int i = 0; i < size1; i++){
         scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &size2);
    int arr2[size2];
    printf("Enter elements of second array:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    int result[size1 + size2];
    int resultSize = 0;

    mergeRemoveSort(arr1, size1, arr2, size2, result, &resultSize);

    printf("Final sorted array without duplicates:\n");
    for (int i = 0; i < resultSize; i++){
         printf("%d \n", result[i]);
    }
    return 0;
}
