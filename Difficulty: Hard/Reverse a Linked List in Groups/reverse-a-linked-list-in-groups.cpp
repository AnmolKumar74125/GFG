//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/*
   // Redirecting input from file
  freopen("/Users/debojyoti.mandal/expt/input.txt", "r", stdin);

  // Redirecting output to file
  freopen("/Users/debojyoti.mandal/expt/output.txt", "w", stdout);
*/

struct node {
    int data;
    struct node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    struct node *reverseIt(struct node *head, int k) {
        // Complete this method
        int i = 0, x = 0, n = 0;
        struct node *temp = head;
        struct node *currHead = head;
        struct node *last = head;
        if(k == 1)
        {
            return head;
        }
        /*
        while(temp != NULL)
        {
            n++;
            temp = temp -> next;
            cout<<"count";
        }
        */
        //printList(head);
        while(temp!=NULL && temp->next !=NULL)
        {
            x = 0;
 /*           if(i<=k)
            head = currHead;
            //last = temp;*/
            currHead = temp;
            //temp =temp -> next;
            //last->next = currHead;
            //else
            //last->next = currHead;
            while(x < k-1 && temp != NULL && temp->next != NULL)
            {
                struct node* temp2 = temp -> next;
                temp -> next = temp2 -> next;
                temp2 -> next = currHead;
                //temp = currHead;
                currHead = temp2;
                //last->next = currHead;
               // cout<<x<<endl;
                x++;
                i++;
                //temp = temp->next;
                //last = temp;
                //printList(currHead);
                
            }
/*            last->next =temp->next;
            if(temp != NULL)
            {
                last = temp;
               // last -> next =currHead;
               cout << "last = " <<last->data<<endl;
                temp = temp->next;
            }
            if(temp != NULL)
            cout<<"A= "<<temp->data<<endl;
*/            
            //i+=x;
           // cout<< i;
            if(i < k)
            {
                head = currHead;
            }
            else
            {
                //last->next = temp->next;
                last->next = currHead;
                last = temp;
            }
            temp = temp->next;
            //last = temp;
            //printList(currHead);
            //printList(temp);
        }
        return head;
    }
    void printList(struct node* head)
    {
        struct node* temp = head;
        while(temp != NULL)
        {
            //cout << temp->data <<" ";
            temp = temp->next;
            //cout<<"print";
        }
        //cout << endl;
    }
    node* reverse(struct node *head, int k)
    {
        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        node* head = new node(data);
        node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return (0);
}

// } Driver Code Ends