#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;       // 세로, 가로
    cin >> N >> M;
    
    int A, B, dir;  // x좌표, y좌표 방향
    cin >> A >> B >> dir;
    
    int directs[4] = {0, 1, 2, 3};                          // 0: 북쪽, 1: 동쪽, 2: 남쪽, 3:서쪽
    int directsPos[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};  // 위와 동일
    int type[2] = {0, 1};     // 0: 육지, 1: 바다
    
    vector<vector<int>> saveVec(N, vector<int>(M, 0));    // 이동한 위치 저장
    vector<vector<int>> mapVec;     // 맵벡터
    for(int i = 0; i < N; i++)
    {
        vector<int> typeVec;    // 층마다 타입이 들어가있음
        for(int j = 0; j < M; j++)
        {
            int input;
            cin >> input;
            typeVec.push_back(input);
        }
        mapVec.push_back(typeVec);
    }
    
    saveVec[A][B] = 1;      // 시작 위치 방문기록 저장
    
    // TODO: 시뮬레이션 시작
    int count = 1;
    int turn = 0;
    while(true)
    {
        dir = (dir - 1 < 0) ? directs[3] : dir - 1;       // TODO: 왼쪽 회전
        int targetX = A + directsPos[dir][0];     // 이동할 x좌표
        int targetY = B + directsPos[dir][1];     // 이동할 y좌표
        
        if(saveVec[targetX][targetY] == 0 && mapVec[targetX][targetY] == type[0])
        {   // TODO: 회전한 이후 정면에 가보지 않은 칸이 존재하는 경우 이동
            saveVec[targetX][targetY] = 1;
            A = targetX;
            B = targetY;
            count++;
            turn = 0;
            continue;
        }
        else turn++;    // 회전한 이후 정면에 가보지 않은 칸이 없거나 바다인 경우
        
        if(turn == 4)
        {   // 네 방향 모두 갈 수 없는 경우
            targetX = A - directsPos[dir][0];
            targetY = B - directsPos[dir][1];
            
            if(mapVec[targetX][targetY] == type[0])
            {   // 뒤로 갈 수 있다면 이동
                A = targetX;
                B = targetY;
            }
            else break;     // 바다라면 정지
            turn = 0;
        }
    }
    
    cout << count;
}
