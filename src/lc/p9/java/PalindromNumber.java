public class PalindromNumber {
    public Boolean isPalindrom(int x){
        Boolean ret = false;
        if(x < 0) return false;

        int x_reverse = 0;

        while(x_reverse < x){
            int residual = x % 10;
            x_reverse = x_reverse * 10 + residual;

            if(x_reverse == x){ // for odd number of digits
                ret = true;
                break;
            }

            x = x / 10;

            if (x_reverse == x){ // for even number of digits
                ret = true;
                break;
            }
        }
        
        return ret;
    }
}

