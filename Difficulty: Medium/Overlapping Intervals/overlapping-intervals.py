class Solution:
    def mergeOverlap(self, arr):
        # If there are no intervals or just one interval, return it
        if not arr or len(arr) <= 1:
            return arr

        # Sort intervals based on the start time
        arr.sort(key=lambda x: x[0])

        merged = [arr[0]]  # Initialize the merged list with the first interval

        for i in range(1, len(arr)):
            # Check if current interval overlaps with the last interval in merged
            if arr[i][0] <= merged[-1][1]:
                # Merge the intervals by updating the end time
                merged[-1][1] = max(merged[-1][1], arr[i][1])
            else:
                # No overlap, add the interval to the merged list
                merged.append(arr[i])

        return merged


#{ 
 # Driver Code Starts
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        # a = list(map(int, input().strip().split()))
        arr = []
        # j = 0
        for i in range(n):
            a = list(map(int, input().strip().split()))
            x = a[0]
            # j += 1
            y = a[1]
            # j += 1
            arr.append([x, y])
        obj = Solution()
        ans = obj.mergeOverlap(arr)
        for i in ans:
            for j in i:
                print(j, end=" ")
        print()

# } Driver Code Ends