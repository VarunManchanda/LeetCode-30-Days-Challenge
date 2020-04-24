/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
*/
class Solution {
public:
    int rangeBitwiseAnd(int a, int b) {
        while(a < b){ 
            b -= (b & -b); 
        } 
        return b; 
    }
};
