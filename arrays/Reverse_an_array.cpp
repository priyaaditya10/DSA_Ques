// Reverse an array
//point start=0 and end = n-1 and then just swap a[start] with a[end] increement start pointer and decrement end pointer 
//till start<end
#include <iostream>
using namespace std;

void reverse(int A[], int start, int end)
{
   int temp=0;
   
   while(start<end)
   {
       temp=A[start];
       A[start]=A[end];
       A[end]=temp;
       start++;
       end--;
   }
    
    
}

void print_array(int A[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
}

 int main() {
// T= no. of test cases
// N= size of array
    int T;
    cin>>T;
 
   while(T--)
   {
       int N;
       cin>>N;
       int A[N];
       
        for(int j=0; j<N; j++)
        {
            cin>>A[j];
        }
    
    int start=0, end=N-1;
    reverse(A,start,end);
    
    print_array(A,N);
    
    cout<<endl;
   }

       
       
        
       
	return 0;
}