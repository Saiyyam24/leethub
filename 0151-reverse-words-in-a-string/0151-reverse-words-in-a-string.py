class Solution:
    def reverseWords(self, s: str) -> str:
        stack = []

        word = ""
        for i in s:
            if i!=" ":
                word+=i
            elif word:
                stack.append(word)
                word=""    
        if word:
            stack.append(word)
            word = ""
        result = ""
        while stack:
            result += stack.pop() + " "
        return result.strip()    