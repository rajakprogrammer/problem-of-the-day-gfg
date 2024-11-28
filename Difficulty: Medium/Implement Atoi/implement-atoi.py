class Solution:
    def myAtoi(self, s: str) -> int:
        # Remove leading whitespaces
        s = s.lstrip()
        
        # Return 0 if the string is empty
        if not s:
            return 0
        
        # Check for optional sign
        sign = 1
        if s[0] in ('-', '+'):
            if s[0] == '-':
                sign = -1
            s = s[1:]
        
        # Read the numerical part
        num = 0
        for char in s:
            if char.isdigit():
                num = num * 10 + int(char)
            else:
                break
        
        # Apply the sign
        num *= sign
        
        # Clamp the result within the 32-bit signed integer range
        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        if num < INT_MIN:
            return INT_MIN
        if num > INT_MAX:
            return INT_MAX
        
        return num

#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = input()
        ob = Solution()
        print(ob.myAtoi(s))
        print("~")

# } Driver Code Ends