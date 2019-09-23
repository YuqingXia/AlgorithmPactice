class IsPalindrom:
    def isPalindrom(self, x:int) -> bool:
        ret = False
        if x < 0:
            return False

        x_reverse = 0

        while(x_reverse < x):
            residual = x % 10
            x_reverse = x_reverse * 10 + residual
            if x_reverse == x : # for odd number of digits
                ret = True
                break
            x = int(x/10)
            if x_reverse == x: # for even number of digits
                ret = True
                break
        return ret

