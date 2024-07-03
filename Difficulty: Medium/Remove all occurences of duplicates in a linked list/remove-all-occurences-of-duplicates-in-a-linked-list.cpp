//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
public:
    Node* removeAllDuplicates(struct Node* head) {
        // Handle the edge case where the list is empty or has a single node
        if (!head || !head->next) {
            return head;
        }

        // Remove leading duplicates if any
        while (head && head->next && head->data == head->next->data) {
            Node* temp = head;
            while (temp && temp->data == head->data) {
                temp = temp->next;
            }
            head = temp;
        }

        // Initialize pointers
        Node* curr = head;
        Node* prev = nullptr;

        while (curr && curr->next) {
            Node* forward = curr->next;
            if (curr->data != forward->data) {
                // Move prev and curr forward
                prev = curr;
                curr = forward;
            } else {
                // Skip all duplicates
                while (forward && curr->data == forward->data) {
                    forward = forward->next;
                }
                // Update prev's next pointer to skip duplicates
                if (prev) {
                    prev->next = forward;
                }
                // If prev is null, it means head has been moved, update head
                else {
                    head = forward;
                }
                // Move curr to forward
                curr = forward;
            }
        }
        return head;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends