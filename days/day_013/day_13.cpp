#include <iostream>
#include <queue>
#define LOSE 1

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	if (LOSE) {
        using namespace std;
        queue <int> myQueue;
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) { // ī�带 ť�� �����ϱ�
        myQueue.push(i);
    }
    while (myQueue.size() > 1) { // ī�尡 1�� ���� ������
        myQueue.pop(); // �� ���� ī�带 ����
        myQueue.push(myQueue.front()); // �� ���� ī�带 ���� �Ʒ� ī�� ������ �̵�
        myQueue.pop();
    }
    cout << myQueue.front();
	}
	else {
        //GG
	}
}