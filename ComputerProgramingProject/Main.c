#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> //system("cls"); �Լ��� ȣ���ϱ� ���� �������. system("cls"); = ȭ���� �����ϰ� ����ϴ�.
#include <stdlib.h>
#include <string.h>

struct Student { //����ü. �л��� ���� ���� ����
	char name[13]; //�̸� ���� 12��, �ѱ� 4�ڱ��� ���� �� �ֽ��ϴ�.
	int grade; //�г�
	char studentID[11]; //�й�
	char phone[13]; //��ȭ��ȣ
	double scores[3]; //���� �� 0:�⼮ ����(10.0), 1:���� ����(60.0), 2:������(30.0)
	int attendance[15]; //0 �Ἦ, 1 �⼮, 2 ����
};

struct Student studentInfo[20]; //����ü 20�� ����. �л� �ִ� 20����� ��� ����. ���� ����

int studentCount = 0; //��ϵ� �л��� ���ڸ� ��Ÿ��. ��� �� �л� �� ��ŭ �ݺ��� ���� ������. �ڵ� �Ͻ� �� Ȱ���Ͻö�� ���������� �صα� �ߴµ� ���� ��� �Ǿ��ִ� �л� ���� ��ġ�ؾ� �մϴ�. ���� Ʋ���� ������ �� �� �����Ƿ� �Ժη� ���� �ٲٸ� �ȵ˴ϴ�.

//-----------------------------------------------------------------------------------���뿵 ����, �Լ� ����

void studentInformation(void); //�л� �������� ���� �Լ� ����
void addInfo(); //�л� �߰� �� ����ϴ� �Լ� ����
void inquiryInfo(); //�л� ��ȸ �� ����ϴ� �Լ� ����
void deleteInfo(); //�л� ���� ���� �� ����ϴ� �Լ� ����
void sort();

//-----------------------------------------------------------------------------------������ ����, �Լ� ����

void attendance(void); //������ �Լ� ����
void attendanceAdd(void);
void attendanceSearch();

//-----------------------------------------------------------------------------------����� ����, �Լ� ����

const char* stitles[3] = { "�⼮(10.0)","����(60.0)","������(30.0)" };

void grade(void); //�������� �Լ� ����
void Run();
int SelectMenu();//�޴� ��� �� ����
void AddStudent();//�л� ������ �Է�
void RemoveStudent();//�л� ������ ����
void FindStudent();//�л� �˻�
void ListStudent();//��� ����
int IsAvailNum(int num);//��ȿ�� ��ȣ���� �Ǻ�
int IsAvailScore(double score, int c);//��ȿ�� �������� �Ǻ�
void ViewStuData(int n);

//-----------------------------------------------------------------------------------




int main(void) {
	system("mode con cols=150 lines=40");
	int select; //�޴� ���� �� �Է� �� ���� ����

	printf("********************\n�л� ���� ��\nMade By ���뿵, �����, ������, ������\n"); //Ÿ��Ʋ ���

	while (1) {
		printf("********************\n\t-�޴�-\n1.�л� �������� ����\n2.��� ����\n3.���� ����\n4.������\n********************\n�Է�: "); //�޴� ���
		scanf_s("%d", &select); //�޴� ����

		switch (select) {
		case 1: //�л� �������� ���� �Լ� �б�
			studentInformation();
			system("cls");
			break;
		case 2: //������ �Լ� �б�
			attendance();
			system("cls");
			break;
		case 3: //�������� �Լ� �б�
			grade();
			system("cls");
			break;
		case 4: //���α׷� ����
			printf("���α׷��� �����մϴ�.\n");
			return 0;
			break;
		default: //�߸� �� �� �Է� �� �ٽ� �ǵ��� ��
			printf("�߸��� �Է��Դϴ�.\n");
			getchar();
			break;
		}
	}
	return 0;
}


//-----------------------------------------------------------------------------------�л� �߰� �� ����ϴ� �Լ�. ���뿵 ���


void studentInformation(void) { //�л� �������� ���� �Լ�. ���뿵 ���
	int select; //�޴� ���� �� �Է� �� ���� ����
	system("cls");

	printf("********************\n�л� �������� ���� ȭ��\n");

	while (1) {
		printf("********************\n\t-�޴�-\n1.�л� �߰�\n2.�л� ��ȸ\n3.�л� ���� ����\n4.�л� ����Ʈ ����\n5.���� ȭ������\n********************\n�Է�: ");
		scanf_s("%d", &select);

		switch (select) {
		case 1:
			addInfo(); //�л� �߰� �Լ��� �б�
			break;
		case 2:
			inquiryInfo(); //�л� ��ȸ �Լ��� �б�
			break;
		case 3:
			deleteInfo(); //�л� ���� ���� �Լ��� �б�
			break;
		case 4:
			sort();
			break;
		case 5:
			return;
			break;
		default: //�߸� �� �� �Է� �� �ٽ� �ǵ��� ��
			printf("�߸��� �Է��Դϴ�.\n");
			getchar();
			break;
		}
	}
}

void addInfo() {
	if (studentCount >= 20) { //�л��� 20�� ��ϵǾ� �� ���ԵǸ� �� �̻� ��� �Ұ������� �˸��� false ����
		printf("�� �̻� �л��� ����� �� �����ϴ�.");
		return;
	}
	printf("�̸�(�ִ� 12Byte): ");
	scanf("%s", studentInfo[studentCount].name); //�̸��� �Է� �޾� studentInfo �迭�� ���ʴ�� �������
	printf("�г�: ");
	scanf_s(" %d", &studentInfo[studentCount].grade); //���̸� �Է� �޾� studentInfo �迭�� ���ʴ�� �������
	printf("�й�: ");
	scanf("%s", studentInfo[studentCount].studentID);
	printf("�޴��� ��ȣ('-'����x): ");
	scanf("%s", studentInfo[studentCount].phone);
	for (int i = 0; i < 3; i++) { //���� �ʱ�ȭ
		studentInfo[studentCount].scores[i] = -1;
	}
	studentInfo[studentCount].scores[0] = 10;
	for (int i = 0; i < 15; i++) { //�⼮ �ʱ�ȭ
		studentInfo[studentCount].attendance[i] = 1;
	}
	system("cls");
	printf("---�߰� �Ϸ�---\n");
	studentCount++; //���������� �л� �߰� �� �л� �� 1 ����
}

void inquiryInfo() { //�л� ��ȸ �� ����ϴ� �Լ� 
	if (studentCount == 0) { //��� �� �л��� �� �� ������ ������ �˸��� �Լ� ����
		system("cls");
		printf("---�л� ������ �����ϴ�.---\n");
		return;
	}
	system("cls");
	printf("---�л� ���� ���---\n********************************************************************************\n��ȣ\t\t�̸�\t\t�г�\t\t�й�\t\t�޴��� ��ȣ\t\t\n");
	for (int i = 0; i < studentCount; i++) {
		printf("%d\t\t%s\t\t%d\t\t%s\t%s\n", i, studentInfo[i].name, studentInfo[i].grade, studentInfo[i].studentID, studentInfo[i].phone);
	}
	printf("********************************************************************************\n�� %d���� �л� ������ �ֽ��ϴ�.\n", studentCount);
}

void deleteInfo() { //�л� ���� ���� �� ����ϴ� �Լ�. ���������� ȸ���� �����Ǿ����� ���θ� ������
	int m; //�� ��° �л��� ���� �� �� ��ȣ�� �޴� ����
	if (studentCount == 0) {
		system("cls");
		printf("---���� �� �л� ������ �����ϴ�.---\n");
		return;
	}
	inquiryInfo(studentCount);
	printf("�����ϰ� ���� �л� ������ ��ȣ�� �Է��ϼ���.");
	scanf_s("%d", &m);
	if (m < 0 || m >= studentCount) { //���� �л� ��ȣ �Է� �� ���� ��� �� �Լ� ����. false�� ���� ��
		system("cls");
		printf("---�߸��� ���Դϴ�.---\n");
		return;
	}
	for (int i = m + 1; i < studentCount; i++) { //�л� ���� ���� �� �迭 ������ �л� ������ ������ ���.
		strcpy(studentInfo[i - 1].name, studentInfo[i].name);
		studentInfo[i - 1].grade = studentInfo[i].grade;
		strcpy(studentInfo[i - 1].studentID, studentInfo[i].studentID);
		strcpy(studentInfo[i - 1].phone, studentInfo[i].phone);
	}
	studentCount--; //���������� �л� ���� ���� �Ϸ� �� �л� �� 1 ����
	system("cls");
	printf("---���� �Ϸ�---\n");
}

int isEmpty() {
	if (studentCount == 0) {
		return 1;
	}
	else
	{
		return 0;
	}
}

void sort() {
	struct Student v[20];
	struct Student n;
	char c;

	if (studentCount == 0) { //��� �� �л��� �� �� ������ ������ �˸��� �Լ� ����
		system("cls");
		printf("---�л� ������ �����ϴ�.---\n");
		return;
	}

	for (int i = 0; i < studentCount; i++) {
		v[i] = studentInfo[i];
	}

	for (int i = 1; i < studentCount; i++) {
		for (int y = i; y > 0; y--) {
			if (strcmp(v[y].name, v[y - 1].name) < 0) {
				n = v[y];
				v[y] = v[y - 1];
				v[y - 1] = n;
			}
			else {
				break;
			}
		}
	}

	system("cls");
	printf("�л� ���� ���\n********************************************************************************\n��ȣ\t\t�̸�\t\t�г�\t\t�й�\t\t�޴��� ��ȣ\t\t\n");
	for (int i = 0; i < studentCount; i++) {
		printf("%d\t\t%s\t\t%d\t\t%s\t%s\n", i, v[i].name, v[i].grade, v[i].studentID, v[i].phone);
	}
	printf("********************************************************************************\n���� �Ϸ�. �� %d���� �л� ������ �ֽ��ϴ�.\n�̴�� ���� �Ͻðڽ��ϱ�(y/n)? ", studentCount);
	scanf_s(" %c", &c);
	if ((c == 'y') || (c == 'Y')) {
		for (int i = 0; i < studentCount; i++) {
			studentInfo[i] = v[i];
		}
		system("cls");
		printf("---���� ���� ���� �Ϸ�!---\n");
	}
	else {
		system("cls");
		printf("---���� ������ �������� �ʰ� ���� ȭ������ ���ư��ϴ�.---\n");
	}
}


//-----------------------------------------------------------------------------------������ �Լ�. ������ ���


void attendance(void) {
	int select;
	system("cls");
	printf("******************\n");
	printf("��� ���� ȭ��\n");

	while (1) {
		printf("******************\n");
		printf("1. ��� ����\n2. ��� ��Ȳ ��ȸ\n3. ���� ȭ������\n******************\n����: ");
		scanf_s("%d", &select);

		switch (select) {
		case 1:
			attendanceAdd();
			break;
		case 2:
			attendanceSearch();
			break;
		case 3:
			return;
			break;
		default:
			printf_s("�߸� �� �Է�\n");
			break;
		}
	}
}

void attendanceAdd(void) {
	int selectStudent, selectDay, selectAttendance;
	int n = 10;

	inquiryInfo();
	if (isEmpty()) {
		return;
	}

	printf("�л� ��ȣ ����: ");
	scanf_s("%d", &selectStudent);
	if ((selectStudent >= studentCount) || (selectStudent < 0)) {
		system("cls");
		printf("---�߸��� ��ȣ�Դϴ�.---\n");
		return; 
	}
	do {
		printf("���� ����(1~15): ");
		scanf_s("%d", &selectDay);
		if ((selectDay > 15) || (selectDay < 1)) {
			printf("�߸��� ��\n");
			getchar();
		}
	} while ((selectDay > 15) || (selectDay < 1));
	do
	{
		printf("1.�⼮ 2.�Ἦ 3.����\n����: ");
		scanf_s("%d", &selectAttendance);
		if ((selectAttendance > 3) || (selectAttendance < 0)) {
			printf("�߸��� ��\n");
			getchar();
		}
	} while ((selectAttendance > 3) || (selectAttendance < 0));

	system("cls");

	switch (selectAttendance) {
	case 1:
		studentInfo[selectStudent].attendance[selectDay - 1] = 1;
		printf("%s�л� %d���� �⼮ ó�� �Ϸ�\n", studentInfo[selectStudent].name, selectDay);
		break;
	case 2:
		studentInfo[selectStudent].attendance[selectDay - 1] = 0;
		printf("%s�л� %d���� �Ἦ ó�� �Ϸ�\n", studentInfo[selectStudent].name, selectDay);
		break;
	case 3:
		studentInfo[selectStudent].attendance[selectDay - 1] = 2;
		printf("%s�л� %d���� ���� ó�� �Ϸ�\n", studentInfo[selectStudent].name, selectDay);
		break;
	default:
		break;
	}

	for (int i = 0; i < 15; i++) {
		switch (studentInfo[selectStudent].attendance[i])
		{
		case 0:
			n -= 3;
			break;
		case 1:
			break;
		case 2:
			n -= 1;
			break;
		default:
			break;
		}
	}
	if (n < 0) {
		studentInfo[selectStudent].scores[0] = 0;
	}
	else {
		studentInfo[selectStudent].scores[0] = n;
	}
}

void attendanceSearch() {

	if (studentCount == 0) { //��� �� �л��� �� �� ������ ������ �˸��� �Լ� ����
		system("cls");
		printf("---�л� ������ �����ϴ�.---\n");
		return;
	}
	system("cls");
	printf("�л� ���� ���\n***************************************************************************************************************************************\n��ȣ\t�̸�\t1����\t2����\t3����\t4����\t5����\t6����\t7����\t8����\t9����\t10����\t11����\t12����\t13����\t14����\t15����\n");
	for (int i = 0; i < studentCount; i++) {
		printf("%d\t%s\t", i, studentInfo[i].name);
		for (int y = 0; y < 15; y++) {
			switch (studentInfo[i].attendance[y]) {
			case 1:
				printf("�⼮\t");
				break;
			case 2:
				printf("����\t");
				break;
			case 0:
				printf("�Ἦ\t");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
	printf("***************************************************************************************************************************************\n�� %d���� �л� ������ �ֽ��ϴ�.\n", studentCount);
}


//-----------------------------------------------------------------------------------�������� �Լ�. ����� ���


void grade(void) {
	int key = 0;
	system("cls");
	printf("*******************\n");
	printf("���� ���� ȭ��\n");

	while ((key = SelectMenu()) != 5)//������ �޴��� 0�� �ƴϸ� �ݺ�
	{
		switch (key)//������ Ű�� ���� ��� ����
		{
		case 1: AddStudent(); break;
		case 2: RemoveStudent(); break;
		case 3: FindStudent(); break;
		case 4: ListStudent(); break;
		default: printf("�߸� �����Ͽ����ϴ�.\n"); break;
		}
	}
	printf("���α׷� ����\n");
}

int SelectMenu()
{
	int key = 0;
	printf("*******************\n");
	printf("1. �л� ���� �Է�\n2. �л� ���� �ʱ�ȭ\n3. �л� �˻�\n4. ������� ����\n5. ���� ȭ������ \n");
	printf("*******************\n�Է�: ");
	scanf_s("%d", &key);
	return key;
}

void AddStudent() { //�л� ������ �Է�
	int num;
	double score;

	inquiryInfo();
	if (isEmpty()) {
		return;
	}

	printf("���� �Է� �� �л� ��ȣ(0 ~ %d): ", studentCount - 1);
	scanf_s("%d", &num);

	if (IsAvailNum(num) == 0)//��ȿ�� ��ȣ�� �ƴ� ��
	{
		system("cls");
		printf("---������ ��� �л� ��ȣ�Դϴ�.---\n");
		return;
	}

	printf("%s �л��� ������ �Է��մϴ�.", studentInfo[num].name);

	do
	{
		printf("���� ����(0.0~60.0):");
		scanf_s("%lf", &score);
		if ((score < 0.0) || (score > 60.0)) {
			printf("�߸��� �����Դϴ�.\n");
			getchar();
		}
	} while ((score < 0.0) || (score > 60.0));
	studentInfo[num].scores[1] = score;

	do
	{
		printf("���� ����(0.0~30.0):");
		scanf_s("%lf", &score);
		if ((score < 0.0) || (score > 30.0)) {
			printf("�߸��� �����Դϴ�.\n");
			getchar();
		}
	} while ((score < 0.0) || (score > 30.0));
	studentInfo[num].scores[2] = score;

	system("cls");
	printf("---���� �Է� �Ϸ�---\n");
}

void RemoveStudent() {//�л� ������ ����
	int num = -1;
	int s = 0;

	inquiryInfo();
	if (isEmpty()) {
		return;
	}

	printf("���� �ʱ�ȭ �� �л� ��ȣ(0~%d): ", studentCount - 1);
	scanf_s("%d", &num);

	if (IsAvailNum(num) == 0)//��ȿ�� ��ȣ�� �ƴ� ��
	{
		system("cls");
		printf("������ ��� �л� ��ȣ�Դϴ�.\n");
		return;
	}

	for (s = 1; s < 3; s++)
	{
		studentInfo[num].scores[s] = -1;
	}

	printf("�����Ͽ����ϴ�.\n");
}

void FindStudent() { //�л� �˻�
	int num = -1;
	int s = 0;

	inquiryInfo();
	if (isEmpty()) {
		return;
	}

	printf("�˻��� �л� ��ȣ(0~%d): ", studentCount - 1);
	scanf_s("%d", &num);

	if (IsAvailNum(num) == 0)//��ȿ�� ��ȣ�� �ƴ� ��
	{
		printf("������ ��� �л� ��ȣ�Դϴ�.\n");
		return;
	}

	system("cls");
	ViewStuData(num);
}

void ListStudent() { //��� ����
	if (isEmpty()) {
		system("cls");
		printf("---�л� ������ �����ϴ�.---\n");
		return;
	}

	system("cls");
	printf("�л� ���� ���(������ -1�� ���� ���Է�)\n********************************************************************************\n��ȣ\t\t�̸�\t\t%s\t\t%s\t\t%s\t\t����\n", stitles[0], stitles[1], stitles[2]);
	for (int i = 0; i < studentCount; i++) {
		printf("%d\t\t%s\t\t%.1lf\t\t\t%.1lf\t\t\t%.1lf\t\t\t%.1lf\n", i, studentInfo[i].name, studentInfo[i].scores[0], studentInfo[i].scores[1], studentInfo[i].scores[2], studentInfo[i].scores[0] + studentInfo[i].scores[1] + studentInfo[i].scores[2]);
	}
	printf("********************************************************************************\n�� %d���� ���� ������ �ֽ��ϴ�.\n\n\n", studentCount);
}
int IsAvailNum(int num) { //��ȿ�� ��ȣ���� �Ǻ�
	return (num >= 0) && (num <= studentCount - 1);
}

void ViewStuData(int n) {
	int i = 0;
	int s = 0;

	printf("---%s �л� ���� ��ȸ---\n%s: %.1lf��\n%s: %.1lf��\n%s: %.1lf��\n����: %.1lf��\n", studentInfo[n].name, stitles[0], studentInfo[n].scores[0], stitles[1], studentInfo[n].scores[1], stitles[2], studentInfo[n].scores[2], studentInfo[n].scores[0] + studentInfo[n].scores[1] + studentInfo[n].scores[2]);
}