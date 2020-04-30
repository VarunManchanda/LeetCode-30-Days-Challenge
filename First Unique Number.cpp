/*
You have a queue of integers, you need to retrieve the first unique integer in the queue.
Implement the FirstUnique class:
FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.
*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class FirstUnique {
public:
    queue<int> q;
    unordered_map<int,int> hashMap;
    FirstUnique(vector<int>& nums) {
        for(auto i : nums)
        {
            q.push(i);
            hashMap[i]++;
            while(!q.empty())
            {
                if(hashMap[q.front()]>1) q.pop();
                else break;
            }
        }
    }
    int showFirstUnique() {
        if(!q.empty()) return q.front();
        return -1;
    }
    void add(int value) {
        q.push(value);
        hashMap[value]++;
        while(!q.empty())
        {
            if(hashMap[q.front()]>1) q.pop();
            else break;
        }
    }
};
