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
        int N;
        cin >> N;
        vector<int> A(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        sort(A.begin(), A.end());
        int Result = 0;
        for (int k = 0; k < N; k++) {
            long find = A[k];
            int i = 0;
            int j = N - 1;// �ǵ��-> ��... ������ �Ǿ�����.. �׻� ���������� ���ؾ��ϱ���... 
            while (i < j) {  // �������� �˰��� // �ǵ��->�̰�... ���� �ʴٰ� �޴µ�.. �´ٰ� �ؾ��ϳ���...
                if (A[i] + A[j] == find) {  // ���� �ٸ� �� ���� ������ üũ
                    if (i != k && j != k) {
                        Result++;
                        break;
                    }
                    else if (i == k) {
                        i++;
                    }
                    else if (j == k) {
                        j--;
                    }
                }
                else if (A[i] + A[j] < find) {
                    i++;
                }
                else {
                    j--;
                }
            }
        }
        cout << Result << "\n";
	}
	else {
        // 1���� �ٿ� ���� ���� N(1~2000), 2��° �ٿ� N���� ���� �� ������ ���� ����... �� ������ 1,000,000,000 ������...
        int total_num;
        std::cin >> total_num;
        int* arr_ = new int[total_num];
        // input assign array
        for (int i = 0; i < total_num; i++) {
            std::cin>>arr_[i];
        }
        //sort
        std::sort(arr_, arr_+ total_num);
        
        int* start_=arr_;
        int* end_ = arr_ + total_num - 2;
        int* isgood_ptr = arr_ + total_num-1;
        int same_num = 1;
        int good_num_num = 0;

        for (int *i = isgood_ptr; ((*i) != (*arr_)); i--) {
            if (*i==*(i-1)) {
                same_num++;
                continue;
            }
            end_ = i-1;
            for (int* j = arr_; start_ != end_; j++) {
                //if same
                if ((*i) == (*start_) + (*end_)) {
                    end_--;
                    good_num_num += same_num;
                    continue;
                }
                //if bigger
                else if ((*i) < (*start_) + (*end_)) {
                    end_--;
                }
                //if smaller
                else {
                    start_++;
                }
            }
            // 1cycle after
            same_num = 1;
        }

        std::cout << good_num_num << "\n";




	}
}