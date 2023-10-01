#include <iostream>

int main() {
	int total_data_num,total_line_num;
	std::cin >> total_data_num>> total_line_num;
	int* num_stred = new int[total_data_num];
	int* sum_array = new int[total_data_num];
	int* output_array = new int[total_line_num];
	
	std::cin >> num_stred[0];
	sum_array[0] = num_stred[0];
	for (int i = 1; i < total_data_num; i++) {
		std::cin >> num_stred[i];
		sum_array[i] = sum_array[i - 1] + num_stred[i];
	}

	double num_sum = 0;
	int start_idx, end_idx;
	for (int i = 0; i < total_line_num; i++) {
		std::cin >> start_idx >> end_idx;
		if (start_idx == 1) {
			output_array[i] = sum_array[end_idx-1];
			continue;
		}
		output_array[i] = sum_array[end_idx-1] - sum_array[start_idx - 2];
	}
	for (int i = 0; i < total_line_num; i++) {
		std::cout<< output_array[i] << '\n';
	}
	delete[] num_stred;
	delete[] sum_array;

}