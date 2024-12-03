class Solution:
    def minChar(self, s):
        # Create the concatenated string with a delimiter
        temp = s + '#' + s[::-1]
        
        # Compute the LPS array for the concatenated string
        n = len(temp)
        lps = [0] * n
        for i in range(1, n):
            j = lps[i - 1]
            while j > 0 and temp[i] != temp[j]:
                j = lps[j - 1]
            if temp[i] == temp[j]:
                j += 1
            lps[i] = j
        
        # Minimum characters to add = length of s - length of the palindrome suffix
        return len(s) - lps[-1]

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        s = input()
        obj = Solution()
        ans = obj.minChar(s)
        print(ans)
        print("~")

# } Driver Code Ends