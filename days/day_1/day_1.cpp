#include <iostream>

int main() {
	int total_num;
	std::cin >> total_num;
	total_num += 1;
	char* num_stred= new char[total_num];

	std::cin >> num_stred;
	
	int num_sum = 0;
	//int i1 = sizeof(num_stred) / sizeof(char);   // 시발... 뭐임 왜 N이 5일때 8이 쳐나옴? 시밤.... 공부하기...
	for (int i = 0; num_stred[i] != '\0'; i++) {
		num_sum += (int)num_stred[i] -48;
	}

	std::cout << num_sum;
	delete[] num_stred;
}