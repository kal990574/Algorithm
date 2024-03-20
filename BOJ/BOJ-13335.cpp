#include <iostream>
#include <queue>
using namespace std;

int n, w, L, val;
int arr[1000];
int sum;
queue<int> q; // 무게
int cnt = 1;
int idx = 1;

void traverse()
{
    while (idx < n)
    {
        cnt++;
        // 퇴출
        sum -= q.front();
        q.pop();

        if (sum + arr[idx] <= L) // 들어올 수 있으면
        {
            q.push(arr[idx]);
            sum += arr[idx];
            idx++;
        }
        else // 들어올 수 없으면
            q.push(0);
    }
    return;
}

int main()
{
    // input
    cin >> n >> w >> L;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // init
    for (int i = 0; i < w - 1; i++)
        q.push(0);

    q.push(arr[0]);
    sum += arr[0];

    traverse();

    cout << cnt + w;
}