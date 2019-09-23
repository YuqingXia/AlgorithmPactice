import org.junit.Test;
import org.junit.assertEquals;
import org.junit.runner.RunWith;
import org.junit.runner.Suite;
import org.junit.runner.Suite.SuiteClasses;
import org.junit.runner.Result;
import org.junit.runner.JUnitCore;
import org.junit.runner.notification.Failure;

import jdk.internal.jline.internal.TestAccessible;

public class PalindromNumberTests {
    public PalindromNumber solution;

    @BeforeClass
    public void testerCreator(){
        this.solution = new PalindromNumberTests();
    }

    @Test
    public void number121ShouldReturnTrue(){
        Integer x = 121; 
        assertEquals(true, this.solution.isPalindrom(x), "121 should return true");
    }

    @Test
    public void numberNegative121ShouldReturnFalse(){
        Integer x = -121;
        assertEquals(false, this.solution.isPalindrom(x), "-121 should return false");
    }
}

@RunWith(Suite.class)
@SuiteClasses({
    PalindromNumberTests.class
})

public class Test {
    public static void main(String[] args){
        Result result = JunitCore.runClasses(Test.class);
        for(Failure failure : result.getFailures()){
            System.out.println(failure.toString());
        }
    }
}





