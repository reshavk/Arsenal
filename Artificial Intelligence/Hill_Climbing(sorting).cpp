#include<bits/stdc++.h>
using namespace std;

int calculateCost(int arr[], int N) {
    int cost = 0;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            if(arr[j] < arr[i])
                cost++;
        }
    }
    return cost;
}

void doSwap(int arr[], int i, int j) {
    swap(arr[i], arr[j]);
}

int main() {
    cout << "Enter the size of array : ";
    int N;
    cin >> N;

    cout << "Enter array : \n";
    int arr[N];
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    int bestcost, newcost, nswaps = 0;
    
    bestcost = calculateCost(arr, N);

    while(bestcost > 0) {
        for(int i=0; i<N-1; i++) {
            doSwap(arr, i, i+1);
            newcost = calculateCost(arr, N);
            if(bestcost > newcost) {
                cout << "After swap " << nswaps++ << " : \n";
                for(int i=0; i<N; i++) {
                    cout << arr[i] << " ";
                }
                cout << "\n";
                bestcost = newcost;
            }
            else {
                doSwap(arr, i, i+1);
            }
        }
    }

    cout << "Final state of array : \n";
    for(int i=0; i<N; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}