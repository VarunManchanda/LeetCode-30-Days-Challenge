/*
Question:- Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


*/

class Solution {
public:
    //Time:- O(n)
    //Space:- O(1)
    int singleNumber(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int find = 0;
        for(int i=0; i<nums.size(); i++) find ^= nums[i];
        return find;
    }
};
