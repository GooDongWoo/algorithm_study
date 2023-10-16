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
        int count[10001] = { 0 };
        int number = 0;
        for (int i = 1; i <= N; i++) {
            cin >> number;
            count[number]++;
        }
        for (int i = 0; i <= 10000; i++) {
            if (count[i] != 0) {
                for (int j = 0; j < count[i]; j++) {    // �ش� count �迭�� �� ��ŭ index�� �ݺ��Ͽ� ���
                    cout << i << "\n";  
                }
            }
        }
	}
	else {

	}
}