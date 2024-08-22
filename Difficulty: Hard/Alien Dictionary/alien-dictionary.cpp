//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string findOrder(string dict[], int N, int k)
    {
        vector<vector<int>> mat(k, vector<int>(k));
        for (int i = 0; i + 1 < N; i++) {
            string &a = dict[i], &b = dict[i + 1];
            int n = a.size(), m = b.size(), j = 0;
            while (j < n and j < m and a[j] == b[j])
                j++;
            if (j < n and j < m)
                mat[a[j] - 'a'][b[j] - 'a'] = 1;
        }
        vector<int> vis(k);
        string ans;
        auto fun = [&](auto self, int u) -> void {
            vis[u] = true;
            for (int v = 0; v < k; v++)
                if (mat[u][v] and !vis[v])
                    self(self, v);
            ans.push_back('a' + u);
        };
        for (int i = 0; i < k; i++)
            if (!vis[i])
                fun(fun, i);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends