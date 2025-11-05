class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        top = SortedList() 
        remain = SortedList() 
        freq = defaultdict(int)
        cur_sum = 0

        def balance():
            nonlocal cur_sum
            if len(top) < x and remain:
                f, n = remain.pop()
                top.add((f, n))
                cur_sum += f * n
            
            if top and remain and top[0] < remain[-1]:
                f1, n1 = top.pop(0)
                f2, n2 = remain.pop()
                top.add((f2, n2))
                remain.add((f1, n1))
                cur_sum += (f2*n2 - f1*n1)

        def update(num, delta):
            nonlocal cur_sum

            if num in freq:
                if (freq[num], num) in top:
                    top.remove((freq[num], num))
                    cur_sum -= freq[num] * num
                else:
                    remain.remove((freq[num], num))

            freq[num] += delta
            if freq[num] == 0:
                del freq[num]
            else:
                remain.add((freq[num], num))
            balance()

        res = [] 
        for i in range(k):
            update(nums[i], 1)
        
        res.append(cur_sum)
        for i in range(k, len(nums)):
            update(nums[i - k], -1)
            update(nums[i], 1)
            res.append(cur_sum)
        return res