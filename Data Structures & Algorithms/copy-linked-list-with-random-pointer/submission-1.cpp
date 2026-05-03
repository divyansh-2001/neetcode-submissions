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
        if(!head || !head -> next){
            return head;
        }
        Node* head2 = head;

        while(head2){
            Node* nn = new Node(head2->val);
            nn -> next = head2 -> next;
            head2 -> next = nn;
            head2 = nn -> next;
        }

        head2 = head;
        int count = 0;
        while(head2){
            count++;
            if(head2 -> random == NULL){
                head2 -> next -> random = NULL;
            } else {
                head2 -> next -> random = head2 -> random -> next;
            }

            head2 = head2 -> next -> next;
        }

        Node* ans = NULL;
        Node* tail = NULL;
        head2 = head;
        Node* tail2 = head;

        while(head2){
            if(!ans){
                ans = head2 -> next;
                tail = ans;
                tail2 = head2;
            } else {
                tail -> next = head2 -> next;
                tail = tail -> next;
                tail2 -> next = head2;
                tail2 = tail2 -> next;
            }


            head2 = head2 -> next -> next;
        }

        tail -> next = NULL;
        tail2 -> next = NULL;

        return ans;
    }
};
