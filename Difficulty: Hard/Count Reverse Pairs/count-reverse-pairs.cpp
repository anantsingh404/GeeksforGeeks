class Solution {
  public:
  int n;
  long long int merge(vector<int>& arr, long long int l, long long int r, long long int m) {
    long long int inversions = 0;
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    long long int i = 0, j = 0, k = l;
    
    while (i < left.size() && j < right.size()) {
        if ((long long)left[i] > 2LL * (long long)right[j]) {
            inversions += (m - l + 1) - i;  // Count all elements in left since left is sorted
            j++;
        } else {
            i++;
        }
    }
    
    i = 0;
    j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left.size()) {
        arr[k++] = left[i++];
    }

    while (j < right.size()) {
        arr[k++] = right[j++];
    }

    return inversions;
}
long long int mergeSort(vector<int>& arr, long long int l, long long int r) {
    long long int inversions = 0;
    if (l < r) {
        long long int m = l + (r - l) / 2;
        inversions += mergeSort(arr, l, m);
        inversions += mergeSort(arr, m + 1, r);
        inversions += merge(arr, l, r, m);
    }
    return inversions;
}
    int countRevPairs(vector<int> &arr) {
        // Code here
        n=arr.size();
        long long int  x = 0;
    return (int)mergeSort(arr, 0, n - 1);
        
    }
};