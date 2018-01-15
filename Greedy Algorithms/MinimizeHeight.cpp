/* 
Problem : Given an array A[ ] denoting heights of N towers and a positive integer K,
modify the heights of each tower either by increasing or decreasing them by K only once 
and then find out the minimum difference of the heights of shortest and longest towers.
*/

int minimizeHeight(int a[], int n, int k) {
    sort(a, a+n);
    int smallest = a[0];
    int largest = a[n-1];
    int ans = largest - smallest;

    smallest += k;
    largest -= k;
    if(smallest > largest)
        swap(smallest, largest);

    for(int i=1; i<n-1; i++) {
        int add = a[i] + k;
        int sub = a[i] - k;

        if(sub >= smallest || add <= largest)
            continue;

        if(largest - sub <= add - smallest) {
            smallest = sub;
        }
        else
            largest = add; 
    }

    return min(ans, largest - smallest);
}