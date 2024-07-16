
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        left = 0
        hashMap = {}

        # Calculate character frequencies in s1
        for s in s1:
            hashMap[s] = hashMap.get(s, 0) + 1
        # For loop ends here

        char_frequency = {}

        # New for loop starting here
        for right in range(len(s2)):
            if s2[right] in hashMap:
                char_frequency[s2[right]] = char_frequency.get(s2[right], 0) + 1

                while char_frequency[s2[right]] > hashMap[s2[right]]:
                    char_frequency[s2[left]] -= 1
                    if char_frequency[s2[left]] == 0:
                        del char_frequency[s2[left]]
                    left += 1

                if (right - left + 1) == len(s1):
                    print("exiting when right :",right," left : ",left)
                    return True

            else:
                left = right + 1
                char_frequency.clear()
        return False

def main():
    solution = Solution()

    # Test cases
    s1 = "ab"
    s2 = "eidbaooo"
    print(f"checkInclusion('{s1}', '{s2}') = {solution.checkInclusion(s1, s2)}")  # Expected output: True

    s1 = "abc"
    s2 = "ccccbbbbaaaa"
    print(f"checkInclusion('{s1}', '{s2}') = {solution.checkInclusion(s1, s2)}")  # Expected output: False

    s1 = "adc"
    s2 = "dcda"
    print(f"checkInclusion('{s1}', '{s2}') = {solution.checkInclusion(s1, s2)}")  # Expected output: True

    s1 = "hello"
    s2 = "ooolleoooleh"
    print(f"checkInclusion('{s1}', '{s2}') = {solution.checkInclusion(s1, s2)}")  # Expected output: False

    s1 = "a"
    s2 = "ab"
    print(f"checkInclusion('{s1}', '{s2}') = {solution.checkInclusion(s1, s2)}")  # Expected output: True

    s1 = "abcd"
    s2 = "dcba"
    print(f"checkInclusion('{s1}', '{s2}') = {solution.checkInclusion(s1, s2)}")  # Expected output: True

    s1 = "abcd"
    s2 = "efghijklmnop"
    print(f"checkInclusion('{s1}', '{s2}') = {solution.checkInclusion(s1, s2)}")  # Expected output: False

    s1 = "abc"
    s2 = "cbaebabacd"
    print(f"checkInclusion('{s1}', '{s2}') = {solution.checkInclusion(s1, s2)}")  # Expected output: True

    s1 = "xyz"
    s2 = "zxyyzyx"
    print(f"checkInclusion('{s1}', '{s2}') = {solution.checkInclusion(s1, s2)}")  # Expected output: True

    s1 = "a"
    s2 = "a"
    print(f"checkInclusion('{s1}', '{s2}') = {solution.checkInclusion(s1, s2)}")  # Expected output: True

if __name__ == "__main__":
    main()
