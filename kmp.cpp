#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string target = "ababacabacaabacaaba";
string pattern = "abacaaba";

// ### 접두사, 접미사 일치 테이블 생성 함수 ###
vector<int> makeTable(string pattern)
{
    int k=0, i=0;

    int pn = pattern.size();
    vector<int> ptable = vector<int>(pn,0); // 일치 테이블 생성
    
    if (pn == 1) return ptable;

    for (i=1; i<pn; i++) {
    // 1. k, i의 문자 불일치 : k = table[k-1]
        while (k>0 && pattern[k] != pattern[i]) k = ptable[k-1];
    // 2. k, i의 문자 일치 : table[i] = k+1    
        if (pattern[k] == pattern[i]) ptable[i] = ++k;
    }
    return ptable;
}

// ### 문자열 내에서 패턴 찾기 함수 ###
void KMP(string target, string pattern)
{
    int ts=0, ti=0, pi=0;

    int tn = target.size(), pn = pattern.size();
    vector<int> ptable = makeTable(pattern);

    for (ti=0; ti<tn; ti++) {
    // 1. 패턴 불일치
        while (target[ti] != pattern[pi]) {
            if (pi > 0) pi = ptable[pi-1];
            ts = ti - pi; // 문자열 내 패턴 시작점 조정
        }
    // 2. 패턴 일치
        if (pi == pn-1) { // 패턴 전체 일치
            cout << "pattern start index : " << ts << '\n';
        } pi++;
    }
}

int main()
{
    cout << "Target : " << target << '\n'
        << "pattern : " << pattern << '\n';
    
    KMP(target, pattern);
    return 0;
}