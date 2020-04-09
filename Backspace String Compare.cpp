/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. 
# means a backspace character.
*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        _fast_;
        stack<char> st;
	string sc = "", tc = "";
	for(auto i : s)
	{
		if(i!='#') st.push(i);
		else 
		{
			if(st.empty()) continue;
			else st.pop();
		}
	}
	while(!st.empty()) 
	{
		sc += st.top(); st.pop();
	}
	for(auto i : t)
	{
		if(i!='#') st.push(i);
		else 
		{
			if(st.empty()) continue;
			else st.pop();
		}
	}
	while(!st.empty()) 
	{
		tc += st.top(); st.pop();
	}
	if(sc==tc) return true;
	return false;
    }
};
