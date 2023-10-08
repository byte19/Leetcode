//{ Driver Code Starts
//

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
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
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

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        Node* newNode = new Node(data);
        
        if(!head) return newNode;
        if(!head->next) {
            if(head->data >= newNode->data) {
                newNode->next = head;
                head = newNode;
            }
            else head->next = newNode;
            return head;
        }
        
        if(head->data >= newNode->data) {
            newNode->next = head;
            head = newNode;
            return head;
        }
        Node* t1 = head;
        Node* t2 = head->next;
        bool notInserted = false;
        while(t2) {
            if((t2->data >= data) && (!notInserted)) {
                newNode->next = t1->next;
                t1->next = newNode;
                notInserted = true;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        if(!notInserted) t1->next = newNode;
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
		int n;
		cin>>n;
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends