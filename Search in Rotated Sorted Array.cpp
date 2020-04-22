/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1)
        {
            if(nums[0]==target)
            {
                return 0;
            }
            return -1;
        }
        return binary_search(nums,0,nums.size()-1,target);
    }
    int binary_search(vector<int> a, int s, int e, int key)
    {
        while(s<=e)
        {
            int mid = (s+e)/2;
            if(a[mid]==key)
            {
                return mid;
            }
            else if(a[s]<=a[mid])
            {
                if(key>=a[s] && key<=a[mid])
                {
                    e = mid-1;
                }
                else
                {
                    s = mid+1;
                }
            }
            else
            {
                if(key>=a[mid] && key<=a[e])
                {
                    s = mid+1;
                }
                else
                {
                    e = mid-1;
                }
            }
        }
        return -1;
    }
};
