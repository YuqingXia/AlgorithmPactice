#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int longestSubStringLength(string s){
    if(s.size() == 0) return 0;

    int sub_str_longest_len = 1;
    int sub_str_start_pos = 0;
    int sub_str_len = 1;
    unordered_map<char, int> map; 
    map[s[0]] = 0;

    for(int i = 1; i < s.size(); ++i){
        char c = s.at(i);
        auto it = map.find(c);
        if(it == map.end()){
            map[c] = i;
            sub_str_len += 1;
        }else{
            int last_pos = it -> second;
            if(last_pos >= sub_str_start_pos){
                sub_str_start_pos = last_pos + 1;
                sub_str_len = i - sub_str_start_pos + 1;
            }else{
                sub_str_len += 1;
            }
        }

        map[c] = i;

        if(sub_str_len > sub_str_longest_len) sub_str_longest_len = sub_str_len;
    }

    return sub_str_longest_len;
}