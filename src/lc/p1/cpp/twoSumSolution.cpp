#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> & nums, int target){
        vector<int>  index(nums.size());
        for(int i=0; i < index.size(); ++i){
            index[i] = i;
        }

        sort(index.begin(), index.end(), 
            [&nums](int i1, int i2){
                return nums[i1] < nums[i2];
            });

        vector<int> ret(2);
        int il(0), ir(nums.size()-1);
        int s;

        while(il < ir){
            s = nums[index[il]] + nums[index[ir]];
            if(s < target){
                ++il;
            }else if (s > target){
                --ir;
            }else{
                ret[0] = index[il];
                ret[1] = index[ir];
                break;
            }
        }

        return ret;        
    }

    vector<int> twoSum2(vector<int> & nums, int target){
        unordered_map<int, int> map;
        vector<int> ret(2);
        for(int i=0; i < nums.size(); ++i){
            auto it = map.find(nums[i]);
            if(it == map.end()){
                map[target-nums[i]] = i;
            }else{
                //found
                ret[0] = it->second;
                ret[1] = i;
                break;
            }
        }
        return ret;
    }
};