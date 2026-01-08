class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}

        for i in range(0,len(nums)):
            diff = target-nums[i]
            if diff in dic:
                return [i,dic[diff]]

            dic[nums[i]] = i


        