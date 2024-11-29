# User function Template for python3
class Solution:
    def addBinary(self, s1, s2):
        # Initialize pointers and carry
        i, j, carry = len(s1) - 1, len(s2) - 1, 0
        result = []
        
        # Perform binary addition
        while i >= 0 or j >= 0 or carry:
            bit1 = int(s1[i]) if i >= 0 else 0
            bit2 = int(s2[j]) if j >= 0 else 0
            
            # Sum bits and carry
            total = bit1 + bit2 + carry
            carry = total // 2
            result.append(str(total % 2))
            
            i -= 1
            j -= 1
        
        # Remove leading zeros from the result
        final_result = ''.join(reversed(result)).lstrip('0')
        
        # If the result is an empty string, it means the sum is 0
        return final_result if final_result else "0"

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        a = input().strip()
        b = input().strip()
        ob = Solution()
        answer = ob.addBinary(a, b)

        print(answer)
        print("~")

# } Driver Code Ends