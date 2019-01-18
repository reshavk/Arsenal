/*-------------------------------------------------------------------
                            tenacious
-------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 7;
int arr[MAX];

//initialize arr[i] with i, arr[i] stores index of the root or parent
//of that disjoint set
void initialize(int n) {
    for(int i=1; i<=n; i++) {
        arr[i] = i;
    }
}

//function to get root/parent for any node
//uses square root description methodology
int root(int i) {
    while(arr[i] != i) {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

//function to make pair of two elements by adding an element to a disjoint set
//the predicate used for set formation here is that node with largest no. should be root
void makepair(int a, int b) {
    int root_a = root(a);
    int root_b = root(b);

    if(root_a > root_b) {
        arr[root_b] = root_a;
    }
    else {
        arr[root_a] = root_b;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    initialize(n);
    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        makepair(a, b);
    }

    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        cin >> a >> b;
        if(root(a) > root(b)) {
            cout << a << "\n";
        }
        else if(root(b) > root(a)) {
            cout << b << "\n";
        }
        else{
            cout << "TIE\n";
        }
    }

    return 0;
}
