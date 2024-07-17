import sys
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(t)>len(s):
            return ""
        hashMap1={}
        for char in t:
            hashMap1[char]=hashMap1.get(char,0)+1

        actual_L=0
        actual_R=0
        window_size=sys.maxsize
        count=0      # have
        left=0
        need=len(t)
        char_frequency={}
        for right in range(len(s)):
            if s[right] in hashMap1:
                char_frequency[s[right]]=char_frequency.get(s[right],0)+1
                if char_frequency[s[right]]<=hashMap1[s[right]]:
                    count+=1
                while count==need:
                    if right-left+1<window_size:
                        actual_L=left
                        actual_R=right
                        window_size=right-left+1
                    if count==need:
                        char_frequency[s[left]]=char_frequency.get(s[left],0)-1
                    if s[left] in hashMap1 and  char_frequency[s[left]]<hashMap1[s[left]]:
                        count-=1
                    left+=1
            else:
                pass
        return s[actual_L:actual_R+1] if window_size!=sys.maxsize else ""



def main():
    s = "ADOBECODEBANC"
    t = "ABC"
    solution = Solution()
    result = solution.minWindow(s, t)
    print("The minimum window substring is:", result)

if __name__ == "__main__":
    main()
