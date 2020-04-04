/*Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return dAndC(nums,0,nums.size()-1);
    }
    int dAndC(vector<int> &nums, int s, int e)
    {
        if(s==e) return nums[s];
        int mid = (s+e)/2;
        int left = dAndC(nums,s,mid);
        int right = dAndC(nums,mid+1,e);
        int sum = crossSum(nums,s,mid,e);
        return max(sum,max(left,right));
    }
    int crossSum(vector<int> &nums, int left, int mid, int right)
    {
        int maxleftsum = INT_MIN;
        int sum = 0;
        for(int i=mid; i>=left; i--)
        {
            sum += nums[i];
            maxleftsum = max(maxleftsum, sum);
        }
        int maxrightsum = INT_MIN;
        sum = 0;
        for(int i=mid+1; i<=right; i++)
        {
            sum += nums[i];
            maxrightsum = max(maxrightsum, sum);
        }
        return maxleftsum+maxrightsum;
    }
};
