//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    /**
     * Helper function to determine the largest BST subtree.
     * @param root The root of the current subtree.
     * @param maxSize The size of the largest BST found so far.
     * @return A tuple containing:
     * - bool: Indicates if the current subtree is a BST.
     * - int: The size of the current subtree if it is a BST.
     * - Node*: The node with the minimum value in the current subtree.
     * - Node*: The node with the maximum value in the current subtree.
     */
    tuple<bool, int, Node*, Node*> largestBSTSubtreeHelper(Node* root, int& maxSize) {
        // Base case: If the node is null, it's a valid BST with size 0
        if (!root) {
            return make_tuple(true, 0, nullptr, nullptr);
        }

        // Recursively call for left and right subtrees
        auto leftResult = largestBSTSubtreeHelper(root->left, maxSize);
        auto rightResult = largestBSTSubtreeHelper(root->right, maxSize);

        // Manually unpack the results of the left and right subtrees
        bool leftIsBST = get<0>(leftResult);
        int leftSize = get<1>(leftResult);
        Node* leftMinNode = get<2>(leftResult);
        Node* leftMaxNode = get<3>(leftResult);

        bool rightIsBST = get<0>(rightResult);
        int rightSize = get<1>(rightResult);
        Node* rightMinNode = get<2>(rightResult);
        Node* rightMaxNode = get<3>(rightResult);

        // Check if the current subtree rooted at 'root' is a valid BST
        bool validLeft = !leftMaxNode || root->data > leftMaxNode->data;
        bool validRight = !rightMinNode || root->data < rightMinNode->data;

        if (leftIsBST && rightIsBST && validLeft && validRight) {
            // Current subtree is a valid BST
            int size = 1 + leftSize + rightSize; // Size of the current BST
            maxSize = max(maxSize, size); // Update the maximum BST size found so far
            Node* minNode = root->left ? leftMinNode : root; // Minimum value in the current BST
            Node* maxNode = root->right ? rightMaxNode : root; // Maximum value in the current BST
            return make_tuple(true, size, minNode, maxNode);
        }

        // Current subtree is not a valid BST
        return make_tuple(false, 0, nullptr, nullptr);
    }

public:
    int largestBst(Node* root) {
        int maxSize = 0; // Initialize the maximum size of the BST subtree
        largestBSTSubtreeHelper(root, maxSize); // Call the helper function
        return maxSize; // Return the size of the largest BST subtree
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends