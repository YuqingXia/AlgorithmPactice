#include"twoSumSolution.cpp"
#include<iostream>
using namespace std;

int main(){
    vector<int> nums={2, 7, 11, 15};
    int target(9);
    vector<int> res={0, 1};
    Solution solution;
    vector<int> ret = solution.twoSum(nums, target);

    if(ret == res){
        cout << "Passed test" << endl;
    }else{
        cout << "Failed test" << endl;
    }
}