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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = NULL;

        ListNode* left = head;
        ListNode* right = head;

        for(int i=0;i<n;i++){
            if(right == NULL){
                return NULL;
            }

            right = right->next;
        }

        if(right == NULL){
            return head->next;
        }

        while(right != NULL){
            right = right->next;
            prev = left;
            left = left->next;
        }

        prev -> next = left -> next;
        
        return head;
    }
};
