#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


typedef std::pair<int, int> edge;
static std::vector < std::vector <edge> > A;
static std::vector<bool> visited;
static std::vector<int> m_distance;
void BFS(int node);

#define LOSE 1

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	if (LOSE) {
        using namespace std;
        int N;
    cin >> N;
    A.resize(N + 1);

    for (int i = 0; i < N; i++) {
        int S;
        cin >> S;
        while (true)
        {
            int E, V;
            cin >> E;
            if (E == -1)break;
            cin >> V;
            A[S].push_back(edge(E, V));
        }
    }

    m_distance = vector<int>(N + 1, 0);
    visited = vector<bool>(N+1, false);
    BFS(1);
    int Max = 1;
    for (int i = 2; i <= N; i++) {
        if (m_distance[Max] < m_distance[i])
            Max = i;
    }
    fill(m_distance.begin(), m_distance.end(), 0); // �Ÿ� �迭 �ʱ�ȭ
    fill(visited.begin(), visited.end(), false); // �湮 �迭 �ʱ�ȭ
    BFS(Max);
    sort(m_distance.begin(), m_distance.end());
    cout << m_distance[N] << "\n";
	}
	else {

    }
}


void BFS(int index) {  // BFS����
    std::queue<int> myqueue;
    myqueue.push(index);
    visited[index] = true;

    while (!myqueue.empty()) {
        int now_node = myqueue.front();
        myqueue.pop();
        for (edge i : A[now_node]) {
            if (!visited[i.first]) {
                visited[i.first] = true;
                myqueue.push(i.first);
                m_distance[i.first] = m_distance[now_node] + i.second;
            }
        }
    }
}