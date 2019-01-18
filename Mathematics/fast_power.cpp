/*------------------------------------------------------------------------
                                tenacious								
------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

long long fast_power(int base, int exponent) {
    long long result = 1;
    while(exponent > 0) {
        if(exponent % 2 == 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


}