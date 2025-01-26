#include <bits/stdc++.h>
using namespace std;

int n, m;
int r, c, d;
vector<vector<int>> room;
vector<vector<bool>> visited;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int turnLeft(int d){
    return (d+3) % 4;
}

int cleanUp(){
    int cnt = 0;
    
    while(true){
        if(!visited[r][c]){
            visited[r][c] = true;
            cnt ++;
        }
        
        bool notCleaned = false;
        int nx, ny;
        
        for(int i=0; i<4; i++){
            d = turnLeft(d);
            nx = r + dx[d];
            ny = c + dy[d];
            
            if(!visited[nx][ny] && room[nx][ny]==0){
                r = nx;
                c = ny;
                notCleaned = true;
                break;
            }
        }
        
        int back;
        int bx, by;
        
        if(!notCleaned){
            // 뒤로 가는 방향
            back = (d + 2) % 4;
            bx = r + dx[back];
            by = c + dy[back];
            
            if(room[bx][by]==1){
                break;
            }
            else{
                r = bx;
                c = by;
            }
        }
    }
    return cnt;
}

int main(){
    cin >> n >> m;
    cin >> r >> c >> d;
    
    room.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> room[i][j];
        }
    }
    
    cout << cleanUp();
}
