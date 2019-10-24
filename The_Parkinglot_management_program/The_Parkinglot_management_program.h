#include <stdio.h>
#include <stdlib.h> // system �Լ� ������
#include <string.h> // strcpy() ,strcmp() �Լ� ������
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


typedef struct Data { // �迭ó�� �ϱ� ���� �����ͷ� ����
	char ncarFirst[3]; // ���ھտ� ���� 2�� ����
	char ncarSecond[3]; //��� ���� �ϳ� ����
	char ncarLast[5]; // ������ ���� 4������
	int ncarPosition;
	struct Data* link; //�ڱ����� ����ü
}CarData; // ����ü ����

CarData* pHead;

int nTotalNumber=0; // ��ü ������ ��
int displayMainMenu(); // �޴����� ������(����)�� �����ޱ� ���� int ��

char strFileName[80];

//������ũ��, ��ġ���� ����
int numg,nums;
char *parking_size;
	

// �ε� ���θ� �� �� �ְ� ���ִ� ���� ����
int bFileFlag=0;

void insertNode();
void deleteNode();
void updateNode();
void retrieveNode();
// �˻������� ���� 3������ �پ��� �˻��� �����ϱ� ���� �Լ� ����
void Retrieve_1();
void Retrieve_2();
void Retrieve_3();
void printNode();
// ���Ϲ� ������ ��°� 4-2�� �˻��� ����� ���� �Լ� ����
char *printList_1(char MiddleWord[]); // ��� ���ں��� ������ ������ �������ִ� �Լ�
// ��4-3�� �˻��� ����� ���� �Լ� ����
char *printList_2(char first, char second); // ���ڸ� ���ں��� ������ ������ �������ִ� �Լ�
// ��ݺ��Ǵ� Car List ������ �Լ�ȭ ��Ŵ
void printForm_1();
// ��ݺ��Ǵ� �ش������� ������ ������ �Լ�ȭ��Ŵ
void printForm_2(int count);
// �鹮�ڿ� ������ �ݺ��� �Լ��� ����
void copy(char First[5],char Second[5],char Last[5],char ReFirst[5],char ReSecond[5],char ReLast[5],CarData* pPrev2,CarData* pVisited);
void loadFile();
void saveFile();