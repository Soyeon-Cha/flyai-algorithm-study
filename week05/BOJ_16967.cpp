#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> b(h+x, vector<int>(w+y));
        
    for (int i=0; i<h+x; i++){
        for (int j=0; j<w+y; j++){
            cin >> b[i][j];
        }
    }
    
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if (i>=x && j>=y){
                a[i][j] = b[i][j] - a[i-x][j-y];
            }
            else{
                a[i][j] = b[i][j];
            }
        }
    }
    
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            cout << a[i][j] << " ";
        }
    }
}
