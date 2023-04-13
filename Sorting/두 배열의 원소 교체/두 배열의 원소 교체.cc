#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;           // n: 배열 크기, k:  바꿔치기 횟수
    cin >> n >> k;
    
    vector<int> vecA;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        vecA.push_back(input);
    }
    
    vector<int> vecB;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        vecB.push_back(input);
    }
    
    sort(vecA.begin(), vecA.end());
    sort(vecB.begin(), vecB.end(), greater<>());
    
    for(int i = 0; i < k; i++)
    {
        if(vecA[i] < vecB[i]) swap(vecA[i], vecB[i]);
        else break;
    }
    
    int totalSum = 0;
    for(int i = 0; i < n; i++)
    {
        totalSum += vecA[i];
    }
    
    cout << totalSum;
}
