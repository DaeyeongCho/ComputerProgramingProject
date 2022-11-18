#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> //system("cls"); 함수를 호출하기 위한 헤더파일. system("cls"); = 화면을 깨끗하게 지웁니다.
#include <stdlib.h>
#include <string.h>

struct Student { //구조체. 학생에 관한 정보 포함
	char name[13]; //이름 영어 12자, 한글 4자까지 넣을 수 있습니다.
	int age; //나이
	char phone[12]; //전화번호
	char address[31]; //주소
	double scores[3]; //과목 수 0:출석 점수(10.0), 1:시험 성적(60.0), 2:과제물(30.0)
};

struct Student studentInfo[20]; //구조체 20개 생성. 학생 최대 20명까지 등록 가능. 전역 변수
/*
구조체, 배열 사용법입니다. 일단 전역변수로 생성했기 때문에 아무 함수에서나 다 사용 가능하고 내용이 공유되기 때문에 수정하면 모든 함수에서 다 바뀝니다.

일단 구조체는 int나 double, char같은 변수들을 하나의 변수에 묶어놓은거라 생각하시면 편합니다.
한 명의 사람에 이름, 나이 등 여러 정보가 들어가야하고 이걸 따로 변수를 만들어버리면 데이터가 중구난방이 되어버리기 때문에 구조체라는 것으로 묶어두는 것입니다.
여기서는 studentInfo라는 구조체 변수를 만들어 char name, int age 등의 변수를 넣어두었습니다.

그리고 배열은 만약 숫자를 저장하는 변수 10개가 필요하다고 할 때 int a, int b, int c, int d - - - 이런 식으로 10개를 쓰면 매우 귀찮기 때문에 int n[10] 이라고 한 줄 쓰는 것 만으로 n이라는 이름의 변수 10개를 한번에 생성하는 것입니다.
그리고 나중에 값을 집어넣을 때는 몇 번째 n인지 지정을 해 주어야 하기 때문에 만약 4번째 n에 50을 넣겠다고 하면 n[3] = 50 으로 쓰면 됩니다. (int n[10]으로 10개 생성 시 [] 안의 값은 0~9까지 10개입니다.)
이후 출력 시에는 print("%d", n[3])과 같은 방법으로 접근하면 됩니다.

그래서 위에 만들어 둔 struct Student studentList[20];은 studentInfo라고 하는 구조체 변수를 배열을 통해 20개 생성하는 것입니다.
그리고 하나의 studentInfo 변수 안에는 char name, int age 등등이 들어가 있는 것입니다.

이론적인 부분은 여기까지이고 가장 중요한 사용방법입니다.
만약 15번째 사람의 age 값에 30을 집어 넣으려면 studentInfo[14].age = 20; 이라고 쓰시면 됩니다. 가운데 . 표시는 ~의 로 해석하시면 이해하기 편합니다.
이후 출력하실 때에도 printf("%d", studentInfo[14].age);로 쓰시면 값을 얻어낼 수 있습니다.
*/

int studentCount = 0; //등록된 학생의 숫자를 나타냄. 등록 된 학생 수 만큼 반복할 때도 유용함. 코딩 하실 때 활용하시라고 전역변수로 해두긴 했는데 현재 등록 되어있는 학생 수와 일치해야 합니다. 값이 틀리면 오류가 날 수 있으므로 함부로 값을 바꾸면 안됩니다.

//-----------------------------------------------------------------------------------조대영 변수, 함수 원형

void studentInformation(void); //학생 인적사항 관리 함수 원형
void addInfo(); //학생 추가 시 사용하는 함수 원형
void inquiryInfo(); //학생 조회 시 사용하는 함수 원형
void deleteInfo(); //학생 정보 삭제 시 사용하는 함수 원형

//-----------------------------------------------------------------------------------정재헌 변수, 함수 원형

void attendance(void); //출결관리 함수 원형

//-----------------------------------------------------------------------------------길민준 변수, 함수 원형

void grade(void); //성적관리 함수 원형
void Run();
int SelectMenu();//메뉴 출력 및 선택
void AddStudent();//학생 데이터 입력
void RemoveStudent();//학생 데이터 삭제
void FindStudent();//학생 검색
void ListStudent();//목록 보기
int IsAvailNum(int num);//유효한 번호인지 판별
int IsAvailScore(double score);//유효한 성적인지 판별

//-----------------------------------------------------------------------------------조진욱 변수, 함수 원형

void seat(void); //좌석배정 함수 원형

//-----------------------------------------------------------------------------------




int main(void) {
	int select; //메뉴 선택 시 입력 값 저장 변수
	int escape = 1; //아래 while문 반복의 조건. case 5:에서 escape 값을 0으로 바꿔 탈출합니다.

	printf("********************\n학생 관리 앱\nMade By 조대영, 길민준, 정재헌, 조진욱\n"); //타이틀 출력

	while (escape) {
		printf("********************\n\t-메뉴-\n1.학생 인적사항 관리\n2.출결 관리\n3.성적 관리\n4.좌석 배정\n5.끝내기\n********************\n입력: "); //메뉴 출력
		scanf_s("%d", &select); //메뉴 선택

		switch (select) {
		case 1: //학생 인적사항 관리 함수 분기
			studentInformation();
			system("cls");
			break;
		case 2: //출결관리 함수 분기
			attendance();
			system("cls");
			break;
		case 3: //성적관리 함수 분기
			grade();
			system("cls");
			break;
		case 4: //좌석배정 함수 분기
			seat();
			system("cls");
			break;
		case 5: //프로그램 종료
			printf("프로그램을 종료합니다.\n");
			escape = 0;
			break;
		default: //잘못 된 값 입력 시 다시 되돌아 감
			printf("잘못된 입력입니다.\n");
			getchar();
			break;
		}
	}
	return 0;
}


//-----------------------------------------------------------------------------------학생 추가 시 사용하는 함수. 조대영 담당


void studentInformation(void) { //학생 인적사항 관리 함수. 조대영 담당
	int select; //메뉴 선택 시 입력 값 저장 변수
	system("cls");

	printf("********************\n학생 인적사항 관리 모드\n");

	while (1) {
		printf("********************\n\t-메뉴-\n1.학생 추가\n2.학생 조회\n3.학생 정보 삭제\n4.메인 화면으로\n********************\n입력: ");
		scanf_s("%d", &select);

		switch (select) {
		case 1:
			addInfo(); //학생 추가 함수로 분기
			break;
		case 2:
			inquiryInfo(); //학생 조회 함수로 분기
			break;
		case 3:
			deleteInfo(); //학생 정보 삭제 함수로 분기
			break;
		case 4:
			return;
			break;
		default: //잘못 된 값 입력 시 다시 되돌아 감
			printf("잘못된 입력입니다.\n");
			getchar();
			break;
		}
	}
}

void addInfo() {
	if (studentCount >= 20) { //학생이 20명 등록되어 꽉 차게되면 더 이상 등록 불가능함을 알리고 false 리턴
		printf("더 이상 학생을 등록할 수 없습니다.");
		return;
	}
	printf("이름(최대 12Byte): ");
	scanf("%s", studentInfo[studentCount].name); //이름을 입력 받아 studentInfo 배열에 차례대로 집어넣음
	printf("나이: ");
	scanf_s(" %d", &studentInfo[studentCount].age); //나이를 입력 받아 studentInfo 배열에 차례대로 집어넣음
	printf("휴대폰 번호('-'포함x): ");
	scanf("%s", studentInfo[studentCount].phone);
	printf("주소(최대 30Byte): ");
	scanf("%s", studentInfo[studentCount].address);
	for (int i = 0; i < 3; i++) { //성적 초기화
		studentInfo[studentCount].scores[i] = -1;
	}
	printf("---추가 완료---\n");
	studentCount++; //정상적으로 학생 추가 시 학생 수 1 증가
}

void inquiryInfo() { //학생 조회 시 사용하는 함수 
	if (studentCount == 0) { //등록 된 학생이 한 명도 없으면 없음을 알리고 함수 종료
		printf("학생 정보가 없습니다.\n");
		return;
	}
	system("cls");
	printf("학생 정보 출력\n********************************************************************************\n번호\t\t이름\t\t나이\t\t휴대폰 번호\t\t주소\t\t\n");
	for (int i = 0; i < studentCount; i++) {
		printf("%d\t\t%s\t\t%d\t\t%s\t\t%s\n", i, studentInfo[i].name, studentInfo[i].age, studentInfo[i].phone, studentInfo[i].address);
	}
	printf("********************************************************************************\n총 %d명의 학생 정보가 있습니다.\n", studentCount);
}

void deleteInfo() { //학생 정보 삭제 시 사용하는 함수. 정상적으로 회원이 삭제되었는지 여부를 돌려줌
	int m; //몇 번째 학생을 삭제 할 지 번호를 받는 변수
	if (studentCount == 0) {
		printf("삭제 할 학생 정보가 없습니다.\n");
		return;
	}
	inquiryInfo(studentCount);
	printf("삭제하고 싶은 학생 정보의 번호를 입력하세요.");
	scanf("%d", &m);
	if (m < 0 || m >= studentCount) { //없는 학생 번호 입력 시 오류 출력 및 함수 종료. false를 돌려 줌
		printf("잘못된 값입니다.\n");
		return 0;
	}
	for (int i = m + 1; i < studentCount; i++) { //학생 정보 삭제 및 배열 뒷쪽의 학생 정보를 앞으로 당김.
		strcpy(studentInfo[i - 1].name, studentInfo[i].name);
		studentInfo[i - 1].age = studentInfo[i].age;
		strcpy(studentInfo[i - 1].phone, studentInfo[i].phone);
		strcpy(studentInfo[i - 1].address, studentInfo[i].address);
	}
	studentCount--; //정상적으로 학생 정보 삭제 완료 시 학생 수 1 감소
}


//-----------------------------------------------------------------------------------출결관리 함수. 정재헌 담당


void attendance(void) {
	//여기에 구현하시면 됩니다. 이 함수 바깥쪽에 뭔가 작성하실 일 있으시면 그 부분은 따로 주석으로 표시해주시면 제가 확인해서 적용하도록 하겠습니다.
}


//-----------------------------------------------------------------------------------성적관리 함수. 길민준 담당


void grade(void) {
	Run();
}

void Run()
{
	int key = 0;
	while ((key = SelectMenu()) != 0)//선택한 메뉴가 0이 아니면 반복
	{
		switch (key)//선택한 키에 따라 기능 수행
		{
		case 1: AddStudent(); break;
		case 2: RemoveStudent(); break;
		case 3: FindStudent(); break;
		case 4: ListStudent(); break;
		default: printf("잘못 선택하였습니다.\n"); break;
		}
	}
	printf("프로그램 종료\n");
}

int SelectMenu()
{
	int key = 0;
	printf("*****************************************************************\n");
	printf("성적 관리 프로그램 0:종료\n");
	printf("1: 학생 데이터 입력 2: 학생 데이터 삭제 3: 학생 검색 4: 목록 보기 0: 메인 화면으로 \n");
	printf("*****************************************************************\n");
	scanf_s("%d", &key);
	return key;
}

void AddStudent() { //학생 데이터 입력


	/*int num = 0;
	Student* stu = 0;
	int s = 0;

	printf("추가할 학생 번호(1~%d): ", MAX_STUDENT);
	scanf_s("%d", &num);

	if (IsAvailNum(num) == 0)//유효한 번호가 아닐 때
	{
		printf("범위를 벗어난 학생 번호입니다.\n");
		return;
	}

	if (stues[num - 1].num)//이미 번호를 설정한 상태일 때
	{
		printf("이미 추가하였습니다\n");
		return;
	}

	//stues에는 1번 학생 데이터를 관리하는 메모리 주소
	//따라서 stues+(num-1)은 num번 학생 데이터를 관리하는 메모리 주소
	stu = stues + (num - 1);
	stu->num = num;
	printf("이름: ");
	scanf_s("%s", stu->name, sizeof(stu->name));

	for (s = 0; s < MAX_SUBJECT; s++)
	{
		printf("%s 성적:", stitles[s]);
		scanf_s("%lf", stu->scores + s);

		if (IsAvailScore(stu->scores[s]) == 0)//유효한 성적이 아닐 때
		{
			stu->scores[s] = -1;
			printf("입력한 성적이 유효하지 않아서 %s 성적은 입력 처리하지 않았습니다.\n", stitles[s]);
		}
	}*/
}

void RemoveStudent() {//학생 데이터 삭제

}

void FindStudent() { //학생 검색

}

void ListStudent() { //목록 보기

}
int IsAvailNum(int num) { //유효한 번호인지 판별

}
int IsAvailScore(double score) { //유효한 성적인지 판별

}


//-----------------------------------------------------------------------------------좌석배정 함수. 조진욱 담당


void seat(void) {
	//여기에 구현하시면 됩니다. 이 함수 바깥쪽에 뭔가 작성하실 일 있으시면 그 부분은 따로 주석으로 표시해주시면 제가 확인해서 적용하도록 하겠습니다.
}