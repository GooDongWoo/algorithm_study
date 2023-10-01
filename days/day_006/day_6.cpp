#include <iostream>
#define LOSE 1

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	if (LOSE) {
		std::ios::sync_with_stdio(false);
		std::cin.tie(NULL);
		std::cout.tie(NULL);

		int N;
		std::cin >> N;
		int count = 1;
		int start_index = 1;
		int end_index = 1;
		int sum = 1;
		while (end_index != N) {
			if (sum == N) {         //  답을 찾은 경우
				count++;
				end_index++;
				sum = sum + end_index;
			}
			else if (sum > N) {   // 현재 합이 답보다 큰 경우
				sum = sum - start_index;
				start_index++;
			}
			else {                // 현재 합이 답보다 작은 경우
				end_index++;
				sum = sum + end_index;
			}
		}
		std::cout << count << "\n";
	}
	else {

		int target_num;
		std::cin >> target_num;
		int* sum_arr = new int[target_num / 2 + target_num % 2];
		int mid_upper = target_num / 2 + target_num % 2;
		int mid_lower = target_num / 2;
		int count_num = 0;
		int odd_mode = target_num % 2;
		for (int i = 2; i < mid_upper; i++) {
			if (i % 2) {
				if (target_num % i) { continue; }
				if (target_num / i - (i / 2) <= 0) { continue; }
				count_num++;
			}
			else {
				if ((target_num / i * 2 + 1 == target_num / i * 2) && ((target_num / i - (i / 2 - 1) > 0))) {
					count_num++;
				}
			}


		}


		std::cout << count_num + 1;
		delete[] sum_arr;

	}
}