/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode*curr = head;
        ListNode*prev = head;
        while(curr!=NULL && curr->next!=NULL)
        {
            curr=curr->next->next;
            prev=prev->next;
            if(curr==prev)return true;
        }
        return false;
    }
};
