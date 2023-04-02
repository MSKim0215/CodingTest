#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;      // N: 행, M: 열

    int cards[N][M];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> cards[i][j];
        }
    }

    vector<int> minVec;
    for(int i = 0; i < N; i++)
    {
        int min = cards[i][0];
        for(int j = 0; j < M; j++)
        {
            if(min > cards[i][j])
            {
                min = cards[i][j];
            }
        }
        minVec.push_back(min);
    }

    sort(minVec.begin(), minVec.end());

    cout << minVec.back();
}
