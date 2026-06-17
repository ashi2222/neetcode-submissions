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
   ListNode*reverse(ListNode*node)
    {
        ListNode*curr = node;
        ListNode*prev = NULL;
        while(curr!=NULL)
        {
            ListNode*newnode = curr->next;
            curr->next=prev;
            prev=curr;
            curr=newnode;
        } 
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode*curr = head;
        ListNode*prev = head;
        while(curr!=NULL && curr->next!=NULL)
        {
            curr=curr->next->next;
            prev=prev->next;
        }
        ListNode*ans = prev;
        prev = prev->next;
        ans->next=NULL;
        curr = head;
        // ListNode*ans = head;
        ListNode*newnode = reverse(prev);
        int even = 0;
        while(curr!=NULL && newnode!=NULL)
        {
            if(even==0)
            {
                ListNode*nextcurr = curr->next;
                curr->next=newnode;
                curr = nextcurr;
                even=1;
            }
            else{
                ListNode*nextnewnode = newnode->next;
                newnode->next=curr;
                newnode = nextnewnode;
                even=0;
            }
        }
    }
};
