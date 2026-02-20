/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long prefixSum = 0;
    long long count = 0;

    long long hash[2 * MAX + 1] = {0};

    int offset = MAX;

    hash[offset] = 1;  

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(hash[prefixSum + offset] > 0) {
            count += hash[prefixSum + offset];
        }

        hash[prefixSum + offset]++;
    }

    printf("%lld\n", count);

    return 0;
}
