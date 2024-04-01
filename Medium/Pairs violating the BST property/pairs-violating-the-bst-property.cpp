//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:

    /*You are required to complete below function */
    void traverse(Node* node, vector<int> &inorder){
        if(node == NULL){
            return;
        }
        
        traverse(node->left, inorder);
        inorder.push_back(node->data);
        traverse(node->right, inorder);
    }
    
    int merge(vector<int> &inorder, int l, int m, int r){
        vector<int> v(r - l + 1);
        
        int x = l;
        int y = m + 1;
        
        int z = 0;
        
        int invCnt = 0;
        
        while(x <= m && y <= r){
            if(inorder[x] <= inorder[y]){
                v[z++] = inorder[x++];
            }else{
                v[z++] = inorder[y++];
                
                invCnt += m - x + 1;
            }
        }
        
        while(x <= m){
            v[z++] = inorder[x++];
        }
        
        while(y <= r){
            v[z++] = inorder[y++];
        }
        
        z = 0;
        
        for(int i = l; i <= r; i++){
            inorder[i] = v[z++];
        }
        
        return invCnt;
    }
    
    
    int mergeSort(vector<int> &inorder, int l, int r){
        int invCnt = 0;
        
        if(l < r){
            int m = l + (r - l)/2;
            
            invCnt += mergeSort(inorder, l, m);
            invCnt += mergeSort(inorder,m + 1, r);
            invCnt += merge(inorder, l, m, r);
        }
        
        return invCnt;
    }

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        
        vector<int> inorder;
        
        traverse(root, inorder);
        
        int invCnt = 0;
        
        invCnt = mergeSort(inorder, 0, n - 1);
        
        return invCnt;
    }
    
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends