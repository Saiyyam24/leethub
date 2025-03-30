class Solution:
    def isPalindrome(self, s: str) -> bool:
        val = ""
        for i in s:
            if 'a'<=i<='z' or 'A'<=i<='Z' or '0'<=i<='9':
                val+=i.lower()

        return val==val[::-1]        
     
        