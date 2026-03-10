#include <bits/stdc++.h>

using namespace std;

int main(){

    set <int> ss;

    int n, val;

    cin >> n;

    for(int i = 0;i<n;i++) {

        cin >> val;

        ss.insert(val);
    }

    cout << ss.size() << endl;



    return 0;
}
