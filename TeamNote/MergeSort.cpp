struct MergeSort {
    ll arr[MAX], temp[MAX];
    ll mergeSort(int n=MAX) {   // return inversion count
        return divide(0, n-1);
    }
    ll divide(int left, int right) {
        ll inv_count = 0;
        int mid;
        if (right > left) {
            mid = (right + left) / 2;
            inv_count += divide(left, mid);
            inv_count += divide(mid+1, right);
            inv_count += merge(left, mid+1, right);
        }
        return inv_count;
    }
    ll merge(int left, int mid, int right) {
        ll inv_count = 0;
        int i = left, j = mid, k = left;
        while ((i <= mid-1) && (j <= right)) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
                inv_count = inv_count + (mid - i);
            }
        }
        while (i <= mid-1) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];

        for (i = left; i <= right; i++) arr[i] = temp[i];
        return inv_count;
    }
} MS;