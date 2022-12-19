#include <iostream>
#include <vector>
using namespace std;

const int MAX_NUM = 1000 + 1; // 1 ~ 1,000까지 판별

vector<int> prime(MAX_NUM, 1); // 1. 배열 초기화

void eratosSieve()
{
    prime[0] = 0; prime[1] = 0; // 0과 1 제외

    // 2. 2부터 시작, 특정 수의 배수 모두 제외
    for (int i=2; i<=MAX_NUM; i++) {
        if (prime[i] == 0) continue; // 이미 제외된 수
        
        // 현재 숫자 외 해당 숫자의 배수 모두 제외
        for (int j=i*2; j<= MAX_NUM; j+=i) prime[j] = 0;
    }

    // 3. 남아있는 수(소수) 출력
    for (int i=2; i<=MAX_NUM; i++) {
        if (prime[i]) cout << i << '\n';
    }
}

int main()
{
    eratosSieve();
    return 0;
}