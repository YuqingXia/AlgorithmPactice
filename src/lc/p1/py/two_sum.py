from typing import List
#import pdb

class Solution(object):
    @staticmethod
    def two_sum(l:List[int], target:int) -> List[int]:
        search_state={}
        ret = None

        for i, v in enumerate(l):
            res = target - v
            if v in search_state:
                ret = [search_state[v], i]
                break
            else:
                search_state[res] = i
        
        return ret

    @staticmethod
    def two_sum_1(l:List[int], target:int) -> List[int]:
        l = sorted(enumerate(l), key = lambda x: x[1])
        l_idx = 0
        r_idx = len(l)-1

        while r_idx > l_idx:
            s = l[l_idx][1] + l[r_idx][1]
            if s > target:
                r_idx = r_idx - 1
            elif s < target:
                l_idx = l_idx + 1
            else:
                return [l[l_idx][0], l[r_idx][0]]