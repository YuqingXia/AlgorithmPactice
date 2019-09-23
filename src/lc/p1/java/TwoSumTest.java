import org.junit.runner.JunitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;


public class TwoSumTest{
    @BeforeClass
    public void twoSumTestSetupClass(){
        this.solution = TwoSum();
    }

    @Test
    public void twoSumTestCase1(){
        int[] nums = {2, 7, 11, 15};
        int target = 9; 
        int[] ret = {0, 1};
        assertEqual(ret, this.solution.twosum1(nums, target));
        assertEqual(ret, this.solution.twosum2(nums, target));
    }

    public static void main(String[] args){
        Result result = JunitCore.runClasses(TwoSumTest.class);
        for(Failure failure : result.getFailures()){
            System.out.println(failure.toString());
        }
    }
}