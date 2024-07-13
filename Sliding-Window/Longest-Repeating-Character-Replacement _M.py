# This code is written on 13/07/2024 and commented by Umair

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left = 0
        max_length = 0
        char_frequencies = {}  # Frequencies of the characters appearing
        max_count = 0

        for right in range(len(s)):
            right_char = s[right]
            char_frequencies[right_char] = char_frequencies.get(right_char, 0) + 1
            max_count = max(max_count, char_frequencies[right_char])

            while (right - left + 1) - max_count > k:
                left_char = s[left]
                char_frequencies[left_char] -= 1
                left += 1

            max_length = max(max_length, right - left + 1)

        return max_length

if __name__ == "__main__":
    solution = Solution()  # Create a Solution object
    s = "AABABBA"  # Define the input string
    k = 1  # Define the number of allowed replacements
    result = solution.characterReplacement(s, k)  # Call the characterReplacement method
    print(f"The length of the longest substring after {k} replacements is: {result}")  # Print the result
