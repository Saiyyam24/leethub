class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        vector = []
        n = len(spells)
        m = len(potions)
        potions.sort()
        for i in range(0,n,1):
            start = 0
            end = m-1
            index = m
            while start<=end:
                mid = (start+end)//2
                if spells[i]*potions[mid]>=success:
                    index = mid
                    end = mid-1
                else:
                    start = mid+1
            vector.append(m-index)    
        return vector