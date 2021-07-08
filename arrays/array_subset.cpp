/* Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. 
Task is to check whether a2[] is a subset of a1[] or not. 
Both the arrays can be sorted or unsorted.
 It may be assumed that elements in both array are distinct.*/

 // method 1


#include <bits/stdc++.h>
        using namespace std;

    string isSubset(int a1[], int a2[], int n, int m);

    int main()
    {
        int t;
        cin >> t;

        while (t--)
        {
            int n, m;
            cin >> n >> m;
            int a1[n], a2[m];

            for (int i = 0; i < n; i++)
            {
                cin >> a1[i];
            }
            for (int i = 0; i < m; i++)
            {
                cin >> a2[i];
            }

            cout << isSubset(a1, a2, n, m) << endl;
        }
        return 0;
    }
   

    string isSubset(int a1[], int a2[], int n, int m)
    {
        string res;

        set<int> s;
        int flag = 1;

        for (int i = 0; i < n; i++)
        {
            s.insert(a1[i]);
        }

        for (int i = 0; i < m; i++)
        {
            if (s.find(a2[i]) == s.end())
            {
                flag = 0;
            }
        }

        if (flag == 1)
        {
            return "Yes";
        }
        else
        {
            return "No";
        }
    }



// Method 2

// approach is to create an unordered map um and store values of 1st array in map
// now initialize a count variable to 0
// now iterate through a2 from 0 to m
// and check if map contains a2[i] if it is true then increment the counter by 1
// outside of loop check if count==m (means no. of elements of a2 present in map is equal to size of second array)
// the return yes else no

    string isSubset(int a1[], int a2[], int n, int m)
    {

        unordered_map<int, int> um;

        for (int i = 0; i < n; i++)
        {
            um[a1[i]]++;
        }

        int count = 0;
        for (int i = 0; i < m; i++)
        {
            if (um[a2[i]])
            {
                count++;
            }
        }

        if (count == m)
            return "Yes";
        else
            return "No";
    }
