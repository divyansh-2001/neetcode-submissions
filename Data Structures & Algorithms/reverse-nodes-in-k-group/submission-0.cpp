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
    ListNode* rev(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* smallAns = rev(head->next);
        head->next->next = head;
        head->next = NULL;

        return smallAns;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k <= 1){
            return head;
        }

        ListNode* start = head;
        ListNode* end = head;
        
        for(int i=0;i<k-1;i++){
            end = end -> next;

            if(end == NULL){
                return head;
            }
        }

        ListNode* prevTail = NULL;
        ListNode* ans = NULL;

        while(end != NULL){
            ListNode* nextHead = end -> next;
            end -> next = NULL;

            ListNode* reversed = rev(start);

            if(prevTail != NULL){
                prevTail -> next = reversed;   
            }

            prevTail = start;

            if(ans == NULL){
                ans = reversed;
            }

            start = nextHead;
            end = nextHead;
            
            for(int i=0;i<k-1;i++){
                if(end == NULL){
                    prevTail -> next = nextHead;
                    return ans;
                }

                end = end -> next;
                
                if(end == NULL){
                    prevTail -> next = nextHead;
                    return ans;
                }
            }
        }

        return ans;
    }
};
