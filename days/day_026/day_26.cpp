#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

static std::vector < std::vector <int> > A;
static std::vector<bool> visited;
static bool arrive;
void DFS(int node);
void BFS(int node);
#define LOSE 1

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	if (LOSE) {
        using namespace std;
        int N, M, Start;
    arrive = false;
    cin >> N >> M >> Start;
    A.resize(N+1);

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    // �湮�� �� �ִ� ��尡 ���� ���� ��쿡�� ��ȣ�� ���� ���� ���� �湮 �ϱ� ���� ����
    for (int i = 1; i <= N; i++) {
        sort(A[i].begin(), A[i].end());
    }

    visited = vector<bool>(N+1, false); 
    DFS(Start);
    cout << "\n";
    fill(visited.begin(), visited.end(), false); // �湮 �迭 �ʱ�ȭ
    BFS(Start);
    cout << "\n";
	}
	else {

    }
}


void DFS(int node) {  // DFS����
    std::cout << node << " ";
    visited[node] = true;
    for (int i : A[node]) {
        if (!visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int node) {  // BFS����
    std::queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;

    while (!myqueue.empty()) {
        int now_node = myqueue.front();
        myqueue.pop();
        std::cout << now_node << " ";
        for (int i : A[now_node]) {
            if (!visited[i]) {
                visited[i] = true;
                myqueue.push(i);
            }
        }
    }
}