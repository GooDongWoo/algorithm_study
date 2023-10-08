#include <iostream>
#include <queue>
#define LOSE 1

struct compare {
    bool operator()(int o1, int o2) {
        int first_abs = abs(o1);
        int second_abs = abs(o2);
        if (first_abs == second_abs)
            return o1 > o2;// ���밪�� ���� ��� ���� �켱 ����
        else
            return first_abs > second_abs;// ���밪�� �������� ����
    }
};

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	if (LOSE) {
        using namespace std;
        priority_queue<int, vector<int>, compare> MyQueue;
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int request;
            cin >> request;
            if (request == 0) {
                if (MyQueue.empty()) {
                    cout << "0\n";
                }
                else {
                    cout << MyQueue.top() << '\n';
                    MyQueue.pop();
                }
            }
            else {
                MyQueue.push(request);
            }
        }
        }
        else {
            
        }
}
