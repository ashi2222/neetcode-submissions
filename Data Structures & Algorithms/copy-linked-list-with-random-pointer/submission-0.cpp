/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*curr = head;
        while(curr!=NULL)
        {
            Node*newnode = new Node(curr->val);
            newnode->next=curr->next;
            curr->next=newnode;
            curr=newnode->next;
        }
        curr=head;

        while(curr!=NULL)
        {
            if(curr->random!=NULL)
            {
                curr->next->random = curr->random->next;
            }
            curr=curr->next->next;
        }

        Node*ptr = new Node(-1);
        Node*ans = ptr;

        curr=head;
        while(curr!=NULL)
        {
            ptr->next=curr->next;
            ptr=ptr->next;

            curr->next=ptr->next;
            curr =curr->next;
        }

        ptr = ans->next;
        delete ans;
        return ptr;
    }
};
