#include <iostream>

int main() {
	int total_num;
	std::cin >> total_num;
	float* num_stred = new float[total_num];

	for (int i = 0; i < total_num; i++) {
		std::cin >> num_stred[i];
	}
	int max_num = 0;
	for (int i = 0; i < total_num; i++) {
		if (max_num < num_stred[i]){
			max_num = num_stred[i];
		}
	}
	double num_sum = 0;
	//int i1 = sizeof(num_stred) / sizeof(char);   // �ù�... ���� �� N�� 5�϶� 8�� �ĳ���? �ù�.... �����ϱ�...
	for (int i = 0; i < total_num; i++) {

		num_sum += (num_stred[i]/max_num *100);
	}
	num_sum /= total_num;

	std::cout << num_sum;
	delete[] num_stred;
}