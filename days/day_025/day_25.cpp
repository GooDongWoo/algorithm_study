#include <iostream>
#include <vector>
#include <algorithm>

static std::vector < std::vector <int> > A;
static std::vector<bool> visited;
static bool arrive;
void DFS(int now, int depth);
#define LOSE 1

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	if (LOSE) {
        using namespace std;
        int N, M;
    arrive = false;
    cin >> N >> M;
    A.resize(N);
    visited = vector<bool>(N, false);


    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    for (int i = 0; i < N; i++) {
        DFS(i, 1);
        if (arrive)
            break;
    }

    if(arrive) cout << 1 << "\n";
    else  cout << 0 << "\n";
	}
	else {

    }
}


void DFS(int now, int depth) {
    if (depth == 5 || arrive) { // ���̰� 5���Ǹ� ���α׷� ����
        arrive = true;
        return;
    }
    visited[now] = true;
    for (int i : A[now]) {
        if (!visited[i]) {
            DFS(i, depth + 1);
        }
    }
    visited[now] = false;
}