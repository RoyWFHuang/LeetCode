

char * longestPalindrome(char * s){
    char *ret = NULL;
    int *cent = NULL;
    int max = 0, curr_max = 0;
    int st = 0, ed = 0;
    int tmp_st = 0, tmp_ed = 0;
    cent = calloc(strlen(s), sizeof(int));
    for (int i = 1; i < strlen(s); i++) {
        if (s[i - 1] == s[i]) cent[i] += 1;
        if (s[i - 1] == s[i + 1]) cent[i] += 2;
        if (3 == cent[i]){
            int t_st = -2, t_ed = 2;
            int select = 1;
            cent[i] = 2;
            while(true) {
                if ((i + t_st) >= 0 && s[i + t_st] == s[i]) {
                    select = ((select + 1) & 0x01);
                    cent[i] = select + 1;
                }
                else break;
                if (((i + t_ed) < strlen(s)) && (s[i + t_ed] == s[i])) {
                    select = ((select + 1) & 0x01);
                    cent[i] = select + 1;
                }
                else break;
                t_st--;
                t_ed++;
            }
        }
    }
    for (int i = 1; i < strlen(s); i++){
        if (cent[i]) {
            switch(cent[i]) {
            case 1:
                tmp_st = i - 1;
                tmp_ed = i;
                break;
            case 2:
                tmp_st = i - 1;
                tmp_ed = i + 1;
                break;
            }
            while (true) {
                if (tmp_st - 1 < 0) break;
                if (tmp_ed + 1 > strlen(s)) break;
                if (s[tmp_st - 1] == s[tmp_ed + 1]) {
                    tmp_st --;
                    tmp_ed ++;
                }
                else break;
            }
            if (tmp_ed - tmp_st > max) {
                max = tmp_ed - tmp_st;
                st = tmp_st;
                ed = tmp_ed;
            }
        }

    }
    ret = s;
    ret += st;
    s[ed + 1] = 0x0;
    return ret;
}