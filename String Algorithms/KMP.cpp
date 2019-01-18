/*-------------------------------------------------------------------
                            tenacious
-------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

int ind[MAX];

//preprocess patter string to know the index of the last part which
//both refix as well as suffix
void preprocessP(string p) {
    ind[0] = 0;
    int i = 1, j = 0;
    while(i < p.size()) {
        if(p[i] == p[j]) {
            ind[i] = j + 1;
            i++;
            j++;
        }
        else {
            if(j != 0) {
                j = ind[j-1];
            }
            else{
                ind[i] = 0;
                i++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string p, t;
    cin >> p >> t;

    preprocessP(p);

    int ans = 0;
    int i = 0, j = 0;
    bool flag = false;
    //method to look for total no. of patterns in a given string
    while(i<t.size()) {
        if(j == 0 && t[i] != p[j])
            i++;
        else {
            while(j<p.size() && t[i] == p[j]) {
                flag = true;
                i++;
                j++;
            }
            if(flag && j == p.size()) {
                ans++;
                j = ind[j-1];
                flag = false;
            }
            else {
                j = ind[j-1];
            }
        }
    }

    cout << ans;
    return 0;

}
