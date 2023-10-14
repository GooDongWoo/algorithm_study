#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define LOSE 1

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	if (LOSE) {
        using namespace std;
        string str;
    cin >> str;
    vector<int> A(str.size(), 0);
    for (int i = 0; i < str.size(); i++) {
        A[i] = stoi(str.substr(i, 1));
    }

    for (int i = 0; i < str.length(); i++) {
        int Max = i;
        for (int j = i + 1; j < str.length(); j++) {
            if (A[j] > A[Max])  //���������̹Ƿ� �ִ� ���� ã��
                Max = j;
        }
        if (A[i] < A[Max]) {
            int temp = A[i];
            A[i] = A[Max];
            A[Max] = temp;
        }
    }
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
    }
	}
	else {
        
	}
}