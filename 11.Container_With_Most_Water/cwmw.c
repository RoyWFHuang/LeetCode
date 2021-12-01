 #define MIN(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

int maxArea(int* height, int heightSize){
    if (NULL == height) return 0;
    int st = 0, ed = heightSize - 1;
    int tmp_max = 0, max = 0;
    while(st < ed) {
        tmp_max = MIN(height[st], height[ed]) * (ed - st) ;
        if (tmp_max > max) max = tmp_max;
        if(height[st] < height[ed]) st++;
        else ed --;
    }
    return max;
}