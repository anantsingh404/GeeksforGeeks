//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  long long  mg(vector<int>&arr, long long l, long long  r, long long mid)
{
    long long  arr1[r - l + 1];
    int k = 0;
    long long count = 0;
    int p = l;
    int q = mid + 1;

    for (int i = p; i <= r; i++)
    {
        if (p > mid)
        {
            arr1[k++] = arr[q++];
        }
        else if (q > r)
        {
            arr1[k++] = arr[p++];
        }
        else if (arr[p] <= arr[q])
        {
            arr1[k++] = arr[p++];
        }
        else
        {
            count += mid - p + 1;
            arr1[k++] = arr[q++];
        }
    }
    for (int p = 0; p < k; p++)
    {
        arr[l++] = arr1[p];
    }
    return count;
}

long long ms(vector<int>&arr, long long l, long long r)
{
    if (l < r)
    {
        long long x = 0, y = 0;
        long long mid = l + (r - l) / 2;
        x = ms(arr, l, mid);
        y = ms(arr, mid + 1, r);
        return x + y + mg(arr, l, r, mid);
    }
    return 0;
}
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        long long n=arr.size();
         long long x = 0;
    x = ms(arr, 0, n - 1);
    return (int)x;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends