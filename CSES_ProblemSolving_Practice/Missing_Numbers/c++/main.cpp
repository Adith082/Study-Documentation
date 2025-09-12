#include <bits/stdc++.h>

using namespace std;

int main(){

    long long int n, val;
    cin >> n;
    long long int sum = 0;
    for(int i = 1; i<=n; i++) sum ^= i;
    for(int i = 0;i<n-1;i++){
        cin >> val;
        sum ^= val;
    }
    cout << sum << endl;
    return 0;
}
