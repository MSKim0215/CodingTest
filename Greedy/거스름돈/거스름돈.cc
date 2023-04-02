#include <iostream>

using namespace std;

int main()
{
    int coins[] = {500, 100, 50, 10};

    int N;      // 거스름돈
    cin >> N;
    
    int resultCount = 0;
    
    for(int i = 0; i < sizeof(coins)/sizeof(*coins); i++)
    {
        resultCount += (N / coins[i]);
        N = N % coins[i];
    }
    
    cout << resultCount;
}
