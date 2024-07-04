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
static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout.tie(nullptr);
    return 0;
}();

int init = [] {
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string str; getline(cin, str);) {
        istringstream ss(str); ss.ignore(3);
        ostringstream os;
        int sum = 0;
        bool first = true;
        cout << '[';
        for (int i; ss >> i; ss.ignore()) {
            if (!i) {
                os << (first ? "" : ",") << sum;
                sum = 0;
                first = false;
            } else {
                sum += i;
            }
        }
        os << ']';
        cout << os.str() << '\n';
    }
    exit(0);
    return 0;
}();
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ret = nullptr;
        ListNode* curr = nullptr;
        int sum = 0;
        while(head != nullptr){
            if(head->val == 0){
                if(sum == 0){
                    head = head->next;
                    continue;
                }
                ListNode* node = new ListNode(sum);
                if(curr == nullptr){
                    curr = node;
                    ret = node;
                    head = head->next;
                    sum = 0;
                    continue;
                }
                curr->next = node;
                curr = node;
                head = head->next;
                sum = 0;
                continue;
            }
            int x = head->val;
            sum = sum + x;
            head = head->next;
        }

        return ret;
    }
};