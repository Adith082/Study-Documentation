
#include <bits/stdc++.h>

using namespace std;

int main(){

    long long int i,j,t,n,x, temp, res;
    cin >> n >> x;
    long long int a[n];
    for(int i = 0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    i = 0;
    j = n-1;
    temp = 0;
    res = 0;
    while(i<=j) {
        if((a[i] + a[j]) <= x) {
            i++;
            j--;
            res++;
        }   else{
            res++;
            j--;
        }
    }       cout << res << endl;
    return 0;
}
