#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long total_data_num, div_num;
	std::cin >> total_data_num >> div_num;
	long* arr = new long[total_data_num];
	long* sum_arr = new long[total_data_num];
	long* remainder = new long[div_num];
	long count_num = 0;
	long tmp;

	std::cin >> arr[0];
	sum_arr[0] = arr[0];
	for (int i = 1; i < total_data_num; i++) {
		std::cin >> arr[i];
		sum_arr[i] = sum_arr[i - 1] + arr[i];
	}
	for (int i = 0; i < div_num; i++) {
		remainder[i] =0;
	}

	for (int i = 0; i < total_data_num; i++) {
		tmp = (sum_arr[i] % div_num);
		remainder[tmp]++;
		if (tmp == 0) {
			count_num++;
		}
	}
	for (int i = 0; i < div_num; i++) {
		count_num += (remainder[i] * (remainder[i] - 1)) / 2;
	}
	/*
	for (int i = total_data_num-1; i >=0; i--) {
		for (int j = i-1; j >=0 ; j--) {
			if ((sum_arr[i] - sum_arr[j]) % div_num == 0) {
				count_num += 1;
			}
		}
		if (sum_arr[i] % div_num == 0) {
			count_num += 1;
		}
	}*/
	std::cout << count_num;
	delete[] arr;// 동우야!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 제발 딜리트 까먹지 말자... 
	delete[] sum_arr;
	delete[] remainder;

}