/*
We have a collection of stones, each stone has a positive integer weight.
Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  
The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)
*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        _fast_;
        priority_queue<int> pq;
        for(auto i : stones) pq.push(i);
        int ans = 0;
        while(!pq.empty())
        {
            int y = pq.top(); pq.pop();
            if(pq.empty()) return y;
            int x = pq.top(); pq.pop();
            if(x==y) pq.push(0);
            else pq.push(y-x);
        }
        return ans;
    }
};
