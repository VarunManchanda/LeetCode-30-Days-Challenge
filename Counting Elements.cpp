/*
Given an integer array arr, count element x such that x + 1 is also in arr.
If there're duplicates in arr, count them seperately.
*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class Solution {
public:
    int countElements(vector<int>& arr) {
        _fast_;
        if(arr.size()==0) return 0;
        unordered_map<int,int> hashMap;
        int ans = 0;
        for(auto i : arr) hashMap[i]++;
        for(auto i : hashMap) (hashMap.count(i.first+1)) ? ans += hashMap[i.first] : ans += 0;
        return ans;
    }
};
