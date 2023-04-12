#include <iostream>
#include <string>

using namespace std;

int main()
{
    string answer;      // 나이트 초기 위치
    cin >> answer;
    
    int staps[8][2] = {{2,-1}, {2,1}, {-2,-1}, {-2,1}, {1,-2}, {-1,-2}, {1,2}, {-1,2}};     // 나이트의 이동 경우의 수
    int count = 0;      // 총 경우의 수
    
    int x = answer[0];          // 나이트의 위치
    int y = answer[1] - '0';    // 나이트의 위치
    
    for(int i = 0; i < 8; i++)
    {
        if((x + staps[i][0] <= 'h' && x + staps[i][0] >= 'a') && (y + staps[i][1] <= 8 && y + staps[i][1] >= 1))
        {
            count++;
        }
        
    }
    cout << count;
}
