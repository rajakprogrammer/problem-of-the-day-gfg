def circularSubarraySum(arr):
    n = len(arr)

    # Helper function to find the maximum subarray sum using Kadane's algorithm
    def kadane(array):
        max_current = max_global = array[0]
        for x in array[1:]:
            max_current = max(x, max_current + x)
            max_global = max(max_global, max_current)
        return max_global

    # Case 1: Maximum sum without circularity (standard Kadane)
    max_kadane = kadane(arr)

    # Case 2: Maximum sum with circularity
    total_sum = sum(arr)
    # Find the minimum subarray sum using Kadane's algorithm on the inverted array
    min_subarray_sum = kadane([-x for x in arr])
    max_wrap = total_sum + min_subarray_sum  # Equivalent to total_sum - (-min_subarray_sum)

    # Special case: If all elements are negative, max_wrap will incorrectly be 0
    if max_wrap == 0:
        return max_kadane

    # Return the maximum of the two cases
    return max(max_kadane, max_wrap)



#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math
import sys

if __name__ == "__main__":
    T = int(input())
    while (T > 0):

        arr = [int(x) for x in input().strip().split()]

        print(circularSubarraySum(arr))

        T -= 1

# } Driver Code Ends