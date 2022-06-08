class Solution {
public:
long long merge(vector<int>& arr, long long l, long long mid, long long r)
{
    long long inv = 0;
    long long n1 = mid - l + 1;
    long long n2 = r - mid;
    long long a[n1];
    long long b[n2];
    for (long long i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }

    for (long long i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
 int j1 = mid + 1;

     for (int i = l; i <= mid; i++) {
    while (j1 <= r && arr[i] > 2  * (long long)arr[j1]) {
      j1++;
    }
    inv += (j1 - (mid + 1));
  }   
    long long i = 0, j = 0, k = l;
    while (i < n1 and j < n2)
    {     
        
       
        if (a[i] <=  b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
           
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
    return inv;
}

long long mergesort(long long l, long long r, vector<int>& arr)
{
    long long inv = 0;
    long long mid = (l + r) / 2;

    if (l < r)
    {
        inv += mergesort(l, mid, arr);
        inv += mergesort(mid + 1, r, arr);
        inv += merge(arr, l, mid, r);
    }

    return inv;
}

 int reversePairs(vector<int>& nums) {
     int n=nums.size();
        return mergesort(0,n-1,nums);
    }
};