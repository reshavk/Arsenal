/*------------------------------------------------------------------------
                                tenacious								
------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

int euclidean_gcd(int a, int b) {
    if(b == 0)
        return a;
    else {
        euclidean_gcd(b, a%b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


}