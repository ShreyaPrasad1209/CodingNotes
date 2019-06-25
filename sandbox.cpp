int partition(vector<int> arr, int l, int r)
{
    int pivot = arr[r];
    int j = l-1;
    for (int i = l; i <= r-1; ++i)
        if (arr[i] <= pivot)
            swap(arr[++j], arr[i]);
    swap(arr[++j], arr[r]);
    return j;
}