#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;  // 공간 크기
    cin >> N;
    
    string plan;        // 행동 계획서
    cin.ignore();
    getline(cin, plan);
    
    int x = 1, y = 1;   // 모험가 위치
    for(int i = 0; i < plan.length(); i++)
    {
        switch(plan[i])
        {
            case 'L': if(y - 1 >= 1) y--; break;
            case 'R': if(y + 1 <= N) y++; break;
            case 'U': if(x - 1 >= 1) x--; break;
            case 'D': if(x + 1 <= N) x++; break;
        }
    }
    
    cout << x << " " << y;
}
