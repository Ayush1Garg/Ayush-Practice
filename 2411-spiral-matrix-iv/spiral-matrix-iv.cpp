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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int t = 0, b = m-1, l = 0, r = n-1, d = 0, i = 0, j = 0;
        while(head && t<=b && l<=r){
            ans[i][j] = head->val;
            head = head->next;
            if(d==0){
                j++;
                if(j>r){
                    j = r;
                    i++;
                    t++;
                    d++;
                }
            }
            else if(d==1){
                i++;
                if(i>b){
                    i = b;
                    j--;
                    r--;
                    d++;
                }
            }
            else if(d==2){
                j--;
                if(j<l){
                    j = l;
                    i--;
                    b--;
                    d++;
                }
            }
            else if(d==3){
                i--;
                if(i<t){
                    i = t;
                    j++;
                    l++;
                    d = 0;
                }
            }
        }
        return ans;
    }
};