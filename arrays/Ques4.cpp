// program to sort an array of 0's 1's and 2's without using any sorting algo
/
{
    Driver Code Starts
    //Initial Template for C

#include <stdio.h>

        // } Driver Code Ends
        //User function Template for C

// use the simple approach count 0's , 1's and 2's in different counter variable and set i=0 and 
// then insert 0's ,1's and 2's in array using loop till all the three counters become 0
        void sort012(int a[], int n)
    { 
        int count0 = 0, count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++)
        {
            switch (a[i])
            {
            case 0:
                count0++;
                break;
            case 1:
                count1++;
                break;
            case 2:
                count2++;
                break;
            }
        }

        int i = 0;

        while (count0 > 0)
        {
            a[i++] = 0;
            count0--;
        }

        while (count1 > 0)
        {
            a[i++] = 1;
            count1--;
        }

        while (count2 > 0)
        {
            a[i++] = 2;
            count2--;
        }
    }

    // { Driver Code Starts.

    int main()
    {

        int t;
        scanf("%d", &t);

        while (t--)
        {
            int n;
            scanf("%d", &n);
            int arr[n];
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            sort012(arr, n);

            for (int i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }
        return 0;
    }
    // } Driver Code Ends