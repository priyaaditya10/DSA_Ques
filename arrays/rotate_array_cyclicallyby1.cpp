// program to rotate an array cyclically by 1
// approach is to store last element of array in a variable say last=arr[n-1]
// now traverse from n-1 th element of array to 1 st element and 
// inside loop transfer i-1 th element to i th element
// and then outside of loop set arr[0]=last

//Initial Template for C++

#include <stdio.h>

void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n], i;
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}


//User function Template for C++

void rotate(int arr[], int n)
{
    int last = arr[n - 1];

    for (int i = n - 1; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = last;
}