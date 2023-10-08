#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define LOSE 1

int myArr[]={0,0,0,0};
int checkArr[]={0,0,0,0};
int checkSecret=0;
int check_approve(int re[],int check[]);
void remove_(int *start,int *checkArr,std::string arr_);
void add_(int *end,int *check,std::string arr_);

void Add(char c);
void Remove(char c);

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	if (LOSE) {
        using namespace std;
        int S, P;
    cin >> S >> P;
    int Result = 0;
    string A;
    cin >> A;
    for (int i = 0; i < 4; i++) {
        cin >> checkArr[i];
        if (checkArr[i] == 0)
            checkSecret++;
    }
    for (int i = 0; i < P; i++) { //초기 P부분 문자열 처리 부분
        Add(A[i]);
    }
    if (checkSecret == 4)
        Result++;
    // 슬라이딩 윈도우 처리 부분
    for (int i = P; i < S; i++) {
        int j = i - P;
        Add(A[i]);
        Remove(A[j]);
        if (checkSecret == 4)  // 4자리 수에 대한 크기가 모두 충족되었을 때는 유효한 비밀번호
            Result++;
    }
    cout << Result << "\n";
	}
	else {
        int dna_len,sub_str_len;
        std::cin >> dna_len>>sub_str_len;
        std::string arr_;
        // input assign array
        std::cin >> arr_;
        int result=0;
        
        for (int i =0; i<4;i++){
            std::cin>>myArr[i];
            if(myArr[i]==0){
                checkSecret+=1;
            }
        }
        for (int i=0;i<sub_str_len;i++){
            if(arr_[i]=='A'){
                checkArr[0]+=1;
            }
            else if(arr_[i]=='C'){
                checkArr[1]+=1;
            }
            else if(arr_[i]=='G'){
                checkArr[2]+=1;
            }
            else if(arr_[i]=='T'){
                checkArr[3]+=1;
            }
        }
        int *start_,*end_;
        *start_=0;
        *end_=sub_str_len-1;
        if(check_approve(myArr,checkArr)){
            result+=1;
        }
        for (int i=*end_;i<dna_len-1;i++){
            remove_(start_,checkArr,arr_);
            add_(end_,checkArr,arr_);
            if(check_approve(myArr,checkArr)){
            result+=1;
            }
        }

        std::cout<<result;
	}
}
int check_approve(int re[],int check[]){
    int result=0;
    for (int i=0;i<4;i++){
        if(re[i]<=check[i]){
            result+=1;
        }
    }
    if (result>=4){
        return 1;
    }
    else{
        return 0;
        }
}
void remove_(int *start,int *checkArr,std::string arr_){
    switch (arr_[*start]){
    case 'A':
        if (myArr[0] == checkArr[0])
            checkSecret--;
        myArr[0]--;
        break;
    case 'C':
        if (myArr[1] == checkArr[1])
            checkSecret--;
        myArr[1]--;
        break;
    case 'G':
        if (myArr[2] == checkArr[2])
            checkSecret--;
        myArr[2]--;
        break;
    case 'T':
        if (myArr[3] == checkArr[3])
            checkSecret--;
        myArr[3]--;
        break;
    }
}
void add_(int *end,int *check,std::string arr_){
    switch (arr_[*end]) {
    case 'A':
        myArr[0]++;
        if (myArr[0] == checkArr[0])
            checkSecret++;
        break;
    case 'C':
        myArr[1]++;
        if (myArr[1] == checkArr[1])
            checkSecret++;
        break;
    case 'G':
        myArr[2]++;
        if (myArr[2] == checkArr[2])
            checkSecret++;
        break;
    case 'T':
        myArr[3]++;
        if (myArr[3] == checkArr[3])
            checkSecret++;
        break;
    }
}

void Add(char c) { //새로 들어온 문자를 처리해주는 함수
    switch (c) {
    case 'A':
        myArr[0]++;
        if (myArr[0] == checkArr[0])
            checkSecret++;
        break;
    case 'C':
        myArr[1]++;
        if (myArr[1] == checkArr[1])
            checkSecret++;
        break;
    case 'G':
        myArr[2]++;
        if (myArr[2] == checkArr[2])
            checkSecret++;
        break;
    case 'T':
        myArr[3]++;
        if (myArr[3] == checkArr[3])
            checkSecret++;
        break;
    }
}

void Remove(char c) { //제거되는  문자를 처리해주는 함수
    switch (c) {
    case 'A':
        if (myArr[0] == checkArr[0])
            checkSecret--;
        myArr[0]--;
        break;
    case 'C':
        if (myArr[1] == checkArr[1])
            checkSecret--;
        myArr[1]--;
        break;
    case 'G':
        if (myArr[2] == checkArr[2])
            checkSecret--;
        myArr[2]--;
        break;
    case 'T':
        if (myArr[3] == checkArr[3])
            checkSecret--;
        myArr[3]--;
        break;
    }
}