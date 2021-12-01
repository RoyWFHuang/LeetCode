

bool isValid(char * s){
    int len = strlen(s);
    if (len & 0x01) return false;
    char *st = calloc((len >> 1), sizeof(char));
    int idx = 0;
    // printf("%d\n", len);
    for(int i = 0; i < len; i++) {
        // printf("%s %s %d\n",s , st, idx);
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if ((idx - 1) >= 0) {
                if (')' == s[i]) {
                    if ('(' != st[idx - 1]) goto error;
                    else idx--;
                } else if ('}' == s[i]) {
                    if ('{' != st[idx - 1]) goto error;
                    else idx--;
                } else {
                    if ('[' != st[idx - 1]) goto error;
                    else idx--;
                }
            } else {
                goto error;
            }
        } else {

        // printf("%s %s %d\n",s , st, idx);
            if ((idx) == (len >> 1)) {
                goto error;
            }
            st[idx] = s[i];
            idx++;

        }
    }
    if (idx != 0) return false;
    free(st);
    return true;
error:
    free(st);
    return false;
}