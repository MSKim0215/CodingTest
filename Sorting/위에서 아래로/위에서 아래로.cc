#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;      // 개수
    cin >> n;
    
    vector<int> box;    // 수열
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        box.push_back(input);
    }
    sort(box.begin(), box.end(), greater<>());
    
    for(int i = 0; i < n; i++)
    {
        cout << box[i] << " ";
    }
}
