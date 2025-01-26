#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> numbers;
vector<int> operators(4);
    
int maxValue = -1000000000;
int minValue = 1000000000;

void dfs(int idx, int now){
    int next;
    if(idx == n){
        maxValue = max(maxValue, now);
        minValue = min(minValue, now);
        return;
    }
    
    for(int i=0; i<4; i++){
        if (operators[i]>0){
            operators[i]--;
            
            next = now;
            if(i==0){
                next += numbers[idx];
            }
            else if(i==1){
                next -= numbers[idx];
            }
            else if(i==2){
                next *= numbers[idx];
            }
            else if(i==3){
                next /= numbers[idx];
            }
            dfs(idx+1, next);
            operators[i]++;
        }
    }
}

int main(){
    cin >> n;
    numbers.resize(n);
    
    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }
    
    for(int i=0; i<4; i++){
        cin >> operators[i];
    }
    
    dfs(1, numbers[0]);
    
    cout << maxValue << '\n';
    cout << minValue;
}
