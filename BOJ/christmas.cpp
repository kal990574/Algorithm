#include <iostream>
using namespace std;

void drawChristmasTree(int height) {
    // 트리 상단
    for (int i = 1; i <= height; ++i) {
        // 공백 출력
        for (int j = 1; j <= height - i; ++j) {
            cout << " ";
        }
        // 별 출력
        for (int k = 1; k <= (2 * i - 1); ++k) {
            cout << "*";
        }
        cout << endl;
    }

    // 트리 밑단 (줄기)
    for (int i = 1; i <= height / 3; ++i) {
        for (int j = 1; j < height; ++j) {
            cout << " ";
        }
        cout << "|||" << endl; // 줄기 부분
    }
}

int main() {
    int height;
    cout << "크리스마스 트리의 높이를 입력하세요: ";
    cin >> height;

    if (height < 3) {
        cout << "트리의 높이는 최소 3 이상이어야 합니다." << endl;
    } else {
        drawChristmasTree(height);
    }

    return 0;
}
