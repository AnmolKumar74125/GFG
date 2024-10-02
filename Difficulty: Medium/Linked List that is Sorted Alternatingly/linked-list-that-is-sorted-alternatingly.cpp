//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sort(Node* head) {
        // Code here
        
        Node* temp = head;
        while( temp != NULL && temp->next != NULL)
        {
            temp = temp -> next;
        }
        Node* head2 = temp;
        temp = head;
        Node* temp2 = head2->next;
        while(temp != head2 && temp != NULL && temp->next !=NULL && temp->next !=head2 )
        {
            Node* startTemp = temp->next;
            temp->next = startTemp->next;
            Node* endTemp = head2->next;
            head2->next = startTemp;
            startTemp->next = endTemp;
            temp = temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
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
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }
        }

        Solution ob;
        Node* newHead = ob.sort(head);
        printList(newHead);
        freeList(newHead);
    }

    return 0;
}

// } Driver Code Ends