/*
Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.
*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        _fast_;
        if(head==NULL) return head;
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while(fastptr->next!=NULL and fastptr!=NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next;
            if(fastptr->next==NULL)
                return slowptr;
            else
                fastptr = fastptr->next;
        }
        return slowptr;
    }
};
