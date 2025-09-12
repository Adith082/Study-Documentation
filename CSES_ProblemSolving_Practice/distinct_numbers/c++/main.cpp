#include <bits/stdc++.h>

using namespace std;

int main(){

    long long int n, val;
    cin >> n;
    set<long long int> ss;
    for(int i = 0;i<n;i++) {
        cin >> val;
        ss.insert(val);
    }
    cout << ss.size() << endl;
    return 0;
}
