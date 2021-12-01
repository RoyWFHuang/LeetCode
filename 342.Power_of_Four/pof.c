#include<stdio.h>
#include<string.h>

bool isPowerOfFour(int n){
    // if (n <= 0) return false;
    // int first_bit = ffs(n);
    // if ((0x00000001 << (first_bit - 1)) != n) return false;
    // if (first_bit & 0x01) return true;
    // return false;
    return (n > 0) && !(n & (n - 1)) && (n & 0x55555555);
}

