#include <iostream>
#include <vector>
#include <algorithm>
#define LOSE 1

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	if (LOSE) {
        using namespace std;
        int N;
        cin >> N;
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i].first;
            A[i].second = i;
        }

        sort(A.begin(), A.end()); //A�迭 ���� O(nlogn)�ð� ���⵵

        int Max = 0;
        for (int i = 0; i < N; i++) {
            if (Max < A[i].second - i) //���� �� index - ���� �� index ��� ���� �ִ� ���� ã�� ����
                Max = A[i].second - i;
        }
        cout << Max + 1;
	}
	else {
        
	}
}