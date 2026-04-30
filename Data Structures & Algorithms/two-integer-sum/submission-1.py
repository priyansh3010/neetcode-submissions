class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        tester = {}

        for i, num in enumerate(nums):
            if target - num in tester:
                index = tester[target - num]
                if index < i:
                    return [index, i]
                else:
                    return [i, index]
            else:
                tester[num] = i
