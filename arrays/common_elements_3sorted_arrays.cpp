/* Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure? */

// Approach 1 using O(n1+n2+n3) space
// simply create three unordered map and insert all 3 array elemenents in map
// iterate through one array and check if element is present in all the three maps
// if it is so then push it in vector



#include <bits/stdc++.h>
        using namespace std;

  
    class Solution
    {
    public:
        vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> result;

            unordered_map<int, int> m1, m2, m3;

            for (int i = 0; i < n1; i++)
            {
                m1[A[i]]++;
            }

            for (int i = 0; i < n2; i++)
            {
                m2[B[i]]++;
            }

            for (int i = 0; i < n3; i++)
            {
                m3[C[i]]++;
            }

            for (int i = 0; i < n1; i++)
            {
                if (m1[A[i]] && m2[A[i]] && m3[A[i]])
                {
                    result.push_back(A[i]);

                    m1[A[i]] = 0; // to handle duplicates 
                }
            }

            return result;
        }
    };

  

    int main()
    {
        int t;
        cin >> t;
        while (t--)
        {
            int n1, n2, n3;
            cin >> n1 >> n2 >> n3;
            int A[n1];
            int B[n2];
            int C[n3];

            for (int i = 0; i < n1; i++)
                cin >> A[i];
            for (int i = 0; i < n2; i++)
                cin >> B[i];
            for (int i = 0; i < n3; i++)
                cin >> C[i];

            Solution ob;

            vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);
            if (res.size() == 0)
                cout << -1;
            for (int i = 0; i < res.size(); i++)
                cout << res[i] << " ";
            cout << endl;
        }
    }

    //Approach 2 using O(1) space

public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        int i = 0, j = 0, k = 0;

        vector<int> res;
        int last = INT_MIN;
        while (i < n1 and j < n2 and k < n3)
        {
            if (A[i] == B[j] and A[i] == C[k] and A[i] != last)
            {
                res.push_back(A[i]);
                last = A[i]; // handling duplicates
                i++;
                j++;
                k++;
            }
            else if (min({A[i], B[j], C[k]}) == A[i])
                i++;
            else if (min({A[i], B[j], C[k]}) == B[j])
                j++;
            else
                k++;
        }
        return res;
    }
    };