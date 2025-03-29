class Solution:
    def isPalindrome(self, x: int) -> bool:
        n = x
        new_val=0
        if x<0:
            return False
        while(n>0):
            add = n%10
            n = n//10
            new_val = new_val*10 + add
        return new_val==x    