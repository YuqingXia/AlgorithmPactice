* Algorithm: Dynamic programing,
* Time complexity: O(N)
* Space complexity: O(N)

### Algorithm:
Let $L_i$ be the longest substring length of string to $S[0 \cdots i]$ and $s_{ji}$ be the longest substring including $S[i]$ without repeated character
$$
s_{j,i} = 
\begin{cases}
s_{j,i} & \text{if }  S[i] \text{ is not in } s_{j, i-1} \\
s_{j'+1, i} & \text{if } S[i] = S[j'] \text{ and } j' > j \\
\end{cases}
$$
And
$$
L_i = 
\begin{cases}
L_i & \text{if } L_i > len(s_{j, i}) \\
len(s_{j, i}) & if L_i < len(s_{j, i})
\end{cases}
$$

To check if the new character in the substring $s_{j, i}$ or not. For such a searching problem, O(1) solution is map. Map from character to position index will make it easy to check if the new element is in the substring or not if we keep update the first position of the substring. 

### Sudo code
```
//edge case
if S is empty:
    return 0

//init
max_sub_str_len = 1

c_pos_map = {S[0]: 0}
sub_str_start_pos = 0
sub_str_len = 1

for each element position pair (e, n) in S[1...]:
    if not e in c_pos_map:
        sub_str_len += 1
        c_pos_map[e] = n
    else:
        n0 = c_pos_map[e]
        c_pos_map[e] = n
        if n0 > sub_str_start_pos:
            sub_str_start_pos = n0 + 1
            sub_str_len = n - sub_str_start_pos + 1 
        else:
            sub_str_len += 1


    if sub_str_len > max_sub_str_len:
        max_sub_str_len = sub_str_len
```



