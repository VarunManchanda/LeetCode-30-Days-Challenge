/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of 
all the elements of nums except nums[i].
*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        _fast_;
        int n = nums.size();
        vector<int> pref(n), suff(n), ans(n);
        pref[0]=nums[0]; suff[n-1]=nums[n-1];
        for(int i=1; i<n; i++)    pref[i] = pref[i-1] * nums[i];
        for(int i=n-2; i>=0; i--) suff[i] = suff[i+1] * nums[i];
        for(int i=1; i<n-1; i++)   ans[i] = pref[i-1] * suff[i+1];
        ans[0] = 1 * suff[1];
        ans[n-1] = pref[n-2] * 1;
        return ans;
    }
    
    
};
