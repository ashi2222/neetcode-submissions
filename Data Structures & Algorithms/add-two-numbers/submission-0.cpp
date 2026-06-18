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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0 ;
        ListNode*ans = new ListNode(-1);
        ListNode*ptr = ans;
        int ans1 = 0;
        int val1 = 0;
        while((l1!=NULL) or (l2!=NULL) or (carry!=0))
        {
            ans1 = ((l1)? l1->val : 0) + ((l2) ? l2->val : 0) + carry ;
            val1 = ans1%10;
            carry = ans1/10;
            ListNode*newnode = new ListNode(val1);
            ans->next=newnode;
            ans=ans->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        ans = ptr->next;
        delete ptr;
        return ans;
    }
};
