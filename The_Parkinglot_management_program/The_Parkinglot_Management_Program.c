#include "The_Parkinglot_management_program.h"

int main()
{
	int nSelected;
	int infinity = TRUE;
	pHead = NULL;

	while(infinity)
	{
		nSelected = displayMainMenu(); //입력한숫자가 nSelected에 넣어짐
		system("cls"); // clear screen
		
		while (getchar() != '\n');	// 입력 버퍼 비우기

		switch(nSelected)
		{
		case INSERT :
			insertNode(); //space바를 이용해 숫자2개,글자1개,숫자4개를 차례로 입력받음
			break;
		case DELETE :
			deleteNode(); // 원하는 차량번호 삭제
			break;
		case UPDATE :
			updateNode(); // 차량번호의 수정
			break;
		case RETRIEVE :
			retrieveNode(); // 세부 1. 단순한 차량번호의 검색
			break;			// 세부 2. 승용차, 화물차 등 종류별로 검색
							// 세부 3. 일반사업용(택시)인지 대여사업용(렌트카)인지
							//       외교용, 자가용 등 종류별로 검색 (아직 이렇게 할지 말지 미정)
		case PRINT :
			printNode(); // 주차장에 있는 차량번호 출력
			break;
		case LOAD :
			loadFile();
			break;
		case SAVE :
			saveFile();
			break;
		case EXIT :
			infinity = ESCAPE; // 탈출조건(종료)
			break;
		default :
			printf("잘못된 선택 입니다.");
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

	printf("           ──────────\n");
	printf("          /    ＿＿＿＿＿＿＿   ＼\n");
	printf("         /   /               ＼   ＼\n");
	printf("        /   /＿＿＿＿＿＿＿＿＿＼   ＼\n");
	printf("   ────────────────────\n");
	printf("  │     〓〓〓〓〓〓〓〓〓〓〓〓〓〓     │\n");
	printf("  │     〓〓〓〓〓〓〓〓〓〓〓〓〓〓     │\n");
	printf("  │     〓〓〓〓┌────┐〓〓〓〓     │\n");
	printf("   ──┬──┬─┴────┴─┬──┬──\n");
	printf("       └──┘                └──┘\n");

	printf("==============================\n");
	printf("  주차장 차량 관리 프로그램\n");
	printf("------------------------------\n");
	printf("    1. 차량번호 등록하기\n");
	printf("    2. 차량번호 삭제하기\n");
	printf("    3. 차량번호 수정하기\n");
	printf("    4. 차량번호 검색하기\n");
	printf("    5. 주차된 차량 목록 보기\n");
	printf("================================\n");
	printf("    6. 파일 가져오기\n");
	printf("    7. 파일 저장하기\n");	
	printf("------------------------------\n");
	printf("    0. 종료\n");
	printf("==============================\n");
	printf("    >>  ");

	scanf("%d", &nNum);

	return nNum;

} // displayMainMenu()

void insertNode()
{
	CarData* insert_temp; //입력할 데이터를 받아줄 구조체포인터
	
	insert_temp = (CarData*)malloc(sizeof(CarData)); // 동적할당

	printf("\n\n");
	printf("어서오세요. 등록할 차량번호를 입력하세요.\n\n");
	printf("(앞숫자2개,중간 글자1개,마지막숫자4개 순)\n");
	printf("ex) 12 가 3456 처럼 사이사이에 스페이스바를 누르세요.\n>>");
	// 입력값을 바로 넣어줌
	scanf("%s%s%s",insert_temp->ncarFirst,insert_temp->ncarSecond,insert_temp->ncarLast);

	insert_temp->link = pHead;

	pHead = insert_temp;
	

	printf("\n\n");
	
	//system("cls");

	nTotalNumber++; // 차량수 증가

	printNode();
	
	// 개별의 프린트노드를 수행하기위해 insert_temp를 할당해제하면 안된다

} // insertNode()

void deleteNode()
{
	CarData* delete_temp; // 지울 데이터를 받아줄 구조체포인터
	CarData* pVisited; // 순회포인터
	CarData* pPrev; // 백업포인터

	delete_temp = (CarData*)malloc(sizeof(CarData)); // 동적할당

	printf("\n\n");
	printf("안녕히가세요.\n");
	printf("삭제할 차량번호를 입력하세요. \n >> ");
	// 입력값을 바로 넣어줌
	scanf("%s%s%s",delete_temp->ncarFirst,delete_temp->ncarSecond,delete_temp->ncarLast);

	pVisited = pHead;
	pPrev = NULL;
	
	while(TRUE) { // 노드의 유무 확인
		if(pVisited == NULL) break; //삭제하고 싶은 데이터의 노드가 없을 때
		if((strcmp(pVisited->ncarFirst, delete_temp->ncarFirst) == 0) && (strcmp(pVisited->ncarSecond, delete_temp->ncarSecond) == 0) && (strcmp(pVisited->ncarLast, delete_temp->ncarLast) == 0))
			break; // 삭제하고 싶은 데이터가 있는 노드를 찾았을 때
		pPrev = pVisited;
		pVisited = pVisited->link;
	} //while

	
	if(pVisited == NULL) { 
		
	// 못찾았을 때
		printf("\n\n");
		printf("차량번호 %s%s%s 는 존재하지 않습니다..\n",delete_temp->ncarFirst,delete_temp->ncarSecond,delete_temp->ncarLast);
	} 
		
	else {
 
		if (pPrev == NULL) { //삭제할 데이터가 처음노드에 있을 때
			pHead = pHead->link;
		} else {
			pPrev->link = pVisited->link; // 백업포인터가 다음노드가 가리키는 곳을 가리킴
		} // if-else
		pVisited->link = NULL;
		printf("\n\n");
		printf("차량번호 %s%s%s 는 삭제되었습니다..\n",pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);

		free(pVisited);
	} // if-else

	nTotalNumber--; // 차량수 감소

	printNode();
	
	free(delete_temp); // 할당해제
} // deleteNode()

void updateNode()
{
	CarData* update_temp; //수정할 데이터를 받아줄 구조체포인터
	CarData* reinsert_temp; // 재입력된 데이터를 받아줄 구조체포인터
	CarData* stored_temp; // 수정하기 전 데이터를 받아줄 구조체포인터
	
	CarData* pVisited; // 순회포인터
	CarData* pPrev; //백업포인터
	CarData* pPrev2; // 백업포인터2 (수정전 데이터를 저장하고 이용하기위함)

	update_temp = (CarData*)malloc(sizeof(CarData)); // 동적할당
	reinsert_temp = (CarData*)malloc(sizeof(CarData));
	stored_temp = (CarData*)malloc(sizeof(CarData));

	printf("\n\n");
	printf("수정하실 차량번호를 입력하세요.\n");
	printf("(앞숫자2개,중간 글자1개,마지막숫자4개 순)\n");
	printf("ex) 12 가 3456 처럼 사이사이에 스페이스바를 누르세요.\n>>");
	// 입력값을 바로 넣어줌
	scanf("%s%s%s",update_temp->ncarFirst,update_temp->ncarSecond,update_temp->ncarLast);

	pVisited = pHead;
	pPrev = NULL;  //첫번째 노드를 삭제하면 헤드포인터가 사라져버림 첫번째 노드인지 아닌지를 확인해야함(백업포인트가 NULL이면 첫번째임)
	pPrev2 = pHead; // 수정전 데이터를 저장하고 이용하기위해 백업포인터2가 헤드포인터를 가리킴 (즉, 수정전 데이터의 위치를 기억할 포인터가 필요함)

	while(TRUE) {
		if(pVisited == NULL) break; // 노드를 못찾았을 때
		if((strcmp(pVisited->ncarFirst,update_temp->ncarFirst) == 0) && (strcmp(pVisited->ncarSecond,update_temp->ncarSecond) == 0) && (strcmp(pVisited->ncarLast,update_temp->ncarLast) == 0))
			break; //찾았을 때
		pPrev = pVisited; //백업포인터 설정
		pVisited = pVisited->link; // 다음노드로 넘어감
		pPrev2 = pPrev2->link; // 다음노드로 넘어감
	} // while //비어있는지 여부 체크

	if(pVisited == NULL) { //수정할 데이터가 없을때
		printf("\n\n");
		printf("수정할 차량번호 %s%s%s는 존재하지 않습니다.\n",update_temp->ncarFirst,update_temp->ncarSecond,update_temp->ncarLast);

		//system("cls"); //화면 없애기

	} else { // 수정할 데이터를 찾았을 때
		// 만약 데이터가 없을 때 대체할 데이터를 입력받는 것을 방지하기위해서 수정할 데이터를 입력받을 때 같이 입력받는 것이 아니라
		// 데이터가 있을 때에만 대체할 데이터를 입력받게 하기 위해 이 부분부터 대체할 데이터를 입력받는다
		printf("\n\n");
		printf("새로 입력할 차량번호를 입력하세요.\n");
		printf("(앞숫자2개,중간 글자1개,마지막숫자4개 순)\n");
		printf("ex) 12 가 3456 처럼 사이사이에 스페이스바를 누르세요.\n>>");
		// 입력값을 바로 넣어줌
		scanf("%s%s%s",reinsert_temp->ncarFirst,reinsert_temp->ncarSecond,reinsert_temp->ncarLast);

		if(pPrev == NULL) { //첫번째 노드 수정할 때
			copy(stored_temp->ncarFirst,stored_temp->ncarSecond,stored_temp->ncarLast,reinsert_temp->ncarFirst,reinsert_temp->ncarSecond,reinsert_temp->ncarLast,pPrev2,pVisited);

			printf("\n\n");
			printf("차량번호 %s%s%s는 수정되었습니다.(%s%s%s -> %s%s%s)\n",stored_temp->ncarFirst,stored_temp->ncarSecond,stored_temp->ncarLast,stored_temp->ncarFirst
							,stored_temp->ncarSecond,stored_temp->ncarLast,reinsert_temp->ncarFirst,reinsert_temp->ncarSecond,reinsert_temp->ncarLast);
		} else { // 첫번째 노드가 아닌 다른 노드를 수정할 때
			copy(stored_temp->ncarFirst,stored_temp->ncarSecond,stored_temp->ncarLast,reinsert_temp->ncarFirst,reinsert_temp->ncarSecond,reinsert_temp->ncarLast,pPrev2,pVisited);

			printf("\n\n");
			printf("차량번호 %s%s%s는 수정되었습니다.(%s%s%s -> %s%s%s)\n",stored_temp->ncarFirst,stored_temp->ncarSecond,stored_temp->ncarLast
					,stored_temp->ncarFirst,stored_temp->ncarSecond,stored_temp->ncarLast,reinsert_temp->ncarFirst,reinsert_temp->ncarSecond,reinsert_temp->ncarLast);
		} // if - else
	} // if-else
	
	printNode();

	free(update_temp); // 할당해제
	free(reinsert_temp);
	free(stored_temp);

} // updateNode()

void copy(char First[5],char Second[5],char Last[5],char ReFirst[5],char ReSecond[5],char ReLast[5],CarData* pPrev2,CarData* pVisited)
{
	strcpy(First,pPrev2->ncarFirst); // 수정전 차량번호를 다른변수에 옮겨 저장
	strcpy(Second,pPrev2->ncarSecond);
	strcpy(Last,pPrev2->ncarLast);

	strcpy(pVisited->ncarFirst,ReFirst); // 수정할 차량번호를 대체할 차량번호로 바꿔 저장
	strcpy(pVisited->ncarSecond,ReSecond);
	strcpy(pVisited->ncarLast,ReLast);

} //copy()

void retrieveNode()
{
	int nChoose; // 1,2,3번 검색을 위한 변수 선언

	printf("\n\n");
	printf("어떤 방식으로 검색하시겠습니까?\n");
	printf("1. 단순한 차량번호 검색\n");
	printf("2. 승용차, 화물차 등 종류별로 검색\n");
	printf("3. 일반사업용, 대여사업용, 외교용, 자가용 등 종류별로 검색\n");
	printf(" >> ");
	scanf("%d",&nChoose);

	system("cls");

	switch (nChoose)
	{
	case 1:
		Retrieve_1(); // 단순한 차량번호 검색
		break;
	case 2:
		Retrieve_2(); // 승용차, 화물차 등 종류별로 검색
		break;
	case 3:
		Retrieve_3(); // 일반사업용, 대여사업용, 외교용, 자가용 등 종류별로 검색
		break;
	default :
		printf("\n\n");
		printf("잘못 입력하셨습니다.\n\n");
	} // switch

} // retrieveNode

void Retrieve_1()
{
	int count=1; // 개수를 알기위한 변수
	CarData *retrieve_temp; // 검색할 데이터를 받아줄 구조체포인터 선언
	CarData *pVisited; // 순회포인터

	retrieve_temp = (CarData*)malloc(sizeof(CarData));

	printf("\n\n");
	printf("찾으실 차량의 번호를 입력하세요.\n");
	printf("(앞숫자2개,중간 글자1개,마지막숫자4개 순)\n");
	printf("ex) 12 가 3456 처럼 사이사이에 스페이스바를 누르세요.\n>>");
	// 입력값을 바로 넣어줌
	scanf("%s%s%s",retrieve_temp->ncarFirst,retrieve_temp->ncarSecond,retrieve_temp->ncarLast);

	pVisited = pHead;

	while(TRUE) {
		if(pVisited == NULL) break; // 찾고자하는 차량번호를 못찾았을 때
		if(strcmp(pVisited->ncarFirst,retrieve_temp->ncarFirst) == 0 &&
			strcmp(pVisited->ncarSecond,retrieve_temp->ncarSecond) == 0 && strcmp(pVisited->ncarLast,retrieve_temp->ncarLast) == 0)
			break; //입력되어있는 차량번호와 찾고자하는 차량번호가 같을경우
		pVisited = pVisited->link; // 다음노드로 이동
		count++; //개수하나증가
	} //while

	if(pVisited == NULL) { // 차량번호가 존재하지 않을 때
		printf("\n\n");
		printf(" %s%s%s 차량은 존재하지 않습니다.\n",retrieve_temp->ncarFirst,retrieve_temp->ncarSecond,retrieve_temp->ncarLast);
	} else if(strcmp(pVisited->ncarFirst,retrieve_temp->ncarFirst) == 0 && //존재할때
		strcmp(pVisited->ncarSecond,retrieve_temp->ncarSecond) == 0 && strcmp(pVisited->ncarLast,retrieve_temp->ncarLast) == 0) {
				printf("\n\n");
				printf(" %s%s%s 차량은 %d구역에 있습니다.\n",retrieve_temp->ncarFirst,retrieve_temp->ncarSecond,retrieve_temp->ncarLast,count);
	}

	printNode();

	free(retrieve_temp); // 할당해제
} // Retrieve_1()

void Retrieve_2()
{
	int nSelect; // 다른 종류의 검색을 위한 변수 선언
	int count=1; // 개수
	char MiddleWord[5] = {NULL}; // 가운데 글자에 따른 차량의 종류를 알기위한 변수 선언
	// 차 종류 변수
	char CarType[8][30] = {"승용차","승합차","화물차","특수차","일반사업용","대여사업용","외교용","자가용"};
	CarData *pVisited; //순회포인터
	char NewCarType[20]; // 가운데 글자에 따른 차량 종류를 저장할 변수 선언

	printf("\n\n");
	printf("찾으실 차량의 종류를 입력해주세요.\n");
	printf("1. 승용차, 2. 승합차, 3. 화물차, 4. 특수차\n");
	printf(" >> ");
	scanf("%d",&nSelect);

	pVisited = pHead;

	switch(nSelect){
		case 1: // 수많은 차량중 승용차만 정렬
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // 원하는 차량종류를 못찾았을 때
					break;
				}
				if(((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') >= 1) && //찾았을때
					  ((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') <= 69)){
						  
						  strcpy(MiddleWord,pVisited->ncarSecond); // 차종(한개의 글자)을 구별하기 위한 방법
						  strcpy(NewCarType,printList_1(MiddleWord)); // 차량에 대한 정보 복사
						  printf(" 『%d』 ㅣ%s, %s %s%s%s\n",count,CarType[0],NewCarType,pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // 개수 증가
				}
				pVisited = pVisited->link; // 다음노드로 이동
			}

			printForm_2(count);

			break;
		case 2: // 수많은 차량중 승합차만 정렬
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // 원하는 차량종류를 못찾았을 때
					break;
				}
				if(((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') >= 70) && //찾았을때
					  ((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') <= 79)){
						  strcpy(MiddleWord,pVisited->ncarSecond); // 차종(한개의 글자)을 구별하기 위한 방법
						  strcpy(NewCarType,printList_1(MiddleWord)); // 차량에 대한 정보 복사
						  printf(" 『%d』 ㅣ%s, %s %s%s%s\n",count,CarType[1],NewCarType,pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // 개수 증가
				}
				pVisited = pVisited->link; // 다음노드로 이동
			}
			
			printForm_2(count);

			break;
		case 3: // 수많은 차량중 화물차만 정렬
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // 원하는 차량종류를 못찾았을 때
					break;
				}
				if(((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') >= 80) && //찾았을때
					  ((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') <= 97)){
						  strcpy(MiddleWord,pVisited->ncarSecond); // 차종(한개의 글자)을 구별하기 위한 방법
						  strcpy(NewCarType,printList_1(MiddleWord)); // 차량에 대한 정보 복사
						  printf(" 『%d』 ㅣ%s, %s %s%s%s\n",count,CarType[2],NewCarType,pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // 개수 증가
				}
				pVisited = pVisited->link; // 다음노드로 이동
			}
			
			printForm_2(count);

			break;
		case 4: // 수많은 차량중 특수차만 정렬
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // 원하는 차량종류를 못찾았을 때
					break;
				}
				if(((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') >= 98) && //찾았을때
					  ((((pVisited->ncarFirst[0]-'0')*10)+pVisited->ncarFirst[1]-'0') <= 99)){
						  strcpy(MiddleWord,pVisited->ncarSecond); // 차종(한개의 글자)을 구별하기 위한 방법
						  strcpy(NewCarType,printList_1(MiddleWord)); // 차량에 대한 정보 복사
						  printf(" 『%d』 ㅣ%s, %s %s%s%s\n",count,CarType[3],NewCarType,pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // 개수 증가
				}
				pVisited = pVisited->link; // 다음노드로 이동
			}
			
			printForm_2(count);

			break;
		default:
			printf("\n\n");
			printf("잘못 입력하셨습니다.\n");
			break;
	}
} // Retrieve_2()

void Retrieve_3()
{
	int nSelect; // 다른 종류의 검색을 위한 변수 선언
	int count=1; // 개수
	char MiddleWord[5] = {NULL}; // 가운데 글자에 따른 차량의 종류를 알기위한 변수 선언
	// 차 종류 변수
	char CarType[8][30] = {"승용차","승합차","화물차","특수차","일반사업용","대여사업용","외교용","자가용"};
	char NewCarType[20]; // 가운데 글자에 따른 차량 종류를 저장할 변수 선언
	CarData *pVisited; //순회포인터

	printf("\n\n");
	printf("찾으실 차량의 종류를 입력해주세요.\n");
	printf("1. 일반사업용, 2. 대여사업용, 3. 외교용, 4. 자가용\n");
	printf(" >> ");
	scanf("%d",&nSelect);

	pVisited = pHead;

	switch(nSelect){
		case 1: // 수많은 차량중 일반사업용만 정렬
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // 원하는 차량종류를 못찾았을 때
					break;
				}

				strcpy(MiddleWord,pVisited->ncarSecond); // 차종(한개의 글자)을 구별하기 위한 방법
				strcpy(NewCarType, printList_2(pVisited->ncarFirst[0], pVisited->ncarFirst[1])); //앞자리 숫자에 대한 차량종류 정보를 복사

				if(strcmp(printList_1(MiddleWord), "일반사업용") == 0){
					printf(" 『%d』 ㅣ%s, %s %s%s%s\n",count,NewCarType,CarType[4],pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // 개수 증가
				}
				pVisited = pVisited->link; // 다음노드로 이동
			}
			printForm_2(count);

			break;

		case 2: // 수많은 차량중 대여사업용만 정렬
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // 원하는 차량종류를 못찾았을 때
					break;
				}
				strcpy(MiddleWord,pVisited->ncarSecond); // 차종(한개의 글자)을 구별하기 위한 방법
				strcpy(NewCarType, printList_2(pVisited->ncarFirst[0], pVisited->ncarFirst[1])); //앞자리 숫자에 대한 차량종류 정보를 복사

				if(strcmp(printList_1(MiddleWord), "대여사업용") == 0){
					printf(" 『%d』 ㅣ%s, %s %s%s%s\n",count,NewCarType,CarType[5],pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // 개수 증가
				}
				pVisited = pVisited->link; // 다음노드로 이동
			}
			
			printForm_2(count);

			break;

		case 3: // 수많은 차량중 외교용만 정렬
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // 원하는 차량종류를 못찾았을 때
					break;
				}
				strcpy(MiddleWord,pVisited->ncarSecond); // 차종(한개의 글자)을 구별하기 위한 방법
				strcpy(NewCarType, printList_2(pVisited->ncarFirst[0], pVisited->ncarFirst[1])); //앞자리 숫자에 대한 차량종류 정보를 복사

				if(strcmp(printList_1(MiddleWord), "외교용") == 0){
					printf(" 『%d』 ㅣ%s, %s %s%s%s\n",count,NewCarType,CarType[6],pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // 개수 증가
				}
				pVisited = pVisited->link; // 다음노드로 이동
			}
			
			printForm_2(count);

			break;

		case 4: // 수많은 차량중 자가용만 정렬
			printForm_1();

			while(TRUE){
				if(pVisited == NULL){ // 원하는 차량종류를 못찾았을 때
					break;
				}
				strcpy(MiddleWord,pVisited->ncarSecond); // 차종(한개의 글자)을 구별하기 위한 방법
				strcpy(NewCarType, printList_2(pVisited->ncarFirst[0], pVisited->ncarFirst[1])); //앞자리 숫자에 대한 차량종류 정보를 복사

				if(strcmp(printList_1(MiddleWord), "자가용") == 0){
					printf(" 『%d』 ㅣ%s, %s %s%s%s\n",count,NewCarType,CarType[7],pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
					count++; // 개수 증가
				}
				pVisited = pVisited->link; // 다음노드로 이동
			}
			printForm_2(count);
			break;

		default:
			printf("\n\n");
			printf("잘못 입력하셨습니다.\n");
			break;
	}
} // Retrieve_3()

void printNode()
{
	CarData* pvisited; //순회포인터 선언
	
	int index=1; // 데이터의 개수는 1부터 시작하게 만듦
	int i;
	char FirstNumber[5] = {NULL};// 앞자리 숫자에 따른 차량 종류를 저장할 변수 선언
	char MiddleWord[5] = {NULL}; // 가운데 글자에 따른 차량 종류를 저장할 변수 선언
	char NewCarType[20]; // 가운데 글자에 따른 차량 종류를 저장할 변수 선언
	// 차 종류 변수
	char CarType[8][30] = {"승용차","승합차","화물차","특수차","일반사업용","대여사업용","외교용","자가용"};

	pvisited = pHead; //순회포인터가 헤드포인터를 가리키게 만듦

	printForm_1();

	while(pvisited != NULL) // 마지막 노드일때 탈출
	{
		for(i=0; i<2; i++) { // 차종(앞 두개의 숫자)을 구별하기 위한 방법
			FirstNumber[i] = pvisited->ncarFirst[i];
		} //for

		strcpy(MiddleWord,pvisited->ncarSecond); // 차종(한개의 글자)을 구별하기 위한 방법
		strcpy(NewCarType,printList_1(MiddleWord)); // 차량에 대한 정보 복사

		switch ((((FirstNumber[0]-'0')*10)+(FirstNumber[1]-'0'))/10) {
			case 0: // 원리 : 입력받은 문자형태의 숫자를 정수형태의 숫자로 이용
			case 1: //		  그래서 몫을 비교하여 분류
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
				printf(" 『%d』 ㅣ%s, %s %s%s%s\n",index,CarType[0],NewCarType,pvisited->ncarFirst,pvisited->ncarSecond,pvisited->ncarLast);
				break;
			case 7:
				printf(" 『%d』 ㅣ%s, %s %s%s%s\n",index,CarType[1],NewCarType,pvisited->ncarFirst,pvisited->ncarSecond,pvisited->ncarLast);
				break;
			case 8:
				printf(" 『%d』 ㅣ%s, %s %s%s%s\n",index,CarType[2],NewCarType,pvisited->ncarFirst,pvisited->ncarSecond,pvisited->ncarLast);
				break;
			case 9:
				if((FirstNumber[1]-'0') != 8 && (FirstNumber[1]-'0') != 9) {
						printf(" 『%d』 ㅣ%s, %s %s%s%s\n",index,CarType[2],NewCarType,pvisited->ncarFirst,pvisited->ncarSecond,pvisited->ncarLast);
				} else {
						printf(" 『%d』 ㅣ%s, %s %s%s%s\n",index,CarType[3],NewCarType,pvisited->ncarFirst,pvisited->ncarSecond,pvisited->ncarLast);
				} //if-esle
				break;
		} //switch
		pvisited = pvisited->link; //순회포인터이용
		index++;
		printf("======================================\n");
		
	} //while
	printf("주차된 차량 수 : %d대\n",index-1); //입력된 데이터의 개수 파악
	printf("======================================\n");
	
} // printNode()

char *printList_1(char MiddleWord[]){

	char NewCarType[20]; // 차량에 대한 정보를 저장할 변수선언

	// 가 자 사 바 아 에 대한 분류작업
	if(strcmp(MiddleWord,"아")==0 || strcmp(MiddleWord,"바")==0 || strcmp(MiddleWord,"사")==0 || strcmp(MiddleWord,"자")==0 || strcmp(MiddleWord,"가")==0){ 
		strcpy(NewCarType, "일반사업용");
	}
	else if (strcmp(MiddleWord,"허") ==0) { // 허 에 대한 분류작업
		strcpy(NewCarType, "대여사업용");
	} 
	else if (strcmp(MiddleWord,"육") ==0 || strcmp(MiddleWord,"해") == 0 || strcmp(MiddleWord,"공") == 0) { // 육 해 공에 대한 분류작업
		strcpy(NewCarType, "외교용");
	} 
	else { // 그외 글자들에 대한 분류 작업
		strcpy(NewCarType, "자가용");
	} // if - else

	return NewCarType;
} //char *printList_1()

char *printList_2(char first, char second){

	char NewCarType[20]; // 차량에 대한 정보를 저장할 변수선언

	switch ((((first-'0')*10)+(second-'0'))/10) {
			case 0: // 입력받은 문자형태의 숫자를 정수형태의 숫자로 이용
			case 1: // 그래서 몫을 비교하여 분류
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
				strcpy(NewCarType, "승용차");
				break;
			case 7:
				strcpy(NewCarType, "승합차");
				break;
			case 8:
				strcpy(NewCarType, "화물차");
				break;
			case 9:
				if((first-'0') != 8 && (second-'0') != 9) {
						strcpy(NewCarType, "화물차");
				} else {
						strcpy(NewCarType, "특수차");
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
	printf("해당종류의 차량 수 : %d대\n",count-1);
	printf("======================================\n");
} // printForm_2()


void loadFile(){
	FILE *fp;
	int i; //반복변수
	CarData *pVisited;

	printf("\n\n");
	printf("데이터를 불러올 파일명 : ");
	scanf("%s",strFileName);

	fp = fopen(strFileName,"r");

	if(fp==NULL){ //불러오기 할 파일이 없을 때
		printf("\n\n");
		printf("%s 파일은 존재하지 않습니다\n",strFileName);
		return;	
	}

	if(pHead != NULL) { // 데이터를 불러오기전에, 입력한 데이터가 있을 때
		printf("\n\n"); // 그 데이터를 없애고 새로 불러옴
		printf("기존의 데이터를 모두 지우고 새로 불러옵니다.\n\n");
		pHead = NULL; // 아무것도 가리키지 않게 함
	} // if

	fscanf(fp,"%d",&nTotalNumber); // 데이터의 총 숫자를 저장

	for(i=0;i<nTotalNumber;i++){ //데이터의 총 수만큼 차량정보 불러오기
		pVisited = (CarData *)malloc(sizeof(CarData));
		fscanf(fp,"%s %s %s", &pVisited->ncarFirst,&pVisited->ncarSecond,
			&pVisited->ncarLast);
		pVisited->link = pHead;
		pHead = pVisited;
	} // for

	printNode();

	fclose(fp);
	
	bFileFlag=1; // 불러온 적이 있는지 알 수 있게함

	} // loadFile()


void saveFile(){
	FILE *fp;
	CarData *pVisited;

	if(!bFileFlag){ // 불러오기를 한적이 없을 때
		printf("\n\n");
		printf("데이터를 저장할 파일명 : ");
		scanf("%s",strFileName);
	}	//if

	pVisited = pHead;

	fp= fopen(strFileName,"w");

	if (fp==NULL){
		printf("\n\n");
		printf("존재하지 않는 파일입니다!\n");
		return;
	} // if

	fprintf(fp,"%d\n",nTotalNumber);

	while(pVisited != NULL){ // 차량정보들을 저장한다.
		fprintf(fp,"%s %s %s\n",pVisited->ncarFirst,pVisited->ncarSecond,pVisited->ncarLast);
		pVisited = pVisited->link;
	}//while

	printf("\n\n");
	printf(" 파일이 저장되었습니다.\n\n");
	fclose(fp);

	bFileFlag=0; // 데이터들을 저장했으므로 불러온 흔적 초기화
} // saveFile()