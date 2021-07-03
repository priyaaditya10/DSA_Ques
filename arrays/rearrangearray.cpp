
class Solution
{
public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n)
    {

        int min_index = 0, max_index = n - 1;
        int max_element = arr[n - 1] + 1;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                // learn this formula to solve this problem
                //https://www.youtube.com/watch?v=ZRoVWxBngX0 
                // refer to this link
                arr[i] = arr[i] + (arr[max_index] % max_element) * max_element;
                max_index--;
            }

            else
            {
                arr[i] = arr[i] + (arr[min_index] % max_element) * max_element;
                min_index++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] / max_element;
        }
    }
};

// { Driver Code Starts.

// Driver program to test above function
int main()
{
    int t;

    //testcases
    cin >> t;

    while (t--)
    {

        //size of array
        int n;
        cin >> n;

        long long arr[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;

        //calling rearrange() function
        ob.rearrange(arr, n);

        //printing the elements
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends