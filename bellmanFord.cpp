#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

const int V = 5;
vector<pair<int,int>> graph[V+1];
int startNode = 1, endNode = 5; // 시작 노드, 도착 노드 설정
void setSampleGraph(); // 샘플 그래프 생성 함수

int bellmanFord(int startNode, int endNode)
{
    vector<int> currWeights(V+1, INT_MAX); // 현재 가중치 테이블
    vector<int> prevWeights; // 이전 가중치 테이블

    // 1. 시작 노드 가중치 테이블 값 초기화
    currWeights[startNode] = 0;
    for (int i=1; i<V; i++) { // 아래 과정 V-1 번 반복
        prevWeights = vector<int>(currWeights); // 테이블 정보 복사
        for (int node=1; node<=V; node++) {
    // 2-a. 초기값일 경우 고려 X
            if (prevWeights[node] == INT_MAX) continue;
    // 2-b. 초기값이 아닐 경우 다음 경로 포함하여 계산
            for (pair<int,int> info : graph[node]) {
                int nxtWeight = prevWeights[node] + info.first;
                int nxtNode = info.second;
    // 3. 최솟값을 현재 가중치 테이블에 저장
                currWeights[nxtNode] = min(prevWeights[nxtNode], nxtWeight);
            }
        }
    }
    return currWeights[endNode];
}


int main()
{
    setSampleGraph();
    cout << bellmanFord(startNode, endNode);
    return 0;
}

void setSampleGraph()
{   // 예시 그래프 활용
    // 가중치, 연결된 노드 순으로 인접 리스트에 저장
    graph[1].push_back({2,2});
    graph[1].push_back({3,3});
    graph[1].push_back({1,4});
    graph[1].push_back({10,5});

    graph[2].push_back({2,4});
    
    graph[3].push_back({1,4});
    graph[3].push_back({1,5});
    
    graph[4].push_back({3,5});
}
