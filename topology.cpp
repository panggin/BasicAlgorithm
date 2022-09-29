#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int SAMPLE_SIZE = 4;
vector<int> graph[SAMPLE_SIZE+1];
void setSampleGraph();

// ### 진입차수 테이블 생성 함수 ###
vector<int> initIndegreeTable(int nodeCounts)
{
    vector<int> indegrees(nodeCounts+1, 0); // 진입차수 테이블
    
    for (int node=1; node<=nodeCounts; node++)
        for (int nxtNode : graph[node])
            indegrees[nxtNode] += 1;
    
    return indegrees;
}

// ### 위상정렬 함수 ###
void topology(int nodeCounts)
{
    vector<int> indegrees = initIndegreeTable(nodeCounts);
    queue<int> order;

    // 1. 진입차수가 0인 노드 큐에 넣기
    for (int node=1; node<=nodeCounts; node++) {
        if (indegrees[node] == 0) order.push(node);
    }
    
    while (!order.empty()) {
    // 2. 큐에서 가장 앞 요소 가져오기
        int currNode = order.front(); order.pop();
        cout << currNode << " -> "; // 순서 출력

        for (int nxtNode : graph[currNode]) {
    // 3. 현재 노드와 연결된 노드의 진입차수 1 차감 (현재 노드 삭제 효과)
            indegrees[nxtNode] -= 1;
    // 4. 다음 노드 중 진입차수가 0인 노드 큐에 넣음
            if (indegrees[nxtNode] == 0) order.push(nxtNode);
        }
    }
}

int main()
{
    setSampleGraph();
    topology(SAMPLE_SIZE);
    return 0;
}

void setSampleGraph()
{   // 예시 그래프 생성 -> 인접 리스트 활용
    graph[4].push_back(2);
    graph[3].push_back(1);   
}
