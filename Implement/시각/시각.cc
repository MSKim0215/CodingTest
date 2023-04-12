#include <iostream>

using namespace std;

bool CheckTime(int _hour, int _min, int _second)
{
    if(_hour % 10 == 3 || _min / 10 == 3 || _min % 10 == 3 || _second / 10 == 3 || _second % 10 == 3) return true;
    return false;
}

int main()
{
    int N;      // 시간
    cin >> N;
    
    int count = 0;      // '3'이 포함
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j < 60; j++)
        {
            for(int k = 0; k < 60; k++)
            {   // TODO: 매 시각 안에 '3'이 포함되어 있다면 카운트 증가
                if(CheckTime(i, j, k))
                {
                    count++;
                }
            }
        }
    }
    
    cout << count;
}
