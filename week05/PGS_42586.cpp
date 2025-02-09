#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    
    // 각 작업을 완료하기까지 걸리는 일 수
    for (int i=0; i<progresses.size(); i++) {
        int day = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
        days.push(day);
    }
    
    while (!days.empty()) {
        int deploy = days.front();
        days.pop();
        int count = 1;
        
        // 함께 배포할 기능이 있는 경우 개수 추가
        while (!days.empty() && days.front() <= deploy) {
            count++;
            days.pop();
        }
        answer.push_back(count);
    }
    return answer;
}
