//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        //printList(head);
        int count = 0;
        Node* temp = head;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        if(count == 0 || count == 1)
        {
            return true;
        }
        if(count == 2)
        {
            return (head->data == head->next->data) ? true : false;
        }
        temp = head;
        Node* midPoint = head;
        int m = ceil(count/2.0);
        while(m > 0)
        {
            midPoint = midPoint->next;
            m--;
        }
        midPoint = reverse(midPoint);
        //printList(midPoint);
        while(temp != NULL && midPoint != NULL)
        {
            if(temp->data != midPoint->data)
            {
                return false;
            }
            temp = temp->next;
            midPoint = midPoint->next;
        }
        return true;   
    }
    void printList(Node* head)
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }
    Node* reverse(Node *head)
    {
        Node* temp = head;
        while(temp != NULL && temp->next != NULL)
        {
            Node* temp2 = temp->next;
            temp->next = temp2->next;
            temp2 -> next = head;
            head = temp2;
            //printList(head);
        }
        return head;
    }
};


//.  375 961 677 596 1 1 596 677 961 375

//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
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
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends