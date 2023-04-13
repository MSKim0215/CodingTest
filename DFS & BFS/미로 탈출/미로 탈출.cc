#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int bfs(const vector<vector<int>> &_map, int _N, int _M, int _startX, int _startY)
{   
    vector<vector<int>> saveVec(_N, vector<int>(_M, 0));    // 지나간 공간 체크
    int checkPos[4][2] = {{-1,0}, {1,0}, {0, -1}, {0, 1}};  // 상하좌우
    
    queue<pair<int, int>> maze;    // 미로 좌표
    maze.push({_startX, _startY});
    saveVec_startX][_startY] = 1;
    
    // TODO: 큐가 빌 때 까지 반복
    while(!maze.empty())
    {
        int x = maze.front().first;
        int y = maze.front().second;
        maze.pop();
        
        for(int i = 0; i < 4; i++)
        {   // TODO: 현재 위치에서 4가지 방향 확인
            int targetX = x + checkPos[i][0];
            int targetY = y + checkPos[i][1];
            
            // 미로 찾기 공간에서 벗어난 경우는 무시
            if(targetX < 0 || targetX >= _N || targetY < 0 || targetY >= _M) continue;
            
            // 벽인 경우 무시
            if(_map[targetX][targetY] == 0) continue;
            
            // 해당 노드를 처음 방문하는 경우에만 최단 거리 기록
            if(saveVec[targetX][targetY] == 0)
            {
                saveVec[targetX][targetY] = saveVec[x][y] + 1;
                maze.push({targetX, targetY});
            }
        }
    }
    
    // 가장 오른쪽까지의 최단거리 반환
    return saveVec[_N - 1][_M - 1]; 
}

int main()
{
    int N, M;       // N: 줄, M: 개수
    cin >> N >> M;
    cin.ignore();
    
    vector<vector<int>> mapVec;     // 지도
    for(int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);
        vector<int> typeVec;
        for(int j = 0; j < M; j++)
        {
            typeVec.push_back(line[j] - '0');
        }
        mapVec.push_back(typeVec);
    }
    
    // TODO: 탐색
    cout << bfs(mapVec, N, M, 0, 0);
}
