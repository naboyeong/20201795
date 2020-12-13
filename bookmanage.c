#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define ESC 0x1b

typedef struct book{
	char name[30]; //책이름
	int star; //책 즐겨찾가 -0,1로 표현 1 즐겨찾기, 0즐겨찾기x
	int read; //책갈피, 책 몇쪽까지 읽었는지
	char location[10]; //책 위치
	char type[10]; //책 종류
	int damage; //책 훼손상태 1 상 2 중 3 하
	struct book* next;
}book_t;

typedef struct bookrandom{
	char name[30]; //책이름
	int star; //책 즐겨찾가 -0,1로 표현 1 즐겨찾기, 0즐겨찾기x
	int read; //책갈피, 책 몇쪽까지 읽었는지
	char location[10]; //책 위치
	char type[10]; //책 종류
	int damage; //책 훼손상태 1 상 2 중 3 하
	int num; //책번호 붙이기(랜덤으로 뽐기위한)
	struct bookrandom* next;
}bookrandom_t;

typedef struct booknew{
	char name[30]; //책이름
	int star; //책 즐겨찾가 -0,1로 표현 1 즐겨찾기, 0즐겨찾기x
	int read; //책갈피, 책 몇쪽까지 읽었는지
	char location[10]; //책 위치
	char type[10]; //책 종류
	int damage; //책 훼손상태 1 상 2 중 3 하

}booknew_t;

void bookchange();
void bookmark(void);
void bookimformation(void);
void bookrandomc(bookrandom_t*(*func)(int*, bookrandom_t*));
void booktype(void);
void bookstar(void);
void bookread(void);
void bookdamage(void);
void bookwrite(void);
void bookreadc(void); //책갈피 수정
void bookrmove(void);
void bookstarc(void);

booknew_t get_record();

book_t* search_book(char* name, book_t* list_head)
{
	book_t* tmp = list_head;
	while (tmp){
		if(!strcmp(tmp->name, name)){
			return tmp;
		}
		tmp = tmp->next;
	}
	return tmp;
}

void search_type(char* type, book_t* list_head)
{
	book_t* tmp = list_head;
	while (tmp){
		if(!strcmp(tmp->type, type)){
			printf("책이름: %s 책 위치: %s\n",tmp->name, tmp->location);
		}
		tmp = tmp->next;
	}
	
}
book_t* search_rmove(char* name, book_t* list_head)
{
	book_t* temp;
	book_t* prev;
	temp = list_head;
	int i;
	if (strcmp(temp->name, name)==0){
		list_head = temp->next;
		free(temp);
	}
	else {
		for (i = 0; strcmp(temp->name, name) != 0; ++i){
			temp = temp->next;
			if( i != 0){
				prev = prev->next;
			}if(i ==1){
				prev = list_head;
			}
		}
		prev->next = temp->next;
		free(temp);
	}
	return list_head;
}

int search_read(char* name, book_t* list_head)
{
	book_t* tmp = list_head;
	while (tmp){
		if(!strcmp(tmp->name, name)){
			if (tmp->type == "문제집")
				printf("%d까지 풀었습니다.\n", tmp->read);
			else
				printf("%d까지 읽었습니다.\n", tmp->read);
			return 1;
		}
		tmp = tmp->next;
	}
	return 0;
}

int search_readc(char* name, book_t* list_head, int* ra)
{
	book_t* tmp = list_head;
	while (tmp){
		if(!strcmp(tmp->name, name)){
			tmp->read = *ra;
			return 1;
		}
		tmp = tmp->next;
	}
	return 0;
}

int search_starc(char* name, book_t* list_head, int* ra)
{
	book_t* tmp = list_head;
	while (tmp){
		if(!strcmp(tmp->name, name)){
			tmp->star = *ra;
			return 1;
		}
		tmp = tmp->next;
	}
	return 0;
}
int search_damage(char* name, book_t* list_head)
{
	book_t* tmp = list_head;
	while (tmp){
		if(!strcmp(tmp->name, name)){
			if (tmp->damage == 3) //하
				printf("책의 상태가 좋습니다\n");
			else if (tmp->damage == 2)//중
				printf("책의 상태가 보통입니다. 조심히 다뤄주세요\n");
			else //상
				printf("폐기처분해야합니다.\n");
			return 1;
		}
		tmp = tmp->next;
	}
	return 0;
}
void search_star(book_t* list_head)
{
	book_t* tmp = list_head;
	while (tmp){
		if(tmp->star == 1){
			printf("책이름: %s 책 위치: %s\n",tmp->name, tmp->location);
		}
		tmp = tmp->next;
	}
	
}
bookrandom_t* search_number(int* num, bookrandom_t* list_head)
{
	bookrandom_t* tmp = list_head;
	while (tmp){
		if(tmp->num == *num){
			return tmp;
		}
		tmp = tmp->next;
	}
	return tmp;
}
//
int main(void)
{
	struct book s;
	int number, end;
	end = 1;
	do
	{
	printf("-------------------\n");
	printf("안녕하세요! 책 관리 프로그램입니다.\n");
	printf("1.책 검색\n");
	printf("2.책 랜덤 추천 프로그램\n");
	printf("3.책 추가\n");
	printf("4.책 삭제\n");
	printf("5.책 종류별 검색\n");
	printf("6.즐겨찾기\n");
	printf("7.책갈피\n");
	printf("8.책 상태\n");
	printf("9.종료\n");
	printf("번호를 선택하세요! ");
	scanf("%d", &number);
	
	switch(number){
		case 1:
			bookimformation();
			break;
		case 2:
			bookrandomc(search_number);
			break;
		case 3:
			bookwrite();
			break;
		case 4:
			bookrmove();
			break;
		case 5:
			booktype();
			break;
		case 6:
			bookchange();
			break;
		case 7:
			bookmark();
			break;
		case 8:
			bookdamage();
			break;
		case 9:
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
	printf("즐겨찾기 기능입니다.\n");
	printf("1.즐겨찾기\n");
	printf("2.즐겨찾기 수정\n");
	printf("3.뒤로가기\n");
	printf("번호를 선택하세요! ");
	scanf("%d", &booknumber);
	
	switch(booknumber){
		case 1:
			bookstar();
			break;
		case 2:
			bookstarc();
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
			bookread();
			break;
		case 2:
			bookreadc();
			break;
		case 3:
			bookend = 0;
			break;
		default:
			printf("번호를 잘못입력하셨습니다.\n");
	 }
	}while (bookend !=0);
}

void bookimformation(void)
{
	FILE* fp = NULL;
	book_t* new_node;
	book_t* tmp_node;
	book_t* list_head = NULL;
	char name[30];
	int input = 1;
	
	fp = fopen("book.dat", "r+");
	if(fp ==NULL){
		printf("Cannot open file\n");
		return;
	}
	
	while(!feof(fp)){
		new_node = (book_t*) malloc (sizeof(book_t));
		fscanf(fp, "%s %s %s %d %d %d\n", new_node->name, new_node->location, new_node->type, &new_node->read, &new_node->star, &new_node->damage);
		
		new_node->next = list_head;
		list_head = new_node;
	}
		
	//책 조회
	while(input!= 0){
		printf("-------------------\n");
		printf("책을 검색합니다.\n");
		printf("책 이름: ");
		scanf("%s", name);
		tmp_node = search_book(name, list_head);
		if(tmp_node){
			printf("책에 대한 정보입니다.\n");
			printf("책 제목: %s\n", tmp_node->name);
			printf("책 위치: %s\n", tmp_node->location);
			printf("책 종류: %s\n", tmp_node->type);
		
			if (tmp_node->star == 1)
				printf("즐겨찾기 되어있습니다.\n");
			else
				printf("즐겨찾기 되어있지않습니다.\n");
		}	
		else
			printf("찾는 책이 없습니다.\n");
		
		printf("종료하려면 0을 누르세요\n");
		scanf("%d", &input);
		
	}
	
	while(list_head){
		tmp_node = list_head;
		list_head = list_head->next;
		free(tmp_node);
	}

	fclose(fp);
}

void bookrandomc(bookrandom_t*(*func)(int* , bookrandom_t*))
{
	FILE* fp = NULL;
	bookrandom_t* new_node;
	bookrandom_t* tmp_node;
	bookrandom_t* list_head = NULL;
	int input = 1;
	int n,brandom;
	n = 0;
	fp = fopen("book.dat", "r+");
	if(fp ==NULL){
		printf("Cannot open file\n");
		return;
	}
	
	while(!feof(fp)){
		new_node = (bookrandom_t*) malloc (sizeof(bookrandom_t));
		fscanf(fp, "%s %s %s %d %d %d\n", new_node->name, new_node->location, new_node->type, &new_node->read, &new_node->star, &new_node->damage);
		new_node->num = n;
		new_node->next = list_head;
		list_head = new_node;
		n++;
	}
		
	//책 뽑기
	
	printf("-------------------\n");
	printf("책을 추첨합니다\n");
	srand((unsigned)time(NULL));

	do{
		brandom = rand()%n;
		tmp_node = func(&brandom, list_head);
	}while(tmp_node->type == "문제집");
		
	if(tmp_node){
		printf("추천하는 책입니다.\n");
		printf("책 제목: %s\n", tmp_node->name);
		printf("책 위치: %s\n", tmp_node->location);
	}	
		
	while(list_head){
		tmp_node = list_head;
		list_head = list_head->next;
		free(tmp_node);
	}

	fclose(fp);
}

void booktype(void){
	
	FILE* fp = NULL;
	book_t* new_node;
	book_t* tmp_node;
	book_t* list_head = NULL;
	char type[10];
	int input = 1;
	
	fp = fopen("book.dat", "r+");
	if(fp ==NULL){
		printf("Cannot open file\n");
		return;
	}
	
	while(!feof(fp)){
		new_node = (book_t*) malloc (sizeof(book_t));
		fscanf(fp, "%s %s %s %d %d %d\n", new_node->name, new_node->location, new_node->type, &new_node->read, &new_node->star, &new_node->damage);
		
		new_node->next = list_head;
		list_head = new_node;
	}
		
	//책 조회
	while(input!= 0){
		printf("-------------------\n");
		printf("검색할 책 종류를 고르세요\n");
		printf("책 종류(소설, 문제집, 자기계발서, 동화책, 만화책, 정보, 기타): ");
		scanf("%s", type);
		search_type(type, list_head);
	
		printf("다찾았습니다.\n");
		printf("\n");
		printf("종료하려면 0을 누르세요\n");
		scanf("%d", &input);
		
	}
	
	while(list_head){
		tmp_node = list_head;
		list_head = list_head->next;
		free(tmp_node);
	}

	fclose(fp);
}

void bookstar(void){
	
	FILE* fp = NULL;
	book_t* new_node;
	book_t* tmp_node;
	book_t* list_head = NULL;
	int a;
	
	fp = fopen("book.dat", "r+");
	if(fp ==NULL){
		printf("Cannot open file\n");
		return;
	}
	
	while(!feof(fp)){
		new_node = (book_t*) malloc (sizeof(book_t));
		fscanf(fp, "%s %s %s %d %d %d\n", new_node->name, new_node->location, new_node->type, &new_node->read, &new_node->star, &new_node->damage);
		
		new_node->next = list_head;
		list_head = new_node;
	}
		
	//즐겨찾기
	printf("-------------------\n");
	printf("즐겨찾기 되어있는 책목록입니다.\n");
	search_star(list_head);
	printf("\n");
	printf("끝났습니다.\n");
	printf("\n");

	
	while(list_head){
		tmp_node = list_head;
		list_head = list_head->next;
		free(tmp_node);
	}

	fclose(fp);
}


void bookread(void)
{
	FILE* fp = NULL;
	book_t* new_node;
	book_t* tmp_node;
	book_t* list_head = NULL;
	char name[30];
	int input = 1;
	int r;
	fp = fopen("book.dat", "r+");
	if(fp ==NULL){
		printf("Cannot open file\n");
		return;
	}
	
	while(!feof(fp)){
		new_node = (book_t*) malloc (sizeof(book_t));
		fscanf(fp, "%s %s %s %d %d %d\n", new_node->name, new_node->location, new_node->type, &new_node->read, &new_node->star, &new_node->damage);
		
		new_node->next = list_head;
		list_head = new_node;
	}
		

	while(input!= 0){
		printf("-------------------\n");
		printf("책갈피 볼 책을 검색하세요\n");
		printf("책 이름: ");
		scanf("%s", name);
		r = search_read(name, list_head);
		if(r == 0){
			printf("찾는 책이 없습니다.\n");
		}	
		
		printf("종료하려면 0을 누르세요\n");
		scanf("%d", &input);
		
	}
	
	while(list_head){
		tmp_node = list_head;
		list_head = list_head->next;
		free(tmp_node);
	}

	fclose(fp);
}
void bookdamage(void)
{
	FILE* fp = NULL;
	book_t* new_node;
	book_t* tmp_node;
	book_t* list_head = NULL;
	char name[30];
	int input = 1;
	int r;
	fp = fopen("book.dat", "r+");
	if(fp ==NULL){
		printf("Cannot open file\n");
		return;
	}
	
	while(!feof(fp)){
		new_node = (book_t*) malloc (sizeof(book_t));
		fscanf(fp, "%s %s %s %d %d %d\n", new_node->name, new_node->location, new_node->type, &new_node->read, &new_node->star, &new_node->damage);
		
		new_node->next = list_head;
		list_head = new_node;
	}
		

	while(input!= 0){
		printf("-------------------\n");
		printf("책상태를 볼 책을 검색하세요\n");
		printf("책 이름: ");
		scanf("%s", name);
		r = search_damage(name, list_head);
		if(r == 0){
			printf("찾는 책이 없습니다.\n");
		}	
		
		printf("종료하려면 0을 누르세요\n");
		scanf("%d", &input);
		
	}
	
	while(list_head){
		tmp_node = list_head;
		list_head = list_head->next;
		free(tmp_node);
	}

	fclose(fp);

}

void bookwrite(void)
{
	FILE *fp = NULL;
	int select;
	if((fp = fopen("book.dat", "a+") )== NULL){
		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다");
		exit(1);
	}

	booknew_t data;
	printf("책이름 ");	
	scanf("%s", data.name);
	printf("책위치 ");	
	scanf("%s", data.location);
	printf("책종류 ");
	scanf("%s", data.type);
	printf("책갈피 ");	
	scanf("%d", &data.read);
	printf("즐겨찾기 여부 1즐겨찾기 0은 아님 "); 
	scanf("%d", &data.star);
	printf("책훼손상태 ");	
	scanf("%d", &data.damage);

	fseek(fp, 0, SEEK_END);
	fprintf(fp, "%s %s %s %d %d %d", data.name,data.location, data.type, data.read, data.star, data.damage);

	fclose(fp);

}

void bookreadc(void)
{
	FILE* fp = NULL;
	book_t* new_node;
	book_t* tmp_node;
	book_t* list_head = NULL;
	char name[30];
	int input = 1;
	int r;
	int ra;
	fp = fopen("book.dat", "r+");
	if(fp ==NULL){
		printf("Cannot open file\n");
		return;
	}
	
	while(!feof(fp)){
		new_node = (book_t*) malloc (sizeof(book_t));
		fscanf(fp, "%s %s %s %d %d %d\n", new_node->name, new_node->location, new_node->type, &new_node->read, &new_node->star, &new_node->damage);
		
		new_node->next = list_head;
		list_head = new_node;
	}
		

	while(input!= 0){
		printf("-------------------\n");
		printf("책갈피 수정할 책의 제목을 입력하세요\n");
		printf("책 이름: ");
		scanf("%s", name);
		printf("책갈피 쪽수: ");
		scanf("%d", &ra); 
		r = search_readc(name, list_head, &ra);
		if(r == 0){
			printf("찾는 책이 없습니다.\n");
		}	
		
		printf("종료하려면 0을 누르세요\n");
		scanf("%d", &input);
		
	}
	fclose(fp);

	if((fp = fopen("book.dat", "w+") )== NULL){
		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다");
		exit(1);
	}
	
	book_t* tmp = list_head;
	while(tmp){
		
		fseek(fp, 0, SEEK_END);
		fprintf(fp, "%s %s %s %d %d %d", tmp->name,tmp->location, tmp->type, tmp->read, tmp->star, tmp->damage);
		tmp = tmp->next;
	}	
	while(list_head){
		tmp_node = list_head;
		list_head = list_head->next;
		free(tmp_node);
	}

	fclose(fp);
}

void bookrmove(void){

	FILE* fp = NULL;
	book_t* new_node;
	book_t* tmp_node;
	book_t* list_head = NULL;
	char name[30];
	int input = 1;
	int r;
	int ra;
	fp = fopen("book.dat", "r+");
	if(fp ==NULL){
		printf("Cannot open file\n");
		return;
	}
	
	while(!feof(fp)){
		new_node = (book_t*) malloc (sizeof(book_t));
		fscanf(fp, "%s %s %s %d %d %d\n", new_node->name, new_node->location, new_node->type, &new_node->read, &new_node->star, &new_node->damage);
		
		new_node->next = list_head;
		list_head = new_node;
	}
	
	while(input!= 0){
		printf("-------------------\n");
		printf("책갈피 삭제할 책의 제목을 입력하세요\n");
		printf("책 이름: ");
		scanf("%s", name);
		list_head = search_rmove(name, list_head);

		printf("종료하려면 0을 누르세요\n");
		scanf("%d", &input);
		
	}
	fclose(fp);

	if((fp = fopen("book.dat", "w+") )== NULL){
		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다");
		exit(1);
	}
	
	book_t* tmp = list_head;
	while(tmp){
		
		fseek(fp, 0, SEEK_END);
		fprintf(fp, "%s %s %s %d %d %d", tmp->name,tmp->location, tmp->type, tmp->read, tmp->star, tmp->damage);
		tmp = tmp->next;
	}	
	while(list_head){
		tmp_node = list_head;
		list_head = list_head->next;
		free(tmp_node);
	}

	fclose(fp);
}

void bookstarc(void)
{

	FILE* fp = NULL;
	book_t* new_node;
	book_t* tmp_node;
	book_t* list_head = NULL;
	char name[30];
	int input = 1;
	int r;
	int ra;
	fp = fopen("book.dat", "r+");
	if(fp ==NULL){
		printf("Cannot open file\n");
		return;
	}
	
	while(!feof(fp)){
		new_node = (book_t*) malloc (sizeof(book_t));
		fscanf(fp, "%s %s %s %d %d %d\n", new_node->name, new_node->location, new_node->type, &new_node->read, &new_node->star, &new_node->damage);
		
		new_node->next = list_head;
		list_head = new_node;
	}
		

	while(input!= 0){
		printf("-------------------\n");
		printf("즐겨찾기를 수정할 책의 제목을 입력하세요\n");
		printf("책 이름: ");
		scanf("%s", name);
		printf("즐겨찾기 여부(1=O,0=X): ");
		scanf("%d", &ra); 
		r = search_starc(name, list_head, &ra);
		if(r == 0){
			printf("찾는 책이 없습니다.\n");
		}	
		
		printf("종료하려면 0을 누르세요\n");
		scanf("%d", &input);
		
	}
	fclose(fp);

	if((fp = fopen("book.dat", "w+") )== NULL){
		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다");
		exit(1);
	}
	
	book_t* tmp = list_head;
	while(tmp){
		
		fseek(fp, 0, SEEK_END);
		fprintf(fp, "%s %s %s %d %d %d", tmp->name,tmp->location, tmp->type, tmp->read, tmp->star, tmp->damage);
		tmp = tmp->next;
	}	
	while(list_head){
		tmp_node = list_head;
		list_head = list_head->next;
		free(tmp_node);
	}

	fclose(fp);
}

