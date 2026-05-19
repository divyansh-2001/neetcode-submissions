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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for(int i=0;i<lists.size();i++){
            if(!lists[i]){
                continue;
            }

            pq.push({lists[i]->val, i});
        }
        
        while(!pq.empty()){
            pair<int,int> front = pq.top();
            pq.pop();

            if(!head){
                head = lists[front.second];
                tail = head;
            } else {
                tail -> next = lists[front.second];
                tail = tail -> next;
            }

            lists[front.second] = lists[front.second]->next;
            if(lists[front.second]){
                pq.push({lists[front.second]->val, front.second});
            }
        }

        return head;
    }
};
