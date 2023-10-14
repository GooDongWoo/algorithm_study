#include <iostream>
#include <vector>
#define LOSE 1

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	if (LOSE) {
        using namespace std;
        int N;
        cin >> N;
        vector<int> A(N, 0);
        vector<int> S(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        for (int i = 1; i < N; i++) { //���� ����
            int insert_point = i;
            int insert_value = A[i];
            for (int j = i - 1; j >= 0; j--) {
                if (A[j] < A[i]){
                    insert_point = j + 1;
                    break;
                }
                if (j == 0) {
                    insert_point = 0;
                }
            }
            for (int j = i; j > insert_point; j--) {
                A[j] = A[j - 1];
            }
            A[insert_point] = insert_value;
        }

        S[0] = A[0]; //�չ迭 ����� 
        for (int i = 1; i < N; i++) {
            S[i] = S[i - 1] + A[i];
        }

        int sum = 0; //�չ迭 ���� ���ϱ�
        for (int i = 0; i < N; i++) {
            sum = sum + S[i];
        }

        cout << sum;
    }
	else {
        
}
}