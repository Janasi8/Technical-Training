#include <stdio.h>

void findTwoNonRepeating(int arr[], int n) {
    int xor_result = 0;
    
    // Step 1: XOR all elements in the array
    for (int i = 0; i < n; i++) {
        xor_result ^= arr[i];
    }

    // Step 2: Find the rightmost set bit in xor_result
    int rightmost_set_bit = xor_result & -xor_result;

    // Step 3: Divide elements into two groups and XOR them separately
    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] & rightmost_set_bit) {
            num1 ^= arr[i];  // Elements with the set bit
        } else {
            num2 ^= arr[i];  // Elements without the set bit
        }
    }

    // Step 4: Print the two non-repeating elements
    printf("The two non-repeating elements are: %d and %d\n", num1, num2);
}

int main() {
    int arr[] = {2, 4, 7, 9, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    findTwoNonRepeating(arr, n);

    return 0;
}
