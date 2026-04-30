class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
        
        s_letter_counter = {}

        for letter in s:
            if letter not in s_letter_counter:
                s_letter_counter[letter] = 1
            else:
                s_letter_counter[letter] += 1
        
        t_letter_counter = {}

        for letter in t:
            if letter not in t_letter_counter:
                t_letter_counter[letter] = 1
            else:
                t_letter_counter[letter] += 1
        
        return s_letter_counter == t_letter_counter        
