/*Given an array nums, write a function to move all 0's to the end of it while maintaining the 
relative order of the non-zero elements.
*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        _fast_;
        fastMethod(nums);
        return;
    }
    void fastMethod(vector<int> &arr)
    {
        int p = 0;
	    int q = 0;
	    while(q<arr.size())
	    {
		    if(arr[q]!=0)
		    {
			    swap(arr[p],arr[q]);
			    p++; q++;
		    }
		    else if(arr[q]==0)
		    {
			    q++;
		    }
	    }
        return;
    }
    void bruteForce(vector<int> &nums)
    {
        unordered_map<int,list<int> > hashMap;
        int count = 0; int k = 1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0) count+=1;
            else{
                hashMap[nums[i]].push_back(k);
                k+=1;
            }
        }
        int index = nums.size()-count;
        for(auto i : hashMap)
        {
            for(auto j : i.second)
            {
                nums[j-1] = i.first;
            }
        }
        while(count--)
        {
            nums[index++] = 0;
        }
        return;
    }
};
