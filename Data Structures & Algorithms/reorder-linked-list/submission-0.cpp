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
private:
    ListNode* reverse(ListNode* head){
        if(!head || !head->next){
            return head;
        }

        ListNode* smallAns = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return smallAns;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next){
            return ;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast -> next;
            }
        }

        ListNode* reversedHead = reverse(slow);
        prev->next = NULL;

        ListNode* h1 = head;
        ListNode* h2 = reversedHead;
        ListNode* ans = NULL;
        ListNode* tail = NULL;

        while(h1 || h2){
            if(!ans){
                ans = h1;
                h1 = h1->next;
                ans -> next = h2;
                tail = h2;
                h2 = h2->next;
            } else {
                if(h1){
                    tail -> next = h1;
                    h1 = h1 -> next;
                    tail = tail->next;
                }

                if(h2){
                    tail -> next = h2;
                    h2 = h2 -> next;
                    tail = tail -> next;
                }
            }
        }   

        head = ans;
    }
};