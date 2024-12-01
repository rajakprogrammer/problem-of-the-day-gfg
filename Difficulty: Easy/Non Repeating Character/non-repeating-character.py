# User function Template for python3

class Solution:
    
    # Function to find the first non-repeating character in a string.
    def nonRepeatingChar(self, s):
        # Step 1: Create a dictionary to store the frequency of each character
        char_count = {}
        
        # Step 2: Count the frequency of each character
        for char in s:
            char_count[char] = char_count.get(char, 0) + 1
        
        # Step 3: Iterate through the string to find the first character with frequency 1
        for char in s:
            if char_count[char] == 1:
                return char
        
        # If no non-repeating character is found, return -1
        return -1



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
    for i in range(t):
        s = str(input())
        obj = Solution()
        ans = obj.nonRepeatingChar(s)
        if (ans != '$'):
            print(ans)
        else:
            print(-1)

        print("~")

# } Driver Code Ends