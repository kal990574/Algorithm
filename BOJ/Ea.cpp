#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

// 다이얼 상태를 문자열로 변환
string to_string(const vector<int>& dials) {
    string result;
    for (int dial : dials) result += char(dial + '0'); // 숫자를 문자로 변환
    return result;
}

// 다이얼 회전을 시뮬레이션
vector<int> rotate_dial(const vector<int>& dials, int index, int direction) {
    vector<int> new_dials = dials;
    for (size_t i = index; i < dials.size(); ++i)
        new_dials[i] = (new_dials[i] + direction + 10) % 10;
    return new_dials;
}

// 최소 이동 횟수 계산
int solution(vector<int> dials, const vector<int>& password) {
    queue<pair<vector<int>, int>> q; // 상태와 이동 횟수를 저장
    unordered_map<string, int> visited; // 상태와 최소 이동 횟수를 저장

    string start_state = to_string(dials);
    string target_state = to_string(password);

    q.push(make_pair(dials, 0)); // 초기 상태
    visited[start_state] = 0;

    while (!q.empty()) {
        pair<vector<int>, int> front = q.front();
        vector<int> current = front.first;
        int moves = front.second;
        q.pop();

        string current_state = to_string(current);
        if (current_state == target_state) return moves;

        for (size_t i = 0; i < dials.size(); ++i) {
            for (int dir = -1; dir <= 1; dir += 2) { // -1, 1
                vector<int> next = rotate_dial(current, i, dir);
                string next_state = to_string(next);

                // 상태가 방문되지 않았거나, 더 적은 이동으로 도달할 경우
                if (visited.find(next_state) == visited.end() || visited[next_state] > moves + 1) {
                    visited[next_state] = moves + 1;
                    q.push(make_pair(next, moves + 1));
                }
            }
        }
    }
    return -1; // 비밀번호를 찾지 못한 경우 (문제 조건상 없음)
}

int main() {
    vector<int> dials = {1, 5, 9, 3, 7};
    vector<int> password = {2, 5, 9, 3, 7};
    cout << solution(dials, password) << endl;
    return 0;
}
