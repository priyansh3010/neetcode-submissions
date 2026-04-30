class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
         
        duplicates = set()

        for num in nums:
            if num not in duplicates:
                duplicates.add(num)
            else:
                return True
        
        return False