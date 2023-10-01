#include <iostream>

int main() {
	int total_data_num, total_line_num;
	std::cin >> total_data_num >> total_line_num;

	int ** row_arr = new int*[total_data_num];
	for (int i = 0; i < total_data_num; i++) {
		row_arr[i] = new int[total_data_num];
	}
	int* output_array = new int[total_line_num];
	int **sum_arr = new int* [total_data_num];
	for (int i = 0; i < total_data_num; i++) {
		sum_arr[i] = new int[total_data_num];
	}

	// 더블어레이에 할당
	for (int i = 0; i < total_data_num; i++) {
		for (int j = 0; j < total_data_num; j++) {
			std::cin >> row_arr[i][j];
		}
	}
	//섬어레이 할당
	sum_arr[0][0] = row_arr[0][0];
	for (int i = 1; i < total_data_num; i++) {
		sum_arr[0][i] = sum_arr[0][i-1]+ row_arr[0][i];
		sum_arr[i][0] = sum_arr[i-1][0]+ row_arr[i][0];
	}

	for (int i = 1; i < total_data_num; i++) {
		for (int j = 1; j < total_data_num; j++) {
			sum_arr[i][j] = sum_arr[i - 1][j] + sum_arr[i][j - 1] - sum_arr[i - 1][j - 1]+ row_arr[i][j];
		}
	}

	double num_sum = 0;
	int start_Xidx,start_Yidx,end_Xidx,end_Yidx;

	for (int i = 0; i < total_line_num; i++) {
		std::cin >> start_Xidx >> start_Yidx>> end_Xidx >> end_Yidx;
		
		if ((start_Xidx == 1)||(start_Yidx == 1)) {
			if ((start_Xidx == 1) && (start_Yidx == 1)) {
				output_array[i] = sum_arr[end_Xidx-1][end_Yidx-1];
			}
			else if (start_Xidx == 1) {
				output_array[i] = sum_arr[end_Xidx - 1][end_Yidx - 1] - sum_arr[end_Xidx - 1][start_Yidx-2];
			}
			else {
				output_array[i] = sum_arr[end_Xidx - 1][end_Yidx - 1] - sum_arr[start_Xidx - 2][end_Yidx - 1];
			}
			continue;
		}

		output_array[i] = sum_arr[end_Xidx - 1][end_Yidx - 1] - sum_arr[end_Xidx - 1][start_Yidx - 2] - sum_arr[start_Xidx - 2][end_Yidx - 1] + sum_arr[start_Xidx - 2][start_Yidx - 2];
	}

	for (int i = 0; i < total_line_num; i++) {
		std::cout << output_array[i] << '\n';
	}
	delete[] row_arr;
	delete[] output_array;

}