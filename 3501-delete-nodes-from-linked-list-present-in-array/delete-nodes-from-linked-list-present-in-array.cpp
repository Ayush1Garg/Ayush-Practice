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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,bool> hash;
        for(auto i : nums) hash[i] = true;
        ListNode* dummy = new ListNode(0,head);
        ListNode* p = dummy, *q = head;
        while(p){
            if(!q || !hash[q->val]){
                p->next = q;
                p = p->next;
                if(!p) break;
            }
            q = q->next;
        }
        return dummy->next;
    }
};

static const int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
