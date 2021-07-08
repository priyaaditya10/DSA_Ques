/*Given an array arr[] of size N and an element k.
 The task is to find all elements in array that appear more than n/k times. */

// A C++ program to print elements with count more than n/k 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Approach is very simple create an unordered_map m and then store all array elements with their frequency in map
// now create an iterator itr of map m
// iterate through all map elements with itr
// check if itr->second > n/k ( as itr->second will contain frequency of each element in array)
// if this is true then increment the counter
// return counter outside loop


class Solution
{
public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k)
    {
        int res = 0;
        int check = n / k;
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }

        unordered_map<int, int>::iterator itr;

        for (itr = m.begin(); itr != m.end(); itr++)
        {
            if (itr->second > check)
            {
                res++;
            }
        }

        return res;
    }
};


int main()
{
    int t, k;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}
