/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        _fast_;
        return fastMethod(nums);
    }
    int fastMethod(vector<int> &nums)
    {
        unordered_map<int,int> hashMap;
        hashMap[0] = -1;
        int count = 0, ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]&1) count+=1;
            else count+=-1;
            if(hashMap.find(count)!=hashMap.end())
            {
                ans = max(ans,i-hashMap[count]);
            }
            else hashMap[count] = i;
        }
        return ans;
        
    }
};
