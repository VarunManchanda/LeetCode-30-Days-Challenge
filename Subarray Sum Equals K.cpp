/*
Given an array of integers and an integer k, you need to find the total number of 
continuous subarrays whose sum equals to k.
*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class Solution {
public:
    int subarraySum(vector<int> arr, int k){
        _fast_;
        if(arr.size()==0) return 0;
        //return bruteForce(arr,k);
        return fastMethod(arr,k);
    }
    int bruteForce(vector<int> arr, int k)
    {
        int n = arr.size();
        int count = 0;
        vector<int> prefix(n+1);
        prefix[0] = 0;
        for(int i=1; i<=n; i++)
        {
            prefix[i] = prefix[i-1] + arr[i-1];
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(prefix[j]-prefix[i]==k)
                {
                    count+=1;
                }
            }
        }
        return count;
    }
    int fastMethod(vector<int> arr, int k)
    {
        unordered_map<int,int> prefixMap;
        int n = arr.size();
        int count = 0; int sum = 0;
        prefixMap[0] = 1;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            if(prefixMap.find(sum-k)!=prefixMap.end())
            {
                count += prefixMap[sum-k];
            }
            prefixMap[sum]++;
        }
        return count;
        
    }
};
