//Naive Solution : Time complexity O(n^2)

void heapsort(int arr[], int n) {
    buildheap(arr, n);
    for(int i=n-1; i>=0; i--) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

void buildheap(int arr[], int n) {
    int s = (n-1)/2;
    int sw;
    for(int i=s; i>=0; i--) {
        if(2*i+2 < n) {
            if(arr[2*i+2] > arr[2*i+1])
                sw = 2*i+2;
            else
                sw = 2*i+1;
            
            if(arr[i] < arr[sw])
                swap(arr[i], arr[sw]);
        }
        else if(2*i+1 < n) {
            if(arr[i] < arr[2*i+1])
                swap(arr[i], arr[2*i+1]);
        }
    }
}

void heapify(int arr[], int n, int i) {
    int s = (n-1)/2;
    int sw;
    for(int i=s; i>=0; i--) {
        if(2*i+2 < n) {
            if(arr[2*i+2] > arr[2*i+1])
                sw = 2*i+2;
            else
                sw = 2*i+1;
            
            if(arr[i] < arr[sw])
                swap(arr[i], arr[sw]);
        }
        else if(2*i+1 < n) {
            if(arr[i] < arr[2*i+1])
                swap(arr[i], arr[2*i+1]);
        }
    }
}

//heapify will again make use of buildheap and heance will give a solution with complexity O(n^2), rather the maxheap
//structure can be exploited to obtain a solution of complexity O(nlogn);

//Optimal Solution : Time Complexity O(nlogn)
void heapsort(int arr[], int n) {
    buildheap(arr, n);
    for(int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void buildheap(int arr[], int n) {
    int s = (n-1)/2;
    for (int i = s; i >= 0; i--)
        heapify(arr, n, i);
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l < n && arr[largest] < arr[l])
        largest = l;
    if(r < n && arr[largest] < arr[r])
        largest = r;
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
} 