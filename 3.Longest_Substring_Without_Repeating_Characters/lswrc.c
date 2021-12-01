

int lengthOfLongestSubstring(char * s)
{
    int start = 0, end = 0;
    int max = 0, curr_max = 0;
    bool exist_table[256];
    memset(exist_table, 0 ,sizeof(exist_table));
    if (NULL == s) return 0;
    for (end = 0; end < strlen(s); end++) {
        if (!exist_table[s[end]]) {
            exist_table[s[end]] = true;
        } else {
            curr_max = end - start;

            if (curr_max > max) max = curr_max;

            for (; start < end; start++) {
                exist_table[s[start]] = false;
                if  (s[start] == s[end]) {
                    exist_table[s[start]] = true;
                    start++;
                    break;
                }
            }
        }
    }
    curr_max = end - start;
    if (curr_max > max) max = curr_max;
    return max;
}