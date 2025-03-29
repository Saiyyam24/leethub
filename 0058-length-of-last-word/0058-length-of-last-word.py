class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s=s.strip()
        new_s = s[::-1]
        count = 0
        i=0
        for i in new_s:
            if(i==" "):
                break;    
            count+=1
            
        return count        