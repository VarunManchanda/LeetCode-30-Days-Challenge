/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
*/
#define _fast_ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        _fast_;
        return greedyApproach(nums);
    }
    bool greedyApproach(vector<int> nums)
    {
        int n = nums.size()-1;
        int m = 0;
        for(int i=0; i<=m; i++)
        {
            m = max(m, i+nums[i]);
            if(m >= n) return true;
        }
        return false;
    }
    bool bfs(vector<int> nums)
    {
        map<unsigned long long int,bool> visited;
        queue<unsigned long long int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty())
        {
            unsigned long long int node = q.front(); q.pop();
            if(node+nums[node] >= nums.size()-1)
            {
                return true;
            }
            for(unsigned long long int i=1; i<=nums[node]; i++)
            {
                if (i + node >= nums.size() or nums[i + node]>=nums.size()) return true;
                if(!visited[node+i])
                {
                    q.push(node+i);
                    visited[node+i] = true;
                    if(visited[nums.size()-1])
                    {
                        return true;
                    }
                }
            }
            
        }
        if(visited[nums.size()-1])
        {
            return true;
        }
        return false;
    }
};
