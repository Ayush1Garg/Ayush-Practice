class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        DisjointSet ds1(n+1);
        DisjointSet ds2(n+1);
        int cnt = 0;
        for (auto& e : edges) {
            if (e[0] == 3) {
                if ((ds1.findUPar(e[1]) == ds1.findUPar(e[2])) &&
                    (ds2.findUPar(e[1]) == ds2.findUPar(e[2]))) {
                    cnt++;
                } else {
                    ds1.unionByRank(e[1], e[2]);
                    ds2.unionByRank(e[1], e[2]);
                }
            }
        }
        for (auto& e : edges) {
            if (e[0] == 1) {
                if ((ds1.findUPar(e[1]) == ds1.findUPar(e[2]))) {
                    cnt++;
                } else {
                    ds1.unionByRank(e[1], e[2]);
                }
            } else if (e[0] == 2) {
                if ((ds2.findUPar(e[1]) == ds2.findUPar(e[2]))) {
                    cnt++;
                } else {
                    ds2.unionByRank(e[1], e[2]);
                }
            }
        }
        int ct1=0;
        int ct2=0;
        for(int i=1; i<=n; i++)
        {
            if(ds1.findUPar(i)==i)
            {
                ct1++;
            }
            if(ds2.findUPar(i)==i)
            {
                ct2++;
            }
        }
        if(ct1>1 || ct2>1)
        {
            return -1;
        }
        
        return cnt;
    }
};