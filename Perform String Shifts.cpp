/*
You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:
direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.
*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        _fast_;
        int m = s.length();
        int n = (int)shift.size();
        deque<char> q;
        string ans = "";
        for(auto c : s) q.push_back(c);
        for(int i=0; i<n; i++)
        {
            int dir =   shift[i][0];
            int moves = shift[i][1];
            if(!(dir&1))
            {
                for(int j=0; j<moves; j++)
                {
                    char front = q.front(); q.pop_front();
                    q.push_back(front);
                }
            }
            else
            {
                for(int j=0; j<moves; j++)
                {
                    char last = q.back(); q.pop_back();
                    q.push_front(last);
                }
            }
        }
        for(auto i : q) ans+=i;
        return ans;
    }
};
