//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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
/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/

class Solution
{
    public:
    unordered_map<int,int> mp;
    void dfs(Node* root, int &lefts){
        if(mp.find(lefts)==mp.end()) mp[lefts]=0;
        mp[lefts] += root->data;
        if(root->left){
            lefts++;
            dfs(root->left,lefts);
            lefts--;
        }
        if(root->right) dfs(root->right,lefts);
    }
    vector <int> diagonalSum(Node* root) {
        // Add your code here
        vector<int> ans;
        vector<pair<int,int>> ex;
        if(!root) return ans;
        int lefts = 0;
        mp.clear();
        dfs(root,lefts);
        for(auto x:mp){
            // cout<<x.first<<" "<<x.second<<endl;
            ex.push_back(x);
        }
        sort(ex.begin(),ex.end());
        for(auto p: ex){
            ans.push_back(p.second);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        vector <int> res = obj.diagonalSum(root);
        for (int i : res) cout << i << " ";
        cout<<endl;
    }
    return 1;
}
// } Driver Code Ends