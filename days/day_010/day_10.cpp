#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define LOSE 1

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	if (LOSE) {
        typedef std::pair<int, int> Node;
        using namespace std;
        int N, L;
    cin >> N >> L;
    deque<Node> mydeque;
    
    for (int i = 0; i < N; i++) {
        int now;
        cin >> now;
        // 새로운 값이 들어 올 때마다 정렬하지 않고 현재 수보다 큰 값을 덱에서 제거함으로써 시간복잡도를 줄일 수 있음
        while (mydeque.size() && mydeque.back().first > now) {
            mydeque.pop_back();
        }
        mydeque.push_back(Node(now, i));
        // 범위에서 벗어난 값은 덱에서 제거
        if (mydeque.front().second <= i - L) {
            mydeque.pop_front();
        }
        cout << mydeque.front().first << ' ';
    }
	}
	else {
        //GG
	}
}