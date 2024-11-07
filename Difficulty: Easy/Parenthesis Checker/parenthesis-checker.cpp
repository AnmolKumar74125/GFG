//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isParenthesisBalanced(string& s) {
        // code here
        stack<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty() || (s[i] == ']' && st.top() != '[') || (s[i] == '}' && st.top() != '{') || (s[i] == ')' && st.top() != '('))
                {
                    return false;
                }
                st.pop();
            }
        }
        if(st.size() == 0)
        {
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isParenthesisBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends