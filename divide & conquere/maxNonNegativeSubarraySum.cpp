
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum sum of a non-negative subarray
pair<int, int> maxNonNegativeSubarraySum(int a[], int low, int high) {
    if (low == high) {
        if (a[low] >= 0) {
            return {a[low], a[low]};
        } else {
            return {0, INT_MIN};
        }
    }

    int mid = (low + high) / 2;
    pair<int, int> left = maxNonNegativeSubarraySum(a, low, mid);
    pair<int, int> right = maxNonNegativeSubarraySum(a, mid + 1, high);

    // Handle the case where the maximum subarray spans the midpoint
    int leftSuffixSum = 0, maxLeftSuffixSum = 0;
    for (int i = mid; i >= low && a[i] >= 0; --i) {
        leftSuffixSum += a[i];
        maxLeftSuffixSum = max(maxLeftSuffixSum, leftSuffixSum);
    }

    int rightPrefixSum = 0, maxRightPrefixSum = 0;
    for (int i = mid + 1; i <= high && a[i] >= 0; ++i) {
        rightPrefixSum += a[i];
        maxRightPrefixSum = max(maxRightPrefixSum, rightPrefixSum);
    }

    int crossSum = maxLeftSuffixSum + maxRightPrefixSum;
    int maxSum = max({left.second, right.second, crossSum});

    return {max(0, max(left.first + right.first, max(left.first, right.first))), maxSum};
}

int main() {
    int a[] = {1, 2, -3, 4, 5, 6, -1, 2, 3, -5};
    int n = sizeof(a) / sizeof(a[0]);
    pair<int, int> result = maxNonNegativeSubarraySum(a, 0, n - 1);
    cout << "Maximum sum of non-negative subarray: " << result.second << endl;
}
