#{ 
 # Driver Code Starts

# } Driver Code Ends

class Solution:
    def sort012(self, arr):
        # Initialize pointers
        low, mid, high = 0, 0, len(arr) - 1
        
        while mid <= high:
            if arr[mid] == 0:
                # Swap 0 to the low position
                arr[low], arr[mid] = arr[mid], arr[low]
                low += 1
                mid += 1
            elif arr[mid] == 1:
                # Move mid pointer forward
                mid += 1
            else:
                # Swap 2 to the high position
                arr[mid], arr[high] = arr[high], arr[mid]
                high -= 1

        

#{ 
 # Driver Code Starts.
def main():
    t = int(input().strip())  # Read the number of test cases
    ob = Solution()

    while t > 0:
        t -= 1
        arr = list(map(int,
                       input().strip().split())
                   )  # Read the array as space-separated integers
        ob.sort012(arr)  # Sort the array

        print(' '.join(map(str, arr)))  # Print the sorted array
        print("~")
        
if __name__ == "__main__":
    main()

# } Driver Code Ends