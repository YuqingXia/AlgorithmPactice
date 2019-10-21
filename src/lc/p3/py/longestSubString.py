from typing import Dict

def lengthOfLongestSubstring(s: str) -> int:
    if len(s) == 0: 
        return 0
    
    str_len_longest: int = 1
    character_pos: Dict[str, int] = {s[0]:0}
    sub_str_start_pos = 0
    sub_str_len = 1

    for n in range(1, len(s)):
        c = s[n]
        if not c in character_pos:
            character_pos[c] = n
            sub_str_len += 1
            if sub_str_len > str_len_longest:
                str_len_longest = sub_str_len
        else:
            last_pos = character_pos[c]
            character_pos[c] = n
            
            if last_pos >= sub_str_start_pos:
                sub_str_start_pos = last_pos + 1
                sub_str_len = n - sub_str_start_pos + 1
            else:
                sub_str_len += 1
                if sub_str_len > str_len_longest:
                    str_len_longest = sub_str_len
            

    return str_len_longest


