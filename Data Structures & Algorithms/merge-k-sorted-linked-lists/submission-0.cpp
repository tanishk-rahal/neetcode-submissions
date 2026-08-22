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
    struct compare {
        bool operator()(ListNode* a , ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* ,vector<ListNode*>, compare> pq ;
        //strores head of each list in pq;
        for(int i=0;i<lists.size(); i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
        }
        //dummy node to store new merged list ;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy ;
        while(!pq.empty()){
            ListNode* node = pq.top();//gets the smallest value node;
            pq.pop();
            temp->next = node;
            temp = temp->next;

            if(node->next != NULL){//pushing next node of same list from which we poped;
                pq.push(node->next);
            }

        }
        return dummy->next;
    }
};
