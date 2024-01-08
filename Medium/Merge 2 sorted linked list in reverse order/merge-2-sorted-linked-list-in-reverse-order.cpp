//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* previous = NULL;   
        Node* current = head;  
     
        while (current != NULL)
        {
            
            Node* next = current->next;
            current->next = previous;    
     
            previous = current;
            current = next;
        }
     
        head = previous;
        return head;
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        node1=reverse(node1);
        node2=reverse(node2);
        
        Node* head=NULL;
        Node* tail=NULL;
        
        while(node1 and node2)
        {
            if(node1->data>node2->data)
            {
                if(!head)
                {
                    head=node1;
                    tail=node1;
                }
                else
                {
                    tail->next=node1;
                    tail=node1;
                }
                node1=node1->next;
            }
            else
            {
                if(!head)
                {
                    head=node2;
                    tail=node2;
                }
                else
                {
                    tail->next=node2;
                    tail=node2;
                }
                node2=node2->next;
            }
        }
        
        while(node1)
        {
            if(!head)
            {
                head=node1;
                tail=node1;
            }
            else
            {
                tail->next=node1;
                tail=node1;
            }
            node1=node1->next;
        }
        
        while(node2)
        {
            if(!head)
            {
                head=node2;
                tail=node2;
            }
            else
            {
                tail->next=node2;
                tail=node2;
            }
            node2=node2->next;
        }
        
        return head;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends