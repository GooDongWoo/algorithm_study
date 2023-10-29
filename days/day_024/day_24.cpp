#include <iostream>
#include <vector>
#include <algorithm>

void DFS(int number, int jarisu);
bool isPrime(int num);
static int N;

#define LOSE 1

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	if (LOSE) {
        using namespace std;
        cin >> N;
    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
	}
	else {

    }
}

void DFS(int number, int jarisu) {
    if (jarisu == N) {
        if (isPrime(number)) {
            std::cout << number << "\n";
        }
        return;
    }
    for (int i = 1; i < 10; i++) {
        if (i % 2 == 0) { // ¦���̸� �� �̻� Ž���� �ʿ䰡 ����
            continue;
        }
        if (isPrime(number * 10 + i)) { // �Ҽ��̸� ��ͷ� �ڸ����� �÷����ϴ�.
            DFS(number * 10 + i, jarisu + 1);
        }
    }
}

bool isPrime(int num) {
    for (int i = 2; i <= num / 2; i++)
        if (num % i == 0)
            return false;
    return true;
}