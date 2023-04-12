#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool DFS(vector<vector<int>> &_iceVec, int _N, int _M, int _x, int _y)
{
    if(_x <= -1 || _x >= _N || _y <= -1 || _y >= _M) return false;  // 주어진 범위를 벗어나는 경우 즉시 종료
    
    // TODO: 현재 노드를 아직 방문하지 않았다면
    if(_iceVec[_x][_y] == 0)
    {
        _iceVec[_x][_y] = 1;
        
        // 상,하,좌,우 위치들도 모두 재귀적으로 호출
        DFS(_iceVec, _N, _M, _x - 1, _y);
        DFS(_iceVec, _N, _M, _x, _y - 1);
        DFS(_iceVec, _N, _M, _x + 1, _y);
        DFS(_iceVec, _N, _M, _x, _y + 1);
        return true;
    }
    return false;
}

int main()
{
    int N, M;       // N: 세로, M: 가로
    cin >> N >> M;
    cin.ignore();       // 개행 문자 제거
    
    vector<vector<int>> iceVec;     // 얼음 벡터
    for(int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);
        vector<int> typeVec;
        for(int j = 0; j < M; j++)
        {
            int input = line[j] - '0';      // int 변환
            typeVec.push_back(input);
        }
        iceVec.push_back(typeVec);
    }
    
    // 모든 위치에 대하여 음료수 채우기
    int result = 0;     // 생성되는 아이스크림 개수
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // TODO: 현재 위치에서 DFS
            if(DFS(iceVec, N, M, i, j)) result++;
        }
    }
    
    cout << result;
}
