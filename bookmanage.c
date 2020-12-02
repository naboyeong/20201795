#include<stdio.h>
#include<stdlib.h>

void bookchange();
void bookmark(void);
struct book{
	char name[30]; //책이름
	int star; //책 즐겨찾가 -0,1로 표현 1 즐겨찾기, 0즐겨찾기x
	int read; //책갈피, 책 몇쪽까지 읽었는지
	char location[10]; //책 위치
	char type; //책 종류
	int damage; //책 훼손상태 1 상 2 중 3 하
};

//
int main(void)
{
	struct book s;
	int number, end;
	end = 1;
	do
	{
	printf("안녕하세요! 책 관리 프로그램입니다.\n");
	printf("1.책 검색\n");
	printf("2.책 랜덤 추천 프로그램\n");
	printf("3.책 추가\n");
	printf("4.책 삭제\n");
	printf("5.책 종류별 검색\n");
	printf("6.즐겨찾기\n");
	printf("7.책갈피\n");
	printf("8.종료\n");
	printf("번호를 선택하세요! ");
	scanf("%d", &number);
	
	switch(number){
		case 1:
			break;
		case 2:
			break;
		case 3:
			bookchange();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			bookmark();
			break;
		case 8:
			end = 0;
			break;
		default:
			printf("다시선택해주세요\n");
			break;
	}
	}while (end !=0);

	return 0;

	
	
}

void bookchange()
{	
	int booknumber, bookend;
	bookend = 1;
	do
	{
	printf("책목록을 수정합니다.\n");
	printf("1.책추가\n");
	printf("2.책 목록 제거\n");
	printf("3.뒤로가기\n");
	printf("번호를 선택하세요! ");
	scanf("%d", &booknumber);
	
	switch(booknumber){
		case 1:
			break;
		case 2:
			break;
		case 3:
			bookend = 0;
			break;
		default:
			printf("번호를 잘못입력하셨습니다.\n");
	 }
	}while (bookend !=0);
}
void bookmark(void)
{
	
	int booknumber, bookend;
	bookend = 1;
	do
	{
	printf("책갈피를 사용합니다.\n");
	printf("1.책갈피\n");
	printf("2.책쪽수 수정 \n");
	printf("3.뒤로가기 \n");
	printf("번호를 선택하세요! ");
	scanf("%d", &booknumber);
	
	switch(booknumber){
		case 1:
			break;
		case 2:
			break;
		case 3:
			bookend = 0;
			break;
		default:
			printf("번호를 잘못입력하셨습니다.\n");
	 }
	}while (bookend !=0);
}
