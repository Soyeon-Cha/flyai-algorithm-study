#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
    
    sort(p.begin(), p.end());

    int time = 0;
    int result = 0;
    for (int i=0; i<n; i++){
        time += p[i];
        result += time;
    }
    cout << result;
}
