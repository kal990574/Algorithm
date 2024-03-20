#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int arr[12][6];
int visited[12][6];
int visit_cnt = 1;
int linked_cnt = 0;
vector<pair<int, int> > v;

int is_in(int x, int y)
{
   if (x >= 0 && x < 12 && y >= 0 && y < 6)
      return 1;
   else
      return 0;
}

void dfs(int x, int y, int color, int visit_flag)
{
   if (is_in(x, y) == 0 || color != arr[x][y] || visited[x][y] == visit_flag) // 범위를 벗어나거나 색이 다르면
      return ;

   visited[x][y] = visit_flag;
   v.push_back(make_pair(x, y));
   linked_cnt++;

   dfs(x - 1, y, color, visit_flag);
   dfs(x + 1, y, color, visit_flag);
   dfs(x, y - 1, color, visit_flag);
   dfs(x, y + 1, color, visit_flag);
}
void show()
{
   for (int i = 0; i < 12; i++)
   {
      for (int j = 0; j < 6; j++)
      {
         cout << arr[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;
}
void poyo()
{
   for (int i = 0; i < v.size(); i++)
   {
      int x = v[i].first;
      int y = v[i].second;
      arr[x][y] = 0;
   }
}
void init_visit()
{
   for (int i = 0; i < 12; i++)
      for (int j = 0; j < 6; j++)
         visited[i][j] = 0;
}
void push_down()
{
   for (int j = 0; j < 6; j++)
   {
      queue<int> q;
      for (int i = 11; i >= 0; i--)
      {
         if (arr[i][j] != 0)
         {
            q.push(arr[i][j]);
            arr[i][j] = 0;
         }
      }

      int idx = 0;
      while (!q.empty())
      {
         arr[11 - idx][j] = q.front();
         q.pop();
         idx++;
      }
   }
}

int main()
{
   // input
   for (int i = 0; i < 12; i++)
   {
      string temp;
      cin >> temp;
      for (int j = 0; j < 6; j++)
      {
         char t = temp[j]; // 문자로 변경
         if (t == '.')
            arr[i][j] = 0;
         else if (t == 'R')
            arr[i][j] = 1;
         else if (t == 'G')
            arr[i][j] = 2;
         else if (t == 'B')
            arr[i][j] = 3;
         else if (t == 'P')
            arr[i][j] = 4;
         else // Y
            arr[i][j] = 5;
      }
   }
   // show();
   int ans = 0;
   while (1)
   {
      int end_flag = 0;
      // dfs 시작 -> 한 cnt 실행
      for (int i = 0; i < 12; i++)
      {
         for (int j = 0; j < 6; j++)
         {
            if (arr[i][j] > 0 && visited[i][j] != visit_cnt) // 색이 있고 이번턴에 방문 안됐으면
            {
               dfs(i, j, arr[i][j], visit_cnt);

               if (linked_cnt >= 4)
               {
                  poyo();
                  end_flag = 1;
               }

               v.clear();
               linked_cnt = 0;
            }
         }
      }
      visit_cnt++;

      if (end_flag == 0)
         break;

      ans++;
      // show();

      // 내리기
      push_down();
      // show();
   }
   cout << ans << endl;

   return 0;
}