//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head)
    {
        if(head==NULL||head->next==NULL)
        return head;
        else
        {
            Node* ptr=reverse(head->next);
            (head->next)->next=head;
            head->next=NULL;
            return ptr;
        }
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
       Node* nh=reverse(head);
       Node* curr=nh;
       nh->data=nh->data+1;
       int carry=0;
       if(nh->data>=10)
       {
            while(curr->next!=NULL)
            {
              curr->data=curr->data+carry;
              carry=curr->data/10;
              curr->data=curr->data%10;
              curr =curr->next;
            }
            if(carry)
          {
              curr->data=curr->data+carry;
          }
       }
         head=reverse(nh);
                return head;
    
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends