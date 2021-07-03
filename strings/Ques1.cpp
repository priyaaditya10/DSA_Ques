// { Driver Code Starts
//Initial Template for C++

// program to reverse a string
#include <bits/stdc++.h>
using namespace std;

string reverseWord(string str);

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << reverseWord(s) << endl;
    }
    return 0;
}

// } Driver Code Ends

//User function Template for C++

string reverseWord(string str)
{

    int len = str.length();
    int start = 0, end = len - 1;
    if (len == 0)
        return "";
    while (start < end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }

    return str;
}