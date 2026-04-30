class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        anagrams = {}

        for word in strs:
            count = [0] * 26
            for char in word:
                count[ord(char) - ord("a")] += 1
            
            if tuple(count) in anagrams:
                anagrams[tuple(count)].append(word)
            else:
                anagrams[tuple(count)] = [word]
        
        return anagrams.values()
        