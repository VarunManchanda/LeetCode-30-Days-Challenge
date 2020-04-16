/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.

*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class Solution {
public:
    bool checkValidString(string s) {
        _fast_;
        vector<vector<int> > dp(s.length(), vector<int>(s.length(),INT_MIN));
        return dfs(s,0,0,dp);
    }
    bool dfs(string s,int index, int open, vector<vector<int> > &dp)
    {
    if(index==s.length()) return open==0;
    if(dp[index][open]!=INT_MIN) { return dp[index][open]; }
    if(s[index]=='('){ dp[index][open] = dfs(s,index+1,open+1,dp); }
    else if(s[index]==')'){ dp[index][open] = open!=0 && dfs(s,index+1,open-1,dp); }
    else { dp[index][open] =  
        dfs(s,index+1,open,dp) || dfs(s,index+1,open+1,dp) ||           open!=0&&dfs(s,index+1,open-1,dp);
         }
    return dp[index][open];

}
};
