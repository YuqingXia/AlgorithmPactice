### Two Sum 
find the two number so there sum is equal to given number S. 

#### Algorithm 1
Use sorted array to move forward to the goal deterministically
1. Sort the input array
1. two pointer, one is on the left and other is on the right
1. calcualte the sum, if the sum is less than the given value, move the left to right. If the sum is greater than the target, move the right to left
1. if the sum is found, return the index. if  the right and left pointer meet each other, no solution

#### Algorithm 2
Use dictionary to help reduce searching time. The dictionary actual create a solution space and then we check if the new element in the solution space
1. Go through a loop
1. calcualte the expected leg and put it in a dictionary with key as expected leg and value as the first leg index. which is a pair 
1. for each new element, check if it exist in the current pair. if exist, return the index. and If not, create a new pair to the dictionary

### Three Sum
find 3 number in an array so that their sum is zero

#### Algorithm 1
1. Sorting the array
1. For element selected x, trying to the other two elements whose sum is -x, which is 2 sum problem and can be solved in O(n) time. 

