#include <stdio.h>

//strcmp 함수 구현
int string_compare(char* s1, char* s2) {
	while (*s1 != '\0' || *s2 != '\0') {
		if (*s1 > *s2)
			return 1;
		else if (*s1 < *s2)
			return -1;
		else {
			s1++;
			s2++;
		}
	}
	return 0;
}

//string_compare 함수 호출
void main() {
	char* sen1 = "aaa";
	char* sen2 = "aaa";
	char* sen3 = "aab";
	char* sen4 = "aac";
    char* sen5 = "aaaaa";

	printf("%d\n", strcmp(sen1, sen2));
	printf("%d\n", strcmp(sen2, sen3));
	printf("%d\n", strcmp(sen4, sen3));
    printf("%d\n", strcmp(sen1, sen5));

    printf("%d\n", string_compare(sen1, sen2));
	printf("%d\n", string_compare(sen2, sen3));
	printf("%d\n", string_compare(sen4, sen3));
    printf("%d\n", string_compare(sen1, sen5));
}