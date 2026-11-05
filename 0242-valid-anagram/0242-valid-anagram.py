class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        if len(s) != len(t): 
            return False

        arr = [0] * 26
        
        for i in range(0,len(s)):
            index = ord(s[i]) - ord('a')
            arr[index] += 1
        
        
        for i in range(0,len(s)):
            index = ord(t[i]) - ord('a')
            arr[index] -= 1
        
        for n in arr:
            if n != 0:
                return False
        
        return True