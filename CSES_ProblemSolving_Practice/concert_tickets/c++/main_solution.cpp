#include <bits/stdc++.h>

using namespace std;


long long int leverage_binary_search(long long int ticket_price[], long long int n, long long int val) {

    long long int l = -1;

    long long int r = n;

    while((r-l)>1) {

        long long int mid = (l + r)/2;

        if(ticket_price[mid] <= val) {
            l = mid;
        }   else{
            r = mid;
        }
    }

    return l;
}

long long int find_parent(long long int parent[], long long int index) {

    if(index < 0) return -1;

    if(parent[index] == index) return parent[index];

    return parent[index] = find_parent(parent, parent[index]);

}

int main(){


    long long int i,j,t,n,m;

    cin >> n >> m;

    long long int ticket_price[n];

    long long int customer_max_price[m];

    long long int parent[n];

    for(int i = 0;i<n;i++) {
        cin >> ticket_price[i];
        parent[i] = i;
    }

    for(int i = 0;i<m;i++) cin >> customer_max_price[i];

    sort(ticket_price, ticket_price + n);

    for(int i = 0;i<m; i++) {

        long long int nearest_price_index = leverage_binary_search(ticket_price, n, customer_max_price[i]);

        if(nearest_price_index == -1) cout << -1 << endl;
        else {

             long long int new_nearest_price_index = find_parent(parent, nearest_price_index);
             if(new_nearest_price_index == -1) cout << -1 << endl;
             else {
                 cout << ticket_price[new_nearest_price_index] << endl;
                 parent[new_nearest_price_index] = find_parent(parent, new_nearest_price_index - 1); // union with left neighbor
             }

        }
    }

    return 0;
}




