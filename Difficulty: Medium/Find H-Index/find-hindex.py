class Solution:
    # Function to find hIndex
    def hIndex(self, citations):
        # Sort citations in descending order
        citations.sort(reverse=True)
        
        # Iterate through the sorted list to find the h-index
        h_index = 0
        for i, citation in enumerate(citations):
            # Check if the current citation is greater than or equal to (i+1)
            if citation >= i + 1:
                h_index = i + 1
            else:
                break
        
        return h_index

#{ 
 # Driver Code Starts
# Initial Template for Python 3

# Main
if __name__ == '__main__':
    t = int(input())
    while t > 0:
        t -= 1
        arr = [int(x) for x in input().strip().split()]

        ob = Solution()
        result = ob.hIndex(arr)

        print(result)
        print("~")

# } Driver Code Ends