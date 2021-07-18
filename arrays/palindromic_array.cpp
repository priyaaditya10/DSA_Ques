/* Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. 
Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.
 
Example:
Input:
2
5
111 222 333 444 555
3
121 131 20

Output:
1
0

Explanation:
For First test case.
n=5;
A[0] = 111    //which is a palindrome number.
A[1] = 222   //which is a palindrome number.
A[2] = 333   //which is a palindrome number.
A[3] = 444  //which is a palindrome number.
A[4] = 555  //which is a palindrome number.
As all numbers are palindrome so This will return 1.
 
*/


#include <iostream>
#include <string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << PalinArray(a, n) << endl;
    }
} 

// approach is to iterate through every array elements
// store ith element in temp
// calculate its reverse in while loop
// outside os while loop check if ans( will contain reverse of ith element) is not equal to a[i]
// the return 0
// otherwise outside of loop return 1

/*Complete the function below*/
int PalinArray(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int temp = a[i];

        int ans = 0;
        

        // to calculate reverse of a[i]
        while (temp > 0)
        {
            int r = temp % 10; // store remainder in r
            temp = temp / 10; 

            ans = ans * 10 + r; // will contain reverse of number in a[i]
        }

        if (ans != a[i])
        {
            return 0;
        }
    }

    return 1;
}