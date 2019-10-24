#include "The_Parkinglot_management_program.h"

int main()
{
	int nSelected;
	int infinity = TRUE;
	pHead = NULL;

	while(infinity)
	{
		nSelected = displayMainMenu(); //�Է��Ѽ��ڰ� nSelected�� �־���
		system("cls"); // clear screen
		
		while (getchar() != '\n');	// �Է� ���� ����

		switch(nSelected)
		{
		case INSERT :
			insertNode(); //space�ٸ� �̿��� ����2��,����1��,����4���� ���ʷ� �Է¹���
			break;
		case DELETE :
			deleteNode(); // ���ϴ� ������ȣ ����
			break;
		case UPDATE :
			updateNode(); // ������ȣ�� ����
			break;
		case RETRIEVE :
			retrieveNode(); // ���� 1. �ܼ��� ������ȣ�� �˻�
			break;			// ���� 2. �¿���, ȭ���� �� �������� �˻�
							// ���� 3. �Ϲݻ����(�ý�)���� �뿩�����(��Ʈī)����
							//       �ܱ���, �ڰ��� �� �������� �˻� (���� �̷��� ���� ���� ����)
		case PRINT :
			printNode(); // �����忡 �ִ� ������ȣ ���
			break;
		case LOAD :
			loadFile();
			break;
		case SAVE :
			saveFile();
			break;
		case EXIT :
			infinity = ESCAPE; // Ż������(����)
			break;
		default :
			printf("�߸��� ���� �Դϴ�.");
			break;
		} // switch
		system("pause");
	} // while

	return 0;
} // main()

int displayMainMenu()
{
	int nNum;

	system("cls"); // clear screen
	printf("\n\n");

	printf("           ��������������������\n");
	printf("          /    �ߣߣߣߣߣߣ�   ��\n");
	printf("         /   /               ��   ��\n");
	printf("        /   /�ߣߣߣߣߣߣߣߣߡ�   ��\n");
	printf("   ����������������������������������������\n");
	printf("  ��     ���������������     ��\n");
	printf("  ��     ���������������     ��\n");
	printf("  ��     ����릣���������������     ��\n");
	printf("   ����������������������������������������\n");
	printf("       ��������                ��������\n");

	printf("==============================\n");
	printf("  ������ ���� ���� ���α׷�\n");
	printf("------------------------------\n");
	printf("    1. ������ȣ ����ϱ�\n");
	printf("    2. ������ȣ �����ϱ�\n");
	printf("    3. ������ȣ �����ϱ�\n");
	printf("    4. ������ȣ �˻��ϱ�\n");
	printf("    5. ������ ���� ��� ����\n");
	printf("================================\n");
	printf("    6. ���� ��������\n");
	printf("    7. ���� �����ϱ�\n");	
	printf("------------------------------\n");
	printf("    0. ����\n");
	printf("==============================\n");
	printf("    >>  ");

	scanf("%d", &nNum);

	return nNum;

} // displayMainMenu()

void insertNode()
{
	CarData* insert_temp; //�Է��� �����͸� �޾��� ����ü������
	
	insert_temp = (CarData*)malloc(sizeof(CarData)); // �����Ҵ�

	printf("\n\n");
	printf("�������. ����� ������ȣ�� �Է��ϼ���.\n\n");
	printf("(�ռ���2��,�߰� ����1��,����������4�� ��)\n");
	printf("ex) 12 �� 3456 ó�� ���̻��̿� �����̽��ٸ� ��������.\n>>");
	// �Է°��� �ٷ� �־���
	scanf("%s%s%s",insert_temp->ncarFirst,insert_temp->ncarSecond,insert_temp->ncarLast);

	insert_temp->link = pHead;

	pHead = insert_temp;
	

	printf("\n\n");
	
	//system("cls");

	nTotalNumber++; // ������ ����

	printNode();
	
	// ������ ����Ʈ��带 �����ϱ����� insert_temp�� �Ҵ������ϸ� �ȵȴ�

} // insertNode()

void deleteNode()
{
	CarData* delete_temp; // ���� �����͸� �޾��� ����ü������
	CarData* pVisited; // ��ȸ������
	CarData* pPrev; // ���������

	delete_temp = (CarData*)malloc(sizeof(CarData)); // �����Ҵ�

	printf("\n\n");
	printf("�ȳ���������.\n");
	printf("������ ������ȣ�� �Է��ϼ���. \n >> ");
	// �Է°��� �ٷ� �־���
	scanf("%s%s%s",delete_temp->ncarFirst,delete_temp->ncarSecond,delete_temp->ncarLast);

	pVisited = pHead;
	pPrev = NULL;
	
	while(TRUE) { // ����� ���� Ȯ��
		if(pVisited == NULL) break; //�����ϰ� ���� �������� ��尡 ���� ��
		if((strcmp(pVisited->ncarFirst, delete_temp->ncarFirst) == 0) && (strcmp(pVisited->ncarSecond, delete_temp->ncarSecond) == 0) && (strcmp(pVisited->ncarLast, delete_temp->ncarLast) == 0))
			break; // �����ϰ� ���� �����Ͱ� �ִ� ��带 ã���� ��
		pPrev = pVisited;
		pVisited = pVisited->link;
	} //while

	
	if(pVisited == NULL) { 
		
	// ��ã���� ��
		printf("\n\n");
		printf("������ȣ %s%s%s �� �������� �ʽ��ϴ�..\n",delete_temp->ncarFirst,delete_temp->ncarSecond,delete_temp->ncarLast);
	} 
		
	else {
 
		if (pPrev == NULL) { //������ �����Ͱ� ó����忡 ���� ��
			pHead = pHead->link;
		} else {
			pPrev->link = pVisited->link; // ��������Ͱ� ������尡 ����Ű�� ���� ����Ŵ
		} // if-else
		pVisited->link = NULL;
		printf("\n\n");
		printf("������ȣ %s%s%s �� �����Ǿ����ϴ�..\n",pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);

		free(pVisited);
	} // if-else

	nTotalNumber--; // ������ ����

	printNode();
	
	free(delete_temp); // �Ҵ�����
} // deleteNode()

void updateNode()
{
	CarData* update_temp; //������ �����͸� �޾��� ����ü������
	CarData* reinsert_temp; // ���Էµ� �����͸� �޾��� ����ü������
	CarData* stored_temp; // �����ϱ� �� �����͸� �޾��� ����ü������
	
	CarData* pVisited; // ��ȸ������
	CarData* pPrev; //���������
	CarData* pPrev2; // ���������2 (������ �����͸� �����ϰ� �̿��ϱ�����)

	update_temp = (CarData*)malloc(sizeof(CarData)); // �����Ҵ�
	reinsert_temp = (CarData*)malloc(sizeof(CarData));
	stored_temp = (CarData*)malloc(sizeof(CarData));

	printf("\n\n");
	printf("�����Ͻ� ������ȣ�� �Է��ϼ���.\n");
	printf("(�ռ���2��,�߰� ����1��,����������4�� ��)\n");
	printf("ex) 12 �� 3456 ó�� ���̻��̿� �����̽��ٸ� ��������.\n>>");
	// �Է°��� �ٷ� �־���
	scanf("%s%s%s",update_temp->ncarFirst,update_temp->ncarSecond,update_temp->ncarLast);

	pVisited = pHead;
	pPrev = NULL;  //ù��° ��带 �����ϸ� ��������Ͱ� ��������� ù��° ������� �ƴ����� Ȯ���ؾ���(�������Ʈ�� NULL�̸� ù��°��)
	pPrev2 = pHead; // ������ �����͸� �����ϰ� �̿��ϱ����� ���������2�� ��������͸� ����Ŵ (��, ������ �������� ��ġ�� ����� �����Ͱ� �ʿ���)

	while(TRUE) {
		if(pVisited == NULL) break; // ��带 ��ã���� ��
		if((strcmp(pVisited->ncarFirst,update_temp->ncarFirst) == 0) && (strcmp(pVisited->ncarSecond,update_temp->ncarSecond) == 0) && (strcmp(pVisited->ncarLast,update_temp->ncarLast) == 0))
			break; //ã���� ��
		pPrev = pVisited; //��������� ����
		pVisited = pVisited->link; // �������� �Ѿ
		pPrev2 = pPrev2->link; // �������� �Ѿ
	} // while //����ִ��� ���� üũ

	if(pVisited == NULL) { //������ �����Ͱ� ������
		printf("\n\n");
		printf("������ ������ȣ %s%s%s�� �������� �ʽ��ϴ�.\n",update_temp->ncarFirst,update_temp->ncarSecond,update_temp->ncarLast);

		//system("cls"); //ȭ�� ���ֱ�

	} else { // ������ �����͸� ã���� ��
		// ���� �����Ͱ� ���� �� ��ü�� �����͸� �Է¹޴� ���� �����ϱ����ؼ� ������ �����͸� �Է¹��� �� ���� �Է¹޴� ���� �ƴ϶�
		// �����Ͱ� ���� ������ ��ü�� �����͸� �Է¹ް� �ϱ� ���� �� �κк��� ��ü�� �����͸� �Է¹޴´�
		printf("\n\n");
		printf("���� �Է��� ������ȣ�� �Է��ϼ���.\n");
		printf("(�ռ���2��,�߰� ����1��,����������4�� ��)\n");
		printf("ex) 12 �� 3456 ó�� ���̻��̿� �����̽��ٸ� ��������.\n>>");
		// �Է°��� �ٷ� �־���
		scanf("%s%s%s",reinsert_temp->ncarFirst,reinsert_temp->ncarSecond,reinsert_temp->ncarLast);

		if(pPrev == NULL) { //ù��° ��� ������ ��
			copy(stored_temp->ncarFirst,stored_temp->ncarSecond,stored_temp->ncarLast,reinsert_temp->ncarFirst,reinsert_temp->ncarSecond,reinsert_temp->ncarLast,pPrev2,pVisited);

			printf("\n\n");
			printf("������ȣ %s%s%s�� �����Ǿ����ϴ�.(%s%s%s -> %s%s%s)\n",stored_temp->ncarFirst,stored_temp->ncarSecond,stored_temp->ncarLast,stored_temp->ncarFirst
							,stored_temp->ncarSecond,stored_temp->ncarLast,reinsert_temp->ncarFirst,reinsert_temp->ncarSecond,reinsert_temp->ncarLast);
		} else { // ù��° ��尡 �ƴ� �ٸ� ��带 ������ ��
			copy(stored_temp->ncarFirst,stored_temp->ncarSecond,stored_temp->ncarLast,reinsert_temp->ncarFirst,reinsert_temp->ncarSecond,reinsert_temp->ncarLast,pPrev2,pVisited);

			printf("\n\n");
			printf("������ȣ %s%s%s�� �����Ǿ����ϴ�.(%s%s%s -> %s%s%s)\n",stored_temp->ncarFirst,stored_temp->ncarSecond,stored_temp->ncarLast
					,stored_temp->ncarFirst,stored_temp->ncarSecond,stored_temp->ncarLast,reinsert_temp->ncarFirst,reinsert_temp->ncarSecond,reinsert_temp->ncarLast);
		} // if - else
	} // if-else
	
	printNode();

	free(update_temp); // �Ҵ�����
	free(reinsert_temp);
	free(stored_temp);

} // updateNode()

void copy(char First[5],char Second[5],char Last[5],char ReFirst[5],char ReSecond[5],char ReLast[5],CarData* pPrev2,CarData* pVisited)
{
	strcpy(First,pPrev2->ncarFirst); // ������ ������ȣ�� �ٸ������� �Ű� ����
	strcpy(Second,pPrev2->ncarSecond);
	strcpy(Last,pPrev2->ncarLast);

	strcpy(pVisited->ncarFirst,ReFirst); // ������ ������ȣ�� ��ü�� ������ȣ�� �ٲ� ����
	strcpy(pVisited->ncarSecond,ReSecond);
	strcpy(pVisited->ncarLast,ReLast);

} //copy()

void retrieveNode()
{
	int nChoose; // 1,2,3�� �˻��� ���� ���� ����

	printf("\n\n");
	printf("� ������� �˻��Ͻðڽ��ϱ�?\n");
	printf("1. �ܼ��� ������ȣ �˻�\n");
	printf("2. �¿���, ȭ���� �� �������� �˻�\n");
	printf("3. �Ϲݻ����, �뿩�����, �ܱ���, �ڰ��� �� �������� �˻�\n");
	printf(" >> ");
	scanf("%d",&nChoose);

	system("cls");

	switch (nChoose)
	{
	case 1:
		Retrieve_1(); // �ܼ��� ������ȣ �˻�
		break;
	case 2:
		Retrieve_2(); // �¿���, ȭ���� �� �������� �˻�
		break;
	case 3:
		Retrieve_3(); // �Ϲݻ����, �뿩�����, �ܱ���, �ڰ��� �� �������� �˻�
		break;
	default :
		printf("\n\n");
		printf("�߸� �Է��ϼ̽��ϴ�.\n\n");
	} // switch

} // retrieveNode

void Retrieve_1()
{
	int count=1; // ������ �˱����� ����
	CarData *retrieve_temp; // �˻��� �����͸� �޾��� ����ü������ ����
	CarData *pVisited; // ��ȸ������

	retrieve_temp = (CarData*)malloc(sizeof(CarData));

	printf("\n\n");
	printf("ã���� ������ ��ȣ�� �Է��ϼ���.\n");
	printf("(�ռ���2��,�߰� ����1��,����������4�� ��)\n");
	printf("ex) 12 �� 3456 ó�� ���̻��̿� �����̽��ٸ� ��������.\n>>");
	// �Է°��� �ٷ� �־���
	scanf("%s%s%s",retrieve_temp->ncarFirst,retrieve_temp->ncarSecond,retrieve_temp->ncarLast);

	pVisited = pHead;

	while(TRUE) {
		if(pVisited == NULL) break; // ã�����ϴ� ������ȣ�� ��ã���� ��
		if(strcmp(pVisited->ncarFirst,retrieve_temp->ncarFirst) == 0 &&
			strcmp(pVisited->ncarSecond,retrieve_temp->ncarSecond) == 0 && strcmp(pVisited->ncarLast,retrieve_temp->ncarLast) == 0)
			break; //�ԷµǾ��ִ� ������ȣ�� ã�����ϴ� ������ȣ�� �������
		pVisited = pVisited->link; // �������� �̵�
		count++; //�����ϳ�����
	} //while

	if(pVisited == NULL) { // ������ȣ�� �������� ���� ��
		printf("\n\n");
		printf(" %s%s%s ������ �������� �ʽ��ϴ�.\n",retrieve_temp->ncarFirst,retrieve_temp->ncarSecond,retrieve_temp->ncarLast);
	} else if(strcmp(pVisited->ncarFirst,retrieve_temp->ncarFirst) == 0 && //�����Ҷ�
		strcmp(pVisited->ncarSecond,retrieve_temp->ncarSecond) == 0 && strcmp(pVisited->ncarLast,retrieve_temp->ncarLast) == 0) {
				printf("\n\n");
				printf(" %s%s%s ������ %d������ �ֽ��ϴ�.\n",retrieve_temp->ncarFirst,retrieve_temp->ncarSecond,retrieve_temp->ncarLast,count);
	}

	printNode();

	free(retrieve_temp); // �Ҵ�����
} // Retrieve_1()

void Retrieve_2()
{
	int nSelect; // �ٸ� ������ �˻��� ���� ���� ����
	int count=1; // ����
	char MiddleWord[5] = {NULL}; // ��� ���ڿ� ���� ������ ������ �˱����� ���� ����
	// �� ���� ����
	char CarType[8][30] = {"�¿���","������","ȭ����","Ư����","�Ϲݻ����","�뿩�����","�ܱ���","�ڰ���"};
	CarData *pVisited; //��ȸ������
	char NewCarType[20]; // ��� ���ڿ� ���� ���� ������ ������ ���� ����

	printf("\n\n");
	printf("ã���� ������ ������ �Է����ּ���.\n");
	printf("1. �¿���, 2. ������, 3. ȭ����, 4. Ư����\n");
	printf(" >> ");
	scanf("%d",&nSelect);

	pVisited = pHead;

	switch(nSelect){
		case 1: // ������ ������ �¿����� ����
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // ���ϴ� ���������� ��ã���� ��
					break;
				}
				if(((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') >= 1) && //ã������
					  ((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') <= 69)){
						  
						  strcpy(MiddleWord,pVisited->ncarSecond); // ����(�Ѱ��� ����)�� �����ϱ� ���� ���
						  strcpy(NewCarType,printList_1(MiddleWord)); // ������ ���� ���� ����
						  printf(" ��%d�� ��%s, %s %s%s%s\n",count,CarType[0],NewCarType,pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // ���� ����
				}
				pVisited = pVisited->link; // �������� �̵�
			}

			printForm_2(count);

			break;
		case 2: // ������ ������ �������� ����
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // ���ϴ� ���������� ��ã���� ��
					break;
				}
				if(((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') >= 70) && //ã������
					  ((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') <= 79)){
						  strcpy(MiddleWord,pVisited->ncarSecond); // ����(�Ѱ��� ����)�� �����ϱ� ���� ���
						  strcpy(NewCarType,printList_1(MiddleWord)); // ������ ���� ���� ����
						  printf(" ��%d�� ��%s, %s %s%s%s\n",count,CarType[1],NewCarType,pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // ���� ����
				}
				pVisited = pVisited->link; // �������� �̵�
			}
			
			printForm_2(count);

			break;
		case 3: // ������ ������ ȭ������ ����
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // ���ϴ� ���������� ��ã���� ��
					break;
				}
				if(((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') >= 80) && //ã������
					  ((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') <= 97)){
						  strcpy(MiddleWord,pVisited->ncarSecond); // ����(�Ѱ��� ����)�� �����ϱ� ���� ���
						  strcpy(NewCarType,printList_1(MiddleWord)); // ������ ���� ���� ����
						  printf(" ��%d�� ��%s, %s %s%s%s\n",count,CarType[2],NewCarType,pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // ���� ����
				}
				pVisited = pVisited->link; // �������� �̵�
			}
			
			printForm_2(count);

			break;
		case 4: // ������ ������ Ư������ ����
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // ���ϴ� ���������� ��ã���� ��
					break;
				}
				if(((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') >= 98) && //ã������
					  ((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') <= 99)){
						  strcpy(MiddleWord,pVisited->ncarSecond); // ����(�Ѱ��� ����)�� �����ϱ� ���� ���
						  strcpy(NewCarType,printList_1(MiddleWord)); // ������ ���� ���� ����
						  printf(" ��%d�� ��%s, %s %s%s%s\n",count,CarType[3],NewCarType,pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // ���� ����
				}
				pVisited = pVisited->link; // �������� �̵�
			}
			
			printForm_2(count);

			break;
		default:
			printf("\n\n");
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			break;
	}
} // Retrieve_2()

void Retrieve_3()
{
	int nSelect; // �ٸ� ������ �˻��� ���� ���� ����
	int count=1; // ����
	char MiddleWord[5] = {NULL}; // ��� ���ڿ� ���� ������ ������ �˱����� ���� ����
	// �� ���� ����
	char CarType[8][30] = {"�¿���","������","ȭ����","Ư����","�Ϲݻ����","�뿩�����","�ܱ���","�ڰ���"};
	char NewCarType[20]; // ��� ���ڿ� ���� ���� ������ ������ ���� ����
	CarData *pVisited; //��ȸ������

	printf("\n\n");
	printf("ã���� ������ ������ �Է����ּ���.\n");
	printf("1. �Ϲݻ����, 2. �뿩�����, 3. �ܱ���, 4. �ڰ���\n");
	printf(" >> ");
	scanf("%d",&nSelect);

	pVisited = pHead;

	switch(nSelect){
		case 1: // ������ ������ �Ϲݻ���븸 ����
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // ���ϴ� ���������� ��ã���� ��
					break;
				}

				strcpy(MiddleWord,pVisited->ncarSecond); // ����(�Ѱ��� ����)�� �����ϱ� ���� ���
				strcpy(NewCarType, printList_2(pVisited->ncarFirst[0], pVisited->ncarFirst[1])); //���ڸ� ���ڿ� ���� �������� ������ ����

				if(strcmp(printList_1(MiddleWord), "�Ϲݻ����") == 0){
					printf(" ��%d�� ��%s, %s %s%s%s\n",count,NewCarType,CarType[4],pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // ���� ����
				}
				pVisited = pVisited->link; // �������� �̵�
			}
			printForm_2(count);

			break;

		case 2: // ������ ������ �뿩����븸 ����
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // ���ϴ� ���������� ��ã���� ��
					break;
				}
				strcpy(MiddleWord,pVisited->ncarSecond); // ����(�Ѱ��� ����)�� �����ϱ� ���� ���
				strcpy(NewCarType, printList_2(pVisited->ncarFirst[0], pVisited->ncarFirst[1])); //���ڸ� ���ڿ� ���� �������� ������ ����

				if(strcmp(printList_1(MiddleWord), "�뿩�����") == 0){
					printf(" ��%d�� ��%s, %s %s%s%s\n",count,NewCarType,CarType[5],pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // ���� ����
				}
				pVisited = pVisited->link; // �������� �̵�
			}
			
			printForm_2(count);

			break;

		case 3: // ������ ������ �ܱ��븸 ����
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // ���ϴ� ���������� ��ã���� ��
					break;
				}
				strcpy(MiddleWord,pVisited->ncarSecond); // ����(�Ѱ��� ����)�� �����ϱ� ���� ���
				strcpy(NewCarType, printList_2(pVisited->ncarFirst[0], pVisited->ncarFirst[1])); //���ڸ� ���ڿ� ���� �������� ������ ����

				if(strcmp(printList_1(MiddleWord), "�ܱ���") == 0){
					printf(" ��%d�� ��%s, %s %s%s%s\n",count,NewCarType,CarType[6],pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // ���� ����
				}
				pVisited = pVisited->link; // �������� �̵�
			}
			
			printForm_2(count);

			break;

		case 4: // ������ ������ �ڰ��븸 ����
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // ���ϴ� ���������� ��ã���� ��
					break;
				}
				strcpy(MiddleWord,pVisited->ncarSecond); // ����(�Ѱ��� ����)�� �����ϱ� ���� ���
				strcpy(NewCarType, printList_2(pVisited->ncarFirst[0], pVisited->ncarFirst[1])); //���ڸ� ���ڿ� ���� �������� ������ ����

				if(strcmp(printList_1(MiddleWord), "�ڰ���") == 0){
					printf(" ��%d�� ��%s, %s %s%s%s\n",count,NewCarType,CarType[7],pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // ���� ����
				}
				pVisited = pVisited->link; // �������� �̵�
			}
			printForm_2(count);
			break;

		default:
			printf("\n\n");
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			break;
	}
} // Retrieve_3()

void printNode()
{
	CarData* pvisited; //��ȸ������ ����
	
	int index=1; // �������� ������ 1���� �����ϰ� ����
	int i;
	char FirstNumber[5] = {NULL};// ���ڸ� ���ڿ� ���� ���� ������ ������ ���� ����
	char MiddleWord[5] = {NULL}; // ��� ���ڿ� ���� ���� ������ ������ ���� ����
	char NewCarType[20]; // ��� ���ڿ� ���� ���� ������ ������ ���� ����
	// �� ���� ����
	char CarType[8][30] = {"�¿���","������","ȭ����","Ư����","�Ϲݻ����","�뿩�����","�ܱ���","�ڰ���"};

	pvisited = pHead; //��ȸ�����Ͱ� ��������͸� ����Ű�� ����

	printForm_1();

	while(pvisited != NULL) // ������ ����϶� Ż��
	{
		for(i=0; i<2; i++) { // ����(�� �ΰ��� ����)�� �����ϱ� ���� ���
			FirstNumber[i] = pvisited->ncarFirst[i];
		} //for

		strcpy(MiddleWord,pvisited->ncarSecond); // ����(�Ѱ��� ����)�� �����ϱ� ���� ���
		strcpy(NewCarType,printList_1(MiddleWord)); // ������ ���� ���� ����

		switch ((((FirstNumber[0]-'0')*10)+(FirstNumber[1]-'0'))/10) {
			case 0: // ���� : �Է¹��� ���������� ���ڸ� ���������� ���ڷ� �̿�
			case 1: //		  �׷��� ���� ���Ͽ� �з�
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
				printf(" ��%d�� ��%s, %s %s%s%s\n",index,CarType[0],NewCarType,pvisited->ncarFirst,pvisited->ncarSecond,pvisited->ncarLast);
				break;
			case 7:
				printf(" ��%d�� ��%s, %s %s%s%s\n",index,CarType[1],NewCarType,pvisited->ncarFirst,pvisited->ncarSecond,pvisited->ncarLast);
				break;
			case 8:
				printf(" ��%d�� ��%s, %s %s%s%s\n",index,CarType[2],NewCarType,pvisited->ncarFirst,pvisited->ncarSecond,pvisited->ncarLast);
				break;
			case 9:
				if((FirstNumber[1]-'0') != 8 && (FirstNumber[1]-'0') != 9) {
						printf(" ��%d�� ��%s, %s %s%s%s\n",index,CarType[2],NewCarType,pvisited->ncarFirst,pvisited->ncarSecond,pvisited->ncarLast);
				} else {
						printf(" ��%d�� ��%s, %s %s%s%s\n",index,CarType[3],NewCarType,pvisited->ncarFirst,pvisited->ncarSecond,pvisited->ncarLast);
				} //if-esle
				break;
		} //switch
		pvisited = pvisited->link; //��ȸ�������̿�
		index++;
		printf("======================================\n");
		
	} //while
	printf("������ ���� �� : %d��\n",index-1); //�Էµ� �������� ���� �ľ�
	printf("======================================\n");
	
} // printNode()

char *printList_1(char MiddleWord[]){

	char NewCarType[20]; // ������ ���� ������ ������ ��������

	// �� �� �� �� �� �� ���� �з��۾�
	if(strcmp(MiddleWord,"��")==0 || strcmp(MiddleWord,"��")==0 || strcmp(MiddleWord,"��")==0 || strcmp(MiddleWord,"��")==0 || strcmp(MiddleWord,"��")==0){ 
		strcpy(NewCarType, "�Ϲݻ����");
	}
	else if (strcmp(MiddleWord,"��") ==0) { // �� �� ���� �з��۾�
		strcpy(NewCarType, "�뿩�����");
	} 
	else if (strcmp(MiddleWord,"��") ==0 || strcmp(MiddleWord,"��") == 0 || strcmp(MiddleWord,"��") == 0) { // �� �� ���� ���� �з��۾�
		strcpy(NewCarType, "�ܱ���");
	} 
	else { // �׿� ���ڵ鿡 ���� �з� �۾�
		strcpy(NewCarType, "�ڰ���");
	} // if - else

	return NewCarType;
} //char *printList_1()

char *printList_2(char first, char second){

	char NewCarType[20]; // ������ ���� ������ ������ ��������

	switch ((((first-'0')*10)+(second-'0'))/10) {
			case 0: // �Է¹��� ���������� ���ڸ� ���������� ���ڷ� �̿�
			case 1: // �׷��� ���� ���Ͽ� �з�
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
				strcpy(NewCarType, "�¿���");
				break;
			case 7:
				strcpy(NewCarType, "������");
				break;
			case 8:
				strcpy(NewCarType, "ȭ����");
				break;
			case 9:
				if((first-'0') != 8 && (second-'0') != 9) {
						strcpy(NewCarType, "ȭ����");
				} else {
						strcpy(NewCarType, "Ư����");
				} //if-esle
				break;
		} //switch

	return NewCarType;
} // char *printList_2()

void printForm_1() {
	printf("======================================\n");
	printf("        Car       List\n");
	printf("======================================\n");
} // printForm_1()

void printForm_2(int count) {
	printf("======================================\n");
	printf("�ش������� ���� �� : %d��\n",count-1);
	printf("======================================\n");
} // printForm_2()


void loadFile(){
	FILE *fp;
	int i; //�ݺ�����
	CarData *pVisited;

	printf("\n\n");
	printf("�����͸� �ҷ��� ���ϸ� : ");
	scanf("%s",strFileName);

	fp = fopen(strFileName,"r");

	if(fp==NULL){ //�ҷ����� �� ������ ���� ��
		printf("\n\n");
		printf("%s ������ �������� �ʽ��ϴ�\n",strFileName);
		return;	
	}

	if(pHead != NULL) { // �����͸� �ҷ���������, �Է��� �����Ͱ� ���� ��
		printf("\n\n"); // �� �����͸� ���ְ� ���� �ҷ���
		printf("������ �����͸� ��� ����� ���� �ҷ��ɴϴ�.\n\n");
		pHead = NULL; // �ƹ��͵� ����Ű�� �ʰ� ��
	} // if

	fscanf(fp,"%d",&nTotalNumber); // �������� �� ���ڸ� ����

	for(i=0;i<nTotalNumber;i++){ //�������� �� ����ŭ �������� �ҷ�����
		pVisited = (CarData *)malloc(sizeof(CarData));
		fscanf(fp,"%s %s %s", &pVisited->ncarFirst,&pVisited->ncarSecond,
			&pVisited->ncarLast);
		pVisited->link = pHead;
		pHead = pVisited;
	} // for

	printNode();

	fclose(fp);
	
	bFileFlag=1; // �ҷ��� ���� �ִ��� �� �� �ְ���

	} // loadFile()


void saveFile(){
	FILE *fp;
	CarData *pVisited;

	if(!bFileFlag){ // �ҷ����⸦ ������ ���� ��
		printf("\n\n");
		printf("�����͸� ������ ���ϸ� : ");
		scanf("%s",strFileName);
	}	//if

	pVisited = pHead;

	fp= fopen(strFileName,"w");

	if (fp==NULL){
		printf("\n\n");
		printf("�������� �ʴ� �����Դϴ�!\n");
		return;
	} // if

	fprintf(fp,"%d\n",nTotalNumber);

	while(pVisited != NULL){ // ������������ �����Ѵ�.
		fprintf(fp,"%s %s %s\n",pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
		pVisited = pVisited->link;
	}//while

	printf("\n\n");
	printf(" ������ ����Ǿ����ϴ�.\n\n");
	fclose(fp);

	bFileFlag=0; // �����͵��� ���������Ƿ� �ҷ��� ���� �ʱ�ȭ
} // saveFile()