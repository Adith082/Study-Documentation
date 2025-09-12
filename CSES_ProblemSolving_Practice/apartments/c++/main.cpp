#include <bits/stdc++.h>

using namespace std;

int main(){

 long long int i,j,t,n,m,k;

 cin >> n >> m >> k;

 long long int apartment[m];
 long long int applicant[n];

 for(int i = 0;i<n;i++) cin >> applicant[i];

 for(int i = 0;i<m;i++) cin >> apartment[i];

 sort(applicant, applicant + n);
 sort(apartment, apartment + m);

 long long int res = 0;

 i = 0;
 j = 0;
 while((i<n) && (j<m)) {

     long long int min_consideration = applicant[i] - k;
     long long int max_consideration = applicant[i] + k;

     if((apartment[j] < min_consideration)) {
         j++;
     }  else if((apartment[j] > max_consideration)) {
         i++;
     }  else{
         res++;
         i++;
         j++;
     }

 }       cout << res << endl;


return 0;
}
