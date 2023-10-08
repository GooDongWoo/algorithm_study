#include <iostream>
#include <vector>
#include <stack>
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
    vector<char> resultV;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    stack <int> myStack;
    int num = 1; // �������� ��
    bool result = true;
    for (int i = 0; i < A.size(); i++) {
        int su = A[i]; // ���� ������ ��
        if (su >= num) { //���� ���� �� >= �������� �ڿ��� : ���� ���� �� ������ push()����
            while (su >= num) { // push()
                myStack.push(num++);
                resultV.push_back('+');
            }
            myStack.pop();
            resultV.push_back('-');
        }
        else {  //���� ���� �� < �������� �ڿ���: pop()�� �����Ͽ� ���� ���Ҹ� �����ϴ�
            int n = myStack.top();
            myStack.pop();
            // ������ ���� ���� ���� ������ �ϴ� ������ �� ���� ũ�ٸ� ���� ���? �Ұ���
            if (n > su) {
                cout << "NO";
                result = false;
                break;
            } 
            else {
                resultV.push_back('-');
            }
        }
    }
    if (result) {
        for (int i = 0; i < resultV.size(); i++)
        {
            cout << resultV[i] << '\n';
        }
    }
	}
	else {
        //i cant understand problem itself!! wtf!!!!!
	}
}