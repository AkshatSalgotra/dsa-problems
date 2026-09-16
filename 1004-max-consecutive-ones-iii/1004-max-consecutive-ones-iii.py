class Solution:
    def longestOnes(self, arr: list[int], k: int) -> int:
        n = len(arr)
        zeroCnt = maxCnt = 0
        l = 0
        r = 0
        
        while r < n:
            if arr[r] == 0:
                zeroCnt += 1
                
            while zeroCnt > k:
                if arr[l] == 0:
                    zeroCnt -= 1
                l += 1
            
            maxCnt = max(maxCnt, r-l+1)
            r+=1
        
        return maxCnt