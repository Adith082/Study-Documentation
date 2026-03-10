#include <bits/stdc++.h>

using namespace std;

int main(){

    long long int n, m, k, i, j, minn_size, maxx_size;

    cin >> n >> m >> k;

    long long int customer_desired_size[n];

    long long int apartment_size[m];

    for(int i = 0;i<n;i++) cin >> customer_desired_size[i];

    for(int i = 0;i<m;i++) cin >> apartment_size[i];

    sort(apartment_size, apartment_size + m);

    sort(customer_desired_size, customer_desired_size + n);

    i = 0;
    j = 0;

    int res = 0;
    int len = min(n, m);

    while((i<n) && (j<m)) {

        minn_size = customer_desired_size[i] - min(k, customer_desired_size[i]);
        maxx_size = customer_desired_size[i] + k;
     //   cout << "maxx_size  " << maxx_size << "  minn_size " << minn_size << "  apartment_size " << apartment_size[j] << "  customer_desired_size  " << customer_desired_size[i] << endl;
        if((apartment_size[j] >= minn_size) && (apartment_size[j] <= maxx_size)) {
            res++;
            i++;
            j++;
        }   else if(apartment_size[j] < minn_size){
            j++;
        }   else {
            i++;
        }
       // cout << "res " << res << endl;
    }

    cout << res << endl;

    return 0;
}
