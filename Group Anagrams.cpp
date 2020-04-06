/*
Given an array of strings, group anagrams together.
*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        _fast_;
        unordered_map<string,list<string> > hashMap;
        vector<vector<string> > ans;
        int k = 0;
        for(int i=0; i<str.size(); i++) //O(str.size())
        {
            string temp = str[i];
            sort(str[i].begin(),str[i].end());//O(str[i].size()*log(str[i].size()))
            hashMap[str[i]].push_back(temp);//O(log(str[i].size()))
        }
        for(auto i : hashMap)
        {
            vector<string> sub;
            for(auto j : i.second)
            {
                sub.emplace_back(j);
            }
            ans.emplace_back(sub);
        }
        return ans;
    }
};
