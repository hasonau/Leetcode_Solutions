class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # If t is longer than s, it's impossible to find a valid window
        if len(t) > len(s):
            return ""

        # Create a frequency map for characters in t
        hashMap1 = {}
        for char in t:
            hashMap1[char] = hashMap1.get(char, 0) + 1

        # Initialize variables to keep track of the minimum window
        result_pointers = [-1, -1]
        window_size = float("infinity")
        count = 0      # Number of valid characters matched
        left = 0
        need = len(t)  # Total characters to match

        # Frequency map for characters in the current window
        char_frequency = {}

        # Traverse through string s with the right pointer
        for right in range(len(s)):
            if s[right] in hashMap1:
                # Update the frequency map for the current character
                char_frequency[s[right]] = char_frequency.get(s[right], 0) + 1

                # Increase count if the character frequency does not exceed its requirement
                if char_frequency[s[right]] <= hashMap1[s[right]]:
                    count += 1

                # If all characters are matched, try to shrink the window from the left
                while count == need:
                    # Update the minimum window size and boundaries
                    if right - left + 1 < window_size:
                        result_pointers = [left, right]
                        window_size = right - left + 1

                    # Remove the character at the left pointer from the frequency map
                    if count == need:
                        char_frequency[s[left]] = char_frequency.get(s[left], 0) - 1

                    # Decrease count if the character frequency falls below its requirement
                    if s[left] in hashMap1 and char_frequency[s[left]] < hashMap1[s[left]]:
                        count -= 1

                    # Move the left pointer to the right to shrink the window
                    left += 1

            else:
                pass

        # Extract the final result window using the pointers
        l, r = result_pointers
        return s[l:r + 1] if window_size != float("infinity") else ""

# Main function to test the code
def main():
    s = "ADOBECODEBANC"
    t = "ABC"
    solution = Solution()
    result = solution.minWindow(s, t)
    print("The minimum window substring is:", result)

if __name__ == "__main__":
    main()
