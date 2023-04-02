#include <iostream>

using namespace std;

int main()
{
   int N, K;
   cin >> N >> K;
   
   // 규칙1: N - 1
   // 규칙2: N / K -> TODO: N % K == 0
   
   int count = 0;
   while(true)
   {
       if(N % K == 0)
       {    // 규칙2 실행
           N /= K;
           count++;
       }
       else if(N % K != 0)
       {    // 규칙1 실행
           N--;
           count++;
       }
       
       if(N == 1) break;
   }
   
   cout << count << "\n";
}
