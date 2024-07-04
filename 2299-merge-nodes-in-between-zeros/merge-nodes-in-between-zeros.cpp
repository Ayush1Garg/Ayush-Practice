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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *p = head, *q = head->next;
        while(q){
            while(q->val!=0){
                p->val += q->val;
                q = q->next;
            }
            if(q->val==0){
                if(q->next==NULL) p->next=NULL;
                else{
                    p = p->next;
                    p->val = 0;
                }
                q = q->next;
            }
        }
        return head;
    }
};