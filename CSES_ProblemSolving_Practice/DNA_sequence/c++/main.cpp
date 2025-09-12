#include <bits/stdc++.h>

using namespace std;

int main(){

    long long int n, res = 0, diff;

    cin >> n;

    long long int a[n];

    for(int i = 0;i<n;i++) cin >> a[i];

    for(int i = 1; i<n; i++){
        diff = a[i] - a[i-1];
        if(diff < 0) {
            res += abs(diff);
            a[i] = a[i] + abs(diff);
        }
    }   cout << res << endl;
}
