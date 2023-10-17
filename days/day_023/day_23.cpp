#include <iostream>
#include <vector>
#include <algorithm>
#define LOSE 1

static std::vector < std::vector <int> > A;
static std::vector<bool> visited;
void DFS(int v);

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	if (LOSE) {
        using namespace std;
        int N, M;
        cin >> N >> M;
        A.resize(N + 1);
        visited = vector<bool>(N + 1, false);


        for (int i = 0; i < M; i++) {
            int s, e;
            cin >> s >> e ;
            A[s].push_back(e);
            A[e].push_back(s);
        }

        int count = 0;
        for (int i = 1; i < N + 1; i++) {
            if (!visited[i]) { // �� �湮�� ��尡 ���� ������ �ݺ�
                count++;
                DFS(i);
            }
        }
        cout << count << "\n";
	}
	else {
        
	}
}



void DFS(int v) {
    if (visited[v]) {
        return;
    }
    visited[v] = true;
    for (int i : A[v]) {
        if (visited[i] == false) { // ���� ���� �� �湮���� �ʾҴ� ��常 Ž����
            DFS(i);
        }
    }
}