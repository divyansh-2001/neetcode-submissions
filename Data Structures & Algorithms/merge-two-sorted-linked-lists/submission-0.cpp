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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }

        if(!list2){
            return list1;
        }

        ListNode* ans = NULL;
        ListNode* tail = NULL;

        while(list1 != NULL || list2 != NULL){
            if(list1 != NULL && list2 != NULL){
                if(list1 -> val < list2 -> val){
                    if(!ans){
                        ans = list1;
                        tail = ans;
                        list1 = list1 -> next;
                        continue;
                    } else {
                        tail -> next = list1;
                        list1 = list1 -> next;
                    }
                } else{
                    if(!ans){
                        ans = list2;
                        tail = ans;
                        list2 = list2 -> next;
                        continue;
                    } else {
                        tail -> next = list2;
                        list2 = list2 -> next;
                    }
                }

                tail = tail -> next;
            } else if (list1 != NULL){
                tail -> next = list1;
                break;
            } else {
                tail -> next = list2;
                break;
            }
        }

        return ans;
    }
};
