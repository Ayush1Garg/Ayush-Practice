//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        // Step 1: Create a new node with the value `x`
        Node* newNode = new Node();
        newNode->data = x;
        
        // Step 2: Initialize pointers for traversal
        Node* prev = nullptr;
        Node* ptr = head;
        
        // Step 3: Traverse the list to find the correct insertion point
        while (ptr != nullptr && x >= ptr->data) {
            prev = ptr;    // Update prev as we move
            ptr = ptr->next; // Move ptr to the next node
        }
        
        // Step 4: Insert at the beginning if x is smaller than head's data
        if (ptr == head) {
            newNode->next = head;    // Link newNode to head
            head->prev = newNode;    // Link head back to newNode
            newNode->prev = nullptr; // New head has no previous node
            return newNode;          // Return new head
        }
        
        // Step 5: Insert at the end if x is greater than all elements
        else if (ptr == nullptr) {
            prev->next = newNode;    // Link last node to newNode
            newNode->prev = prev;    // Link newNode back to prev
            newNode->next = nullptr; // New end node has no next node
            return head;             // Return original head
        } 
        
        // Step 6: Insert in the middle
        else {
            newNode->next = ptr;    // Link newNode to current node (ptr)
            prev->next = newNode;   // Link previous node to newNode
            ptr->prev = newNode;    // Link current node back to newNode
            newNode->prev = prev;   // Link newNode back to previous node
            return head;            // Return original head
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = getNode(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }

        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); // Ignore the newline character after the value

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends