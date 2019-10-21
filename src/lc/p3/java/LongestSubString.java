import java.util.HashMap;

public class LongestSubString{
    public int lengthOfLongestSubstring(String s) {
        if(s.length() == 0) return 0;
        
        Integer subStrLongestLength = 1;
        HashMap<Character, Integer> charPosMap = new HashMap<Character, Integer>();
        charPosMap.put(s.charAt(0), 0);
        Integer sub_str_start_pos = 0;
        Integer sub_str_len = 1;

        for(int i = 1; i < s.length(); ++i){
            Character c = s.charAt(i);
            if(charPosMap.containsKey(c)){
                Integer last_pos = charPosMap.get(c);
                if(last_pos >= sub_str_start_pos){
                    sub_str_start_pos = last_pos+1;
                    sub_str_len = i - sub_str_start_pos + 1;
                }else{
                    sub_str_len += 1;
                }
                charPosMap.put(c, i);
            }else{
                charPosMap.put(c, i);
                sub_str_len += 1;
            }

            if(sub_str_len > subStrLongestLength) subStrLongestLength = sub_str_len;
            //System.out.println("i=" + i + " sub_str_len: " + sub_str_len + " sub_str_start_pos: "+ sub_str_start_pos + "subStrLongestLength: "+ subStrLongestLength);
        }

        return subStrLongestLength;
    }
}