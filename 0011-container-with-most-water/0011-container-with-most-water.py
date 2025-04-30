class Solution:
    def maxArea(self, height: List[int]) -> int:
        l=0
        r=len(height)-1
        max_result=0
        while l<r:
            minimum=min(height[l],height[r])
            possible_max=minimum*(r-l)
            max_result=max(max_result,possible_max)

            if height[l]<height[r]:
                l+=1
            else:
                r-=1
        return max_result

        