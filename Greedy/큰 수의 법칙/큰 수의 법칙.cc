#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> vec;
    for(int i = 0; i < N; i++)
    {
        int answer;
        cin >> answer;
        vec.push_back(answer);
    }
    
    sort(vec.begin(), vec.end());
    
    int first = vec[N - 1];
    int second = vec[N - 2];
    
    // TODO: 가장 큰 수가 더해지는 횟수
    int count = (M / (K + 1)) * K;
    count += (M % (K + 1));     // 남은 횟수
    
    int result = 0;
    result += count * first;            // 제한된 횟수 만큼 가장 큰 수 더하기
    result += (M - count) * second;     // 나머지 횟수 만큼 두번째로 큰 수 더하기
    
    cout << result;
}
