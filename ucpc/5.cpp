#include MAX_VTXS = 1000000

// BFS 탐색 기능이 추가된 그래프
class SearchAdjListGraph : public AdjListGraph{
private:
    bool visited[MAX_VTXS];     // 방문 기록

public:
    // 모든 정점의 방문기록을 false로 초기화
    void resetVisited(){
        for(int i=0; i<size; i++){
            visited[i] = false;
        }
    }

    // 너비우선탐색 (큐 사용)
    void bfs(int v){
        resetVisited();

        visited[v] = true;      // 현재 vertex 방문처리
        cout << getVertex(v) << " ";

        queue<int> queue;
        queue.push(v);          // 시작 vertex enqueue

        while(!queue.empty()){
            v = queue.front();
            queue.pop();        // v = queue.dequeue()

            // 인접 정점 탐색
            for(Node *n=adjList[v]; n!=NULL; n=n->getLink()){
                int nId = n->getId();       // 인접 노드의 정점 id
                if(!visited[nId]){
                    cout << getVertex(nId) << " ";
                    visited[nId] = true;  // 방문 처리
                    queue.push(nId);
                }
            }
        }
    }
};