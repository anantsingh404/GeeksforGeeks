class Solution {
  public:
    long long merge(vector<int>& arr, int l, int mid, int r)
{
    long long count = 0;

    // count inversions using upper_bound
    int i = mid + 1;
    while (i <= r)
    {
        int x = upper_bound(arr.begin() + l,
                            arr.begin() + mid + 1,
                            arr[i]) - arr.begin();

        count += (mid + 1 - x);
        i++;
    }

    // normal merge (NO inversion counting here)
    vector<int> temp(r - l + 1);
    int p = l;
    int q = mid + 1;
    int k = 0;

    while (p <= mid && q <= r)
    {
        if (arr[p] <= arr[q])
        {
            temp[k++] = arr[p++];
        }
        else
        {
            temp[k++] = arr[q++];
        }
    }

    while (p <= mid)
    {
        temp[k++] = arr[p++];
    }

    while (q <= r)
    {
        temp[k++] = arr[q++];
    }

    int idx = 0;
    while (idx < k)
    {
        arr[l + idx] = temp[idx];
        idx++;
    }

    return count;
}

long long part(vector<int>& arr, int low, int high)
{
    if (low >= high)
    {
        return 0;
    }

    int mid = low + (high - low) / 2;

    long long left = part(arr, low, mid);
    long long right = part(arr, mid + 1, high);
    long long cross = merge(arr, low, mid, high);

    return left + right + cross;
}
    int inversionCount(vector<int> &arr) {
        // Code Here
        
          return part(arr, 0, arr.size() - 1);
    }
};