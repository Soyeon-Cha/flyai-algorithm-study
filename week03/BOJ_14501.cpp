#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> t(n+1);
    vector<int> p(n+1);
    vector<int> d(n+2, 0);

    for(int i=1; i<=n; i++){
        cin >> t[i] >> p[i];
    }

    for(int i=n; i>0; i--) {
        if (i+t[i] <= (n+1)) {
            d[i] = max(d[i+1], p[i] + d[i+t[i]]);
        }
        else {
            d[i] = d[i+1];
        }
    }
    cout << d[1];
}
