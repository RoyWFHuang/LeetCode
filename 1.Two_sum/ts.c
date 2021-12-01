#include <limits.h>

typedef struct _tNum_par {
    int index;
    int num;
}tNum_par;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){


    tNum_par *list_array = (tNum_par *)malloc(sizeof(tNum_par)*numsSize);

    int use_list_array_idx = 0;
    if(numsSize>INT_MAX)
        goto twoSum_error;

    for(int i = 0; i<numsSize; i++){
        for(int idx = 0; idx < use_list_array_idx; idx++){
            if(list_array[idx].num == nums[i])
            {
                *returnSize = 2;
                int *ret_ans =(int *)malloc(sizeof(int)*2);
                ret_ans[0] = list_array[idx].index;
                ret_ans[1] = i;
                free(list_array);
                return ret_ans;
            }
        }

        list_array[use_list_array_idx].num =  target - nums[i];
        list_array[use_list_array_idx].index = i;
        use_list_array_idx++;
    }

twoSum_error:
    *returnSize = 0;
    return NULL;
}