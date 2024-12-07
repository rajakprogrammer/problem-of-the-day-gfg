class Solution:
    # User function Template for python3
    # Function to count inversions in the array.
    def inversionCount(self, arr):
        # Helper function for merge sort
        def merge_sort(arr, temp_arr, left, right):
            inv_count = 0
            if left < right:
                mid = (left + right) // 2

                # Count inversions in the left half
                inv_count += merge_sort(arr, temp_arr, left, mid)

                # Count inversions in the right half
                inv_count += merge_sort(arr, temp_arr, mid + 1, right)

                # Count split inversions and merge both halves
                inv_count += merge(arr, temp_arr, left, mid, right)

            return inv_count

        # Helper function to merge two halves and count split inversions
        def merge(arr, temp_arr, left, mid, right):
            i = left    # Starting index for left subarray
            j = mid + 1 # Starting index for right subarray
            k = left    # Starting index for merged subarray
            inv_count = 0

            # Merge two halves while counting inversions
            while i <= mid and j <= right:
                if arr[i] <= arr[j]:
                    temp_arr[k] = arr[i]
                    i += 1
                else:
                    # There are mid - i inversions because all remaining
                    # elements in the left subarray (arr[i..mid]) are greater than arr[j]
                    temp_arr[k] = arr[j]
                    inv_count += (mid - i + 1)
                    j += 1
                k += 1

            # Copy remaining elements of left subarray, if any
            while i <= mid:
                temp_arr[k] = arr[i]
                i += 1
                k += 1

            # Copy remaining elements of right subarray, if any
            while j <= right:
                temp_arr[k] = arr[j]
                j += 1
                k += 1

            # Copy the sorted subarray back to the original array
            for i in range(left, right + 1):
                arr[i] = temp_arr[i]

            return inv_count

        # Initialize temporary array
        temp_arr = [0] * len(arr)

        # Call merge_sort and return the inversion count
        return merge_sort(arr, temp_arr, 0, len(arr) - 1)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        a = list(map(int, input().strip().split()))
        obj = Solution()
        print(obj.inversionCount(a))
        print("~")

# } Driver Code Ends