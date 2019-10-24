#include <stdio.h>
#include <stdlib.h> // system 함수 쓰려고
#include <string.h> // strcpy() ,strcmp() 함수 쓰려고
#include <Windows.h>
#include <conio.h>

#define TRUE	1
#define ESCAPE	0

#define INSERT		1
#define DELETE		2
#define UPDATE		3
#define RETRIEVE	4
#define PRINT		5
#define LOAD		6
#define SAVE		7
#define EXIT		0


typedef struct Data { // 배열처럼 하기 위해 포인터로 선언
	char ncarFirst[3]; // 글자앞에 숫자 2개 저장
	char ncarSecond[3]; //가운데 글자 하나 저장
	char ncarLast[5]; // 마지막 숫자 4개저장
	int ncarPosition;
	struct Data* link; //자기참조 구조체
}CarData; // 구조체 정의

CarData* pHead;

int nTotalNumber=0; // 전체 차량의 수
int displayMainMenu(); // 메뉴에서 누른값(정수)을 돌려받기 위해 int 씀

char strFileName[80];

//주차장크기, 위치지정 변수
int numg,nums;
char *parking_size;
	

// 로드 여부를 알 수 있게 해주는 변수 선언
int bFileFlag=0;

void insertNode();
void deleteNode();
void updateNode();
void retrieveNode();
// 검색노드안의 세부 3가지의 다양한 검색을 수행하기 위한 함수 선언
void Retrieve_1();
void Retrieve_2();
void Retrieve_3();
void printNode();
// ↓일반 데이터 출력과 4-2번 검색의 사용을 위한 함수 선언
char *printList_1(char MiddleWord[]); // 가운데 글자별로 차량의 종류를 리턴해주는 함수
// ↓4-3번 검색의 사용을 위한 함수 선언
char *printList_2(char first, char second); // 앞자리 숫자별로 차량의 종류를 리턴해주는 함수
// ↓반복되는 Car List 문구를 함수화 시킴
void printForm_1();
// ↓반복되는 해당종류의 차량수 문구를 함수화시킴
void printForm_2(int count);
// ↓문자열 복사의 반복을 함수로 묶음
void copy(char First[5],char Second[5],char Last[5],char ReFirst[5],char ReSecond[5],char ReLast[5],CarData* pPrev2,CarData* pVisited);
void loadFile();
void saveFile();