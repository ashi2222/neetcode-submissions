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

class ashu{
    public:
    bool operator()(ListNode*a , ListNode*b)
    {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , ashu>pq;

        for(int i = 0 ; i< lists.size() ; i++)
        {
            if(lists[i]!=NULL)pq.push(lists[i]);
        }
        ListNode*node = new ListNode(-1);
        ListNode*ptr = node;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            if(it->next!=NULL){
                pq.push(it->next);
            }
            node->next=it;
            node=it;
        }
        return ptr->next;
    }
};
