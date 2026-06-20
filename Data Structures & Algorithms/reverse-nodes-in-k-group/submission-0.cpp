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
    pair<ListNode*,ListNode*> reverse(ListNode*head)
    {
        if(head == NULL)return {NULL,NULL};
        ListNode*curr = head;
        ListNode*prev = NULL;
        ListNode*tail = head;
        while(curr!=NULL)
        {
            ListNode*newnode = curr->next;
            curr->next=prev;
            prev = curr;
            curr = newnode;
        }
        return {prev , tail};

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)return NULL;
        ListNode*curr = head;
        ListNode*node = NULL;
        ListNode*tail = NULL;
        ListNode*ahead = head;
        // ListNode*aprev = head;
        int count = 0;
        while(curr!=NULL)
        {
            count++;
            ListNode*nextnode = curr->next;
            if(count == k){
                count=0;
                curr->next=NULL;
                pair<ListNode*,ListNode*>p = reverse(ahead);
                ahead = nextnode;
                ListNode*h=p.first;
                ListNode*t=p.second;
                if(node == NULL){
                    node = h;
                }
                else{
                    tail->next=h;
                }
                tail = t;
                cout<<((tail)?(tail->val):0)<<endl;
            }
            curr = nextnode;
            // curr=curr->next;
        }
        if(ahead!=NULL)tail->next=ahead;
        return node;
    }
};