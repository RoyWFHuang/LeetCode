

int search(int* nums, int numsSize, int target){
    int st = 0, ed = numsSize - 1;
    // int maxMin, Minmax;

    int fg = 0;
    if (0 == numsSize) return -1;
    if (1 == numsSize) {
        if (nums[0] == target) return 0;
        else return -1;
    }

    while(st <= ed) {
        int middle = (st + ed)/2;
        if (nums[middle] == target) return middle;
        else if (target < nums[middle]) {
            if(target < nums[st] && nums[st] <= nums[middle])
                st = middle + 1;
            else
                ed = middle -1;
        }
        else {
            if(target > nums[ed] && nums[ed] > nums[middle])
                ed = middle -1;
            else
                st = middle + 1;
        }
    }
    return -1;
}