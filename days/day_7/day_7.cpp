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
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int N, M;
        cin >> N >> M;
        vector<int> A(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        sort(A.begin(), A.end());

        int count = 0;
        int i = 0;
        int j = N - 1;
        while (i < j) { //투 포인터 이동 원칙에 따라 포인터를 이동하여 처리
            if (A[i] + A[j] < M) {
                i++;
            }
            else if (A[i] + A[j] > M) {
                j--;
            }
            else {
                count++;
                i++;
                j--;
            }
        }
        cout << count << "\n";
	}
	else {
        int item_counter[100001] = {0};
        int total_item_num; //1~15,000
        int need_sum;//1~10,000,000
        int tmp;
        int answer = 0;
        std::cin >> total_item_num >> need_sum;
        for (int i = 0; i < total_item_num; i++) {
            std::cin >> tmp;
            item_counter[tmp]++;
        }
        int mid = std::min(need_sum / 2, 100001/2) ;
        for (int i = 1; i <= mid; i++) {
            if ((item_counter[i]!=0) &&(item_counter[need_sum-i]!= 0)){
                answer += std::min(item_counter[i], item_counter[need_sum - i]);
            }

        }
        std::cout << answer << "\n";
	}
}