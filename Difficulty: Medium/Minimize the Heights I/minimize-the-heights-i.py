#User function Template for python3

class Solution:
    def getMinDiff(self,k, arr):
        # code here
    #if the array has only one element , the difference is 0
        if len(arr) == 1:
            return 0
    #sort the array to ensure heights are in increasing order
        arr.sort()
    
    #initialize the differene between the maximum and minimum heights
        n=len(arr)
        initial_diff = arr[-1] - arr[0]
    
    #initialize the minimum and maximum values after adjustments
        smallest = arr[0] + k
        largest = arr[-1] - k
    
    #Ensure smallest and largest values remain within bounds
        if smallest > largest:
            smallest, largest = largest, smallest
    
    #Iterate over the array to find the minimal difference
        for i in range(n-1):
            min_height = min(smallest, arr[i+1] -k)
            max_height = max(largest, arr[i] + k)
            initial_diff =min(initial_diff, max_height - min_height)
        return initial_diff


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        k = int(input())
        arr = list(map(int, input().strip().split()))
        solution = Solution()
        res = solution.getMinDiff(k, arr)
        print(res)
        print("~")

# } Driver Code Ends