#User function Template for python3

class Solution:
    ##Complete this function
    #Function to find the sum of contiguous subarray with maximum sum.
    def maxSubArraySum(self, arr):
        # Initialize variables
        max_so_far = float('-inf')  # Maximum sum found so far
        max_ending_here = 0         # Maximum sum ending at the current position

        for num in arr:
            max_ending_here += num
            
            # Update max_so_far if max_ending_here is greater
            if max_so_far < max_ending_here:
                max_so_far = max_ending_here

            # If max_ending_here drops below zero, reset it to zero
            if max_ending_here < 0:
                max_ending_here = 0

        return max_so_far


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


def main():
    T = int(input())
    while (T > 0):

        arr = [int(x) for x in input().strip().split()]

        ob = Solution()

        print(ob.maxSubArraySum(arr))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends