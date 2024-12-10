#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    def minRemoval(self, intervals):
        # Sort intervals by their end time
        intervals.sort(key=lambda x: x[1])
        
        # Initialize variables
        prev_end = float('-inf')  # End time of the last included interval
        removals = 0  # Count of intervals to remove
        
        # Iterate through sorted intervals
        for start, end in intervals:
            if start >= prev_end:
                # No overlap, include this interval
                prev_end = end
            else:
                # Overlap detected, remove the current interval
                removals += 1
        
        return removals



#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N = int(input())
        intervals = [list(map(int, input().split())) for i in range(N)]
        ob = Solution()
        res = ob.minRemoval(intervals)
        print(res)
        print("~")
# } Driver Code Ends