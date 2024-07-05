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
    bool isNextCrit(ListNode *node){
        bool localmax =  (node->next->val > node->val && node->next->val > node->next->next->val);
        bool localmin =  (node->next->val < node->val && node->next->val < node->next->next->val);
        return localmax || localmin;
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v(2);
        v[0] = INT_MAX;
        v[1] = INT_MIN;
        ListNode *p = head, *q = head;
        int dist = 0;
        while(q && q->next && q->next->next){
            cout<<q->val;
            if(isNextCrit(q)){
                cout<<"/ ";
                break;
            }
            cout<<" ";
            q = q->next;
        }
        p = q;
        q = q->next;
        dist = 1;
        while(q && q->next && q->next->next){
            cout<<q->val;
            if(isNextCrit(q)){
                v[0] = min(v[0],dist);
                if(v[1]==INT_MIN){
                    v[1] = dist;
                }
                else{
                    v[1] += dist;
                }
                p = q;
                dist = 0;
                cout<<"/ ";
            }
            else cout<<" ";
            q = q->next;
            dist++;
        }
        if(v[0]==INT_MAX) v[0] = -1;
        if(v[1]==INT_MIN) v[1] = -1;
        return v;
    }
};