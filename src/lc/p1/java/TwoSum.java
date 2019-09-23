import java.util.HashMap;
import java.util.Arrays;
import java.util.Collections;
import java.util.stream.IntStream;
import java.util.Comparator;

public class TwoSum {
    //solution 1
    public static int[] twoSum1(int[] nums, int target){
        HashMap<Integer, Integer>  map = new HashMap<Integer, Integer>();
        int [] ret = new int[2];

        for(int i = 0; i < nums.length; i++){
            int n = nums[i];
            if(map.containsKey(n)){
                //pair find
                ret[0] = map.get(n);
                ret[1] = i;
                break;
            }else{
                map.put(target - n, i);
            }
        }
        
        return ret;
    }

    public static int[] twoSum2(int[] nums, int target){
        Integer[] numsIndex = IntStream.range(0, nums.length).boxed().toArray(Integer[]::new);
        Comparator<Integer> cmp = (i1, i2) -> nums[i1] - nums[i2];
        Arrays.sort(numsIndex, cmp);
        int[] ret = new int[2];
        int l, r; 
        l = 0; 
        r = nums.length - 1; 
        while(l < r){
            int s = nums[numsIndex[l]] + nums[numsIndex[r]];
            if(s > target){
                r--;
            }else if(s < target){
                l++;
            }else{
                ret[0] = numsIndex[l]; 
                ret[1] = numsIndex[r];
                break;
            }
        }
                
        return ret;
    }

    public static void main(String[] args){
        int[] nums = {2, 7, 5, 8};
        int target = 9;
        int[] ret = {0, 1};

        int[] ret1 = twoSum1(nums, target);
        int[] ret2 = twoSum2(nums, target);
       
        System.out.println(Arrays.equals(ret, ret1));
        System.out.println(Arrays.equals(ret, ret2));

    }
}
