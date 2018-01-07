//Problem : Longest contigous sum sequence (Maximum sum subarray) 

int kadane(int a[], int n) {
    int max_so_far = a[0];
    int curr_max = a[0];
    
    for(int i=1; i<n; i++) {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}
