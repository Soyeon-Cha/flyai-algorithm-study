#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, k;
    int cnt = 0;
    cin >> n >> k;
    
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for (int i=n-1; i>=0; i--){
        if(k>=arr[i]){
            cnt += k/arr[i];
            k %= arr[i];
        }
    }
    cout << cnt;
}
