# User function Template for python3

class Solution:
    def search(self, pat, txt):
        # Function to create the LPS array
        def computeLPSArray(pattern):
            m = len(pattern)
            lps = [0] * m
            length = 0  # Length of the previous longest prefix suffix
            i = 1  # Start from the second character

            while i < m:
                if pattern[i] == pattern[length]:
                    length += 1
                    lps[i] = length
                    i += 1
                else:
                    if length != 0:
                        length = lps[length - 1]
                    else:
                        lps[i] = 0
                        i += 1
            return lps

        # Lengths of the pattern and text
        m = len(pat)
        n = len(txt)

        # Compute the LPS array for the pattern
        lps = computeLPSArray(pat)

        # List to store starting indices of pattern matches in the text
        result = []

        i = 0  # Index for txt[]
        j = 0  # Index for pat[]

        while i < n:
            if pat[j] == txt[i]:
                i += 1
                j += 1

            if j == m:
                result.append(i - j)  # Match found, add index to result
                j = lps[j - 1]
            elif i < n and pat[j] != txt[i]:
                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1

        return result



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        patt = input().strip()
        ob = Solution()
        ans = ob.search(patt, s)
        if len(ans) == 0:
            print("[]", end="")
        for value in ans:
            print(value, end=' ')
        print()

# } Driver Code Ends