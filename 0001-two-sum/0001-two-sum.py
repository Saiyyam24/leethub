class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        dict = {}

        for i in range(0,n):
            diff = target - nums[i]

            if diff in dict:
                return [i,dict[diff]]
            dict[nums[i]] = i
            