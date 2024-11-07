//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        // Your code here
        int arr[26] = {};
        for(int i = 0; i < 26; i++)
        {
           // cout << arr[i] << "  ";
        }
        //cout << endl;
        for(int i = 0; i < str.size(); i++)
        {
            //cout << i << "  " << patt.find(str[i]) << endl;
            if((arr[(int)str[i] - 97] == 0) && (patt.find(str[i]) != string::npos))
            {
                return i;
            }
            arr[(int)str[i] - 97]++;
            //cout << arr[]
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends