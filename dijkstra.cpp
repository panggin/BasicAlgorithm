#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

const int V = 5;
vector<pair<int,int>> graph[V+1];
int startNode = 1, endNode = 5; // 시작 노드, 도착 노드 설정
void setSampleGraph();

int dijkstra(int startNode, int endNode)
{
    priority_queue<pair<int,int>, 
        vector< pair<int,int> >, greater< pair<int,int> > > pq;
    vector<int> minWeights(V+1, INT_MAX); // 최소 가중치 테이블

    // 1. 시작 노드 초기화
    minWeights[startNode] = 0; pq.push({0,startNode});
    
    while (!pq.empty()) {
    // 2. 가장 앞에 있는 노드(현재 노드) 가져옴
        int currWeight = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

    // 3-a. 최솟값 X -> 경로 고려 X
        if (currWeight > minWeights[currNode]) continue;
    // 3-b. 최솟값 O -> 다음 이동 가능한 노드 가중치 계산
        for (auto nxt : graph[currNode]) {
            int nxtWeight = currWeight + nxt.first;
            int nxtNode = nxt.second;

    // 4. 테이블 업데이트 -> 큐에 다음 노드 넣기
            if (nxtWeight < minWeights[nxtNode]) {
                minWeights[nxtNode] = nxtWeight;
                pq.push({nxtWeight, nxtNode});
            }
        }
    }
    return minWeights[endNode]; // 도착 노드로의 최단 거리
}


int main()
{
    setSampleGraph();
    cout << dijkstra(startNode, endNode);
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
