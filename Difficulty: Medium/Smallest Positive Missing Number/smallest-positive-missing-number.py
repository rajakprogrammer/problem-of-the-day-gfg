class Solution:
    
    # Function to find the smallest positive number missing from the array.
    def missingNumber(self, arr):
        n = len(arr)
        
        # Step 1: Segregate positive numbers from non-positive numbers
        # Place each positive number within the range [1, N] at its correct index
        for i in range(n):
            while 1 <= arr[i] <= n and arr[i] != arr[arr[i] - 1]:
                arr[arr[i] - 1], arr[i] = arr[i], arr[arr[i] - 1]
        
        # Step 2: Identify the first missing positive number
        for i in range(n):
            if arr[i] != i + 1:
                return i + 1
        
        # If all numbers from 1 to N are present, return N+1
        return n + 1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


def main():
    T = int(input())
    while (T > 0):
        arr = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.missingNumber(arr))
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends