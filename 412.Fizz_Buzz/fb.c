#include <stdlib.h>
#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    char *num = "%d";
    char *fizz = "Fizz";
    char *buzz = "Buzz";
    char *fizzbuzz = "FizzBuzz";
    char **ret = malloc(sizeof(char *) * n);
    char *tmp = NULL;
    int i,j;
    char *maplist[] = {fizzbuzz, num,  num,  fizz, num,  buzz,
                                fizz, num,  num,  fizz, buzz,
                                num,  fizz, num,  num,  fizzbuzz
                                };
    for (i = 1, j = i; i < n +1 ; i++, j++) {
        if (j > 15) j >>= 4;
        ret[i - 1] = malloc(9 * sizeof(char));
        sprintf(ret[i - 1] , maplist[j], i);
        // int length = snprintf(NULL, 0, maplist[j], i);
        // ret[i - 1] = malloc(length + 1);
        // snprintf(ret[i - 1], length + 1, maplist[j], i);
    }
    *returnSize = n;
    return ret;
}

int main(){
    int i;
    char **ret = fizzBuzz(3, &i);
    for (int j = 0; j < i ;j++){
        printf("%s ", ret[j]);
    }
    return 0;
}