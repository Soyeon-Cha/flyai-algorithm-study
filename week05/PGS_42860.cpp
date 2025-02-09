#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int n = name.size();
    int answer = 0;
    int min_val = n - 1;
    
    for (int i = 0; i < n; i++) {
        // 위/아래 최소 이동 횟수
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        // 왼쪽/오른쪽 최소 이동 횟수
        int next = i + 1;
        while (next < n && name[next] == 'A') {
            next++;
        }
        
        min_val = min({
            min_val,
            i + i + (n - next),
            (n - next) + (n - next) + i
        });
    }
    
    answer += min_val;
    return answer;
}
