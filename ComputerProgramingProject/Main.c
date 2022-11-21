#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> //system("cls"); �Լ��� ȣ���ϱ� ���� �������. system("cls"); = ȭ���� �����ϰ� ����ϴ�.
#include <stdlib.h>
#include <string.h>

struct Student { //����ü. �л��� ���� ���� ����
	char name[13]; //�̸� ���� 12��, �ѱ� 4�ڱ��� ���� �� �ֽ��ϴ�.
	int age; //����
	char phone[12]; //��ȭ��ȣ
	char address[31]; //�ּ�
	double scores[3]; //���� �� 0:�⼮ ����(10.0), 1:���� ����(60.0), 2:������(30.0)
	int attendance; //0 �Ἦ, 1 �⼮, 2 ����
};

struct Student studentInfo[20]; //����ü 20�� ����. �л� �ִ� 20����� ��� ����. ���� ����
/*
����ü, �迭 �����Դϴ�. �ϴ� ���������� �����߱� ������ �ƹ� �Լ������� �� ��� �����ϰ� ������ �����Ǳ� ������ �����ϸ� ��� �Լ����� �� �ٲ�ϴ�.

�ϴ� ����ü�� int�� double, char���� �������� �ϳ��� ������ ��������Ŷ� �����Ͻø� ���մϴ�.
�� ���� ����� �̸�, ���� �� ���� ������ �����ϰ� �̰� ���� ������ ���������� �����Ͱ� �߱������� �Ǿ������ ������ ����ü��� ������ ����δ� ���Դϴ�.
���⼭�� studentInfo��� ����ü ������ ����� char name, int age ���� ������ �־�ξ����ϴ�.

�׸��� �迭�� ���� ���ڸ� �����ϴ� ���� 10���� �ʿ��ϴٰ� �� �� int a, int b, int c, int d - - - �̷� ������ 10���� ���� �ſ� ������ ������ int n[10] �̶�� �� �� ���� �� ������ n�̶�� �̸��� ���� 10���� �ѹ��� �����ϴ� ���Դϴ�.
�׸��� ���߿� ���� ������� ���� �� ��° n���� ������ �� �־�� �ϱ� ������ ���� 4��° n�� 50�� �ְڴٰ� �ϸ� n[3] = 50 ���� ���� �˴ϴ�. (int n[10]���� 10�� ���� �� [] ���� ���� 0~9���� 10���Դϴ�.)
���� ��� �ÿ��� print("%d", n[3])�� ���� ������� �����ϸ� �˴ϴ�.

�׷��� ���� ����� �� struct Student studentList[20];�� studentInfo��� �ϴ� ����ü ������ �迭�� ���� 20�� �����ϴ� ���Դϴ�.
�׸��� �ϳ��� studentInfo ���� �ȿ��� char name, int age ����� �� �ִ� ���Դϴ�.

�̷����� �κ��� ��������̰� ���� �߿��� ������Դϴ�.
���� 15��° ����� age ���� 30�� ���� �������� studentInfo[14].age = 20; �̶�� ���ø� �˴ϴ�. ��� . ǥ�ô� ~�� �� �ؼ��Ͻø� �����ϱ� ���մϴ�.
���� ����Ͻ� ������ printf("%d", studentInfo[14].age);�� ���ø� ���� �� �� �ֽ��ϴ�.
*/

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
	int select; //�޴� ���� �� �Է� �� ���� ����
	int escape = 1; //�Ʒ� while�� �ݺ��� ����. case 5:���� escape ���� 0���� �ٲ� Ż���մϴ�.

	printf("********************\n�л� ���� ��\nMade By ���뿵, �����, ������, ������\n"); //Ÿ��Ʋ ���

	while (escape) {
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
			escape = 0;
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

	printf("********************\n�л� �������� ���� ���\n");

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
	printf("����: ");
	scanf_s(" %d", &studentInfo[studentCount].age); //���̸� �Է� �޾� studentInfo �迭�� ���ʴ�� �������
	printf("�޴��� ��ȣ('-'����x): ");
	scanf("%s", studentInfo[studentCount].phone);
	printf("�ּ�(�ִ� 30Byte): ");
	scanf("%s", studentInfo[studentCount].address);
	for (int i = 0; i < 3; i++) { //���� �ʱ�ȭ
		studentInfo[studentCount].scores[i] = -1;
	}
	studentInfo[studentCount].attendance = 0;
	printf("---�߰� �Ϸ�---\n");
	studentCount++; //���������� �л� �߰� �� �л� �� 1 ����
}

void inquiryInfo() { //�л� ��ȸ �� ����ϴ� �Լ� 
	if (studentCount == 0) { //��� �� �л��� �� �� ������ ������ �˸��� �Լ� ����
		printf("�л� ������ �����ϴ�.\n");
		return;
	}
	system("cls");
	printf("�л� ���� ���\n********************************************************************************\n��ȣ\t\t�̸�\t\t����\t\t�޴��� ��ȣ\t\t�ּ�\t\t\n");
	for (int i = 0; i < studentCount; i++) {
		printf("%d\t\t%s\t\t%d\t\t%s\t\t%s\n", i, studentInfo[i].name, studentInfo[i].age, studentInfo[i].phone, studentInfo[i].address);
	}
	printf("********************************************************************************\n�� %d���� �л� ������ �ֽ��ϴ�.\n", studentCount);
}

void deleteInfo() { //�л� ���� ���� �� ����ϴ� �Լ�. ���������� ȸ���� �����Ǿ����� ���θ� ������
	int m; //�� ��° �л��� ���� �� �� ��ȣ�� �޴� ����
	if (studentCount == 0) {
		printf("���� �� �л� ������ �����ϴ�.\n");
		return;
	}
	inquiryInfo(studentCount);
	printf("�����ϰ� ���� �л� ������ ��ȣ�� �Է��ϼ���.");
	scanf_s("%d", &m);
	if (m < 0 || m >= studentCount) { //���� �л� ��ȣ �Է� �� ���� ��� �� �Լ� ����. false�� ���� ��
		printf("�߸��� ���Դϴ�.\n");
		return 0;
	}
	for (int i = m + 1; i < studentCount; i++) { //�л� ���� ���� �� �迭 ������ �л� ������ ������ ���.
		strcpy(studentInfo[i - 1].name, studentInfo[i].name);
		studentInfo[i - 1].age = studentInfo[i].age;
		strcpy(studentInfo[i - 1].phone, studentInfo[i].phone);
		strcpy(studentInfo[i - 1].address, studentInfo[i].address);
	}
	studentCount--; //���������� �л� ���� ���� �Ϸ� �� �л� �� 1 ����
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
		printf("�л� ������ �����ϴ�.\n");
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
	printf("�л� ���� ���\n********************************************************************************\n��ȣ\t\t�̸�\t\t����\t\t�޴��� ��ȣ\t\t�ּ�\t\t\n");
	for (int i = 0; i < studentCount; i++) {
		printf("%d\t\t%s\t\t%d\t\t%s\t\t%s\n", i, v[i].name, v[i].age, v[i].phone, v[i].address);
	}
	printf("********************************************************************************\n���� �Ϸ�. �� %d���� �л� ������ �ֽ��ϴ�.\n�̴�� ���� �Ͻðڽ��ϱ�(y/n)? ", studentCount);
	scanf_s(" %c", &c);
	if ((c == 'y') || (c == 'Y')) {
		for (int i = 0; i < studentCount; i++) {
			studentInfo[i] = v[i];
		}
		printf("���� �Ϸ�!\n");
	}
	else {
		printf("���� ȭ������ ���ư��ϴ�.\n");
	}
}


//-----------------------------------------------------------------------------------������ �Լ�. ������ ���


void attendance(void) {
	int select;

	while (1) {
		printf("1.��� ���� 2.��� ��Ȳ ��ȸ 3.���� ȭ������\n����: ");
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
	int selectStudent;
	int selectAttendance;

	inquiryInfo();
	if (isEmpty()) {
		return;
	}

	printf("�л� ��ȣ ����: ");
	scanf_s("%d", &selectStudent);
	printf("1.�⼮ 2.�Ἦ 3.����\n����: ");
	scanf_s("%d", &selectAttendance);

	switch (selectAttendance) {
	case 1:
		studentInfo[selectStudent].attendance = 1;
		printf("%s�л� �⼮ ó�� �Ϸ�\n", studentInfo[selectStudent].name);
		break;
	case 2:
		studentInfo[selectStudent].attendance = 0;
		printf("%s�л� �Ἦ ó�� �Ϸ�\n", studentInfo[selectStudent].name);
		break;
	case 3:
		studentInfo[selectStudent].attendance = 2;
		printf("%s�л� ���� ó�� �Ϸ�\n", studentInfo[selectStudent].name);
		break;
	default:
		break;
	}
}

void attendanceSearch() {

	if (studentCount == 0) { //��� �� �л��� �� �� ������ ������ �˸��� �Լ� ����
		printf("�л� ������ �����ϴ�.\n");
		return;
	}
	system("cls");
	printf("�л� ���� ���\n********************************************************************************\n��ȣ\t\t�̸�\t\t��� ��Ȳ\t\t\n");
	for (int i = 0; i < studentCount; i++) {
		switch (studentInfo[i].attendance) {
		case 1:
			printf("%d\t\t%s\t\t�⼮\n", i, studentInfo[i].name);
			break;
		case 2:
			printf("%d\t\t%s\t\t����\n", i, studentInfo[i].name);
			break;
		case 0:
			printf("%d\t\t%s\t\t�Ἦ\n", i, studentInfo[i].name);
			break;
		default:
			break;
		}
	}
	printf("********************************************************************************\n�� %d���� �л� ������ �ֽ��ϴ�.\n", studentCount);
}


//-----------------------------------------------------------------------------------�������� �Լ�. ����� ���


void grade(void) {
	Run();
}

void Run()
{
	int key = 0;
	while ((key = SelectMenu()) != 0)//������ �޴��� 0�� �ƴϸ� �ݺ�
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
	printf("*****************************************************************\n");
	printf("���� ���� ���α׷� 0:����\n");
	printf("1: �л� ���� �Է� 2: �л� ���� �ʱ�ȭ 3: �л� �˻� 4: ������� ���� 0: ���� ȭ������ \n");
	printf("*****************************************************************\n");
	scanf_s("%d", &key);
	return key;
}

void AddStudent() { //�л� ������ �Է�
	int num = -1;

	inquiryInfo();
	if (isEmpty()) {
		return;
	}

	printf("���� �Է� �� �л� ��ȣ(0 ~ %d): ", studentCount - 1);
	scanf_s("%d", &num);

	if (IsAvailNum(num) == 0)//��ȿ�� ��ȣ�� �ƴ� ��
	{
		printf("������ ��� �л� ��ȣ�Դϴ�.\n");
		return;
	}

	printf("%s �л��� ������ �Է��մϴ�.", studentInfo[num].name);
	
	for (int s = 0; s < 3; s++)
	{
		printf("%s ����:", stitles[s]);
		scanf_s("%lf", &studentInfo[num].scores[s]);

		if (IsAvailScore(studentInfo[num].scores[s], s) == 0)//��ȿ�� ������ �ƴ� ��
		{
			studentInfo[num].scores[s] = -1;
			printf("�Է��� ������ ��ȿ���� �ʾƼ� %s ������ �Է� ó������ �ʾҽ��ϴ�.\n", stitles[s]);
		}
	}
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
		printf("������ ��� �л� ��ȣ�Դϴ�.\n");
		return;
	}

	for (s = 0; s < 3; s++)
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

	ViewStuData(num);
}

void ListStudent() { //��� ����
	if (isEmpty()) {
		printf("�л� ������ �����ϴ�.\n");
		return;
	}

	system("cls");
	printf("�л� ���� ���(������ -1�� ���� ���Է�)\n********************************************************************************\n��ȣ\t\t�̸�\t\t%s\t\t%s\t\t%s\t\t����\n", stitles[0], stitles[1], stitles[2]);
	for (int i = 0; i < studentCount; i++) {
		printf("%d\t\t%s\t\t%.1lf\t\t\t%.1lf\t\t\t%.1lf\t\t\t%.1lf\n", i, studentInfo[i].name, studentInfo[i].scores[0], studentInfo[i].scores[1], studentInfo[i].scores[2], studentInfo[i].scores[0] + studentInfo[i].scores[1] + studentInfo[i].scores[2]);
	}
	printf("********************************************************************************\n�� %d���� ���� ������ �ֽ��ϴ�.\n", studentCount);
}
int IsAvailNum(int num) { //��ȿ�� ��ȣ���� �Ǻ�
	return (num >= 0) && (num <= studentCount - 1);
}
int IsAvailScore(double score, int c) { //��ȿ�� �������� �Ǻ�
	double valid[3] = { 10.0, 60.0, 30.0 };
	return (score >= 0) && (score <= valid[c]);
}

void ViewStuData(int n) {
	int i = 0;
	int s = 0;

	printf("%s �л��� %s: %.1lf��, %s: %.1lf��, %s: %.1lf�� ����: %.1lf��", studentInfo[n].name, stitles[0], studentInfo[n].scores[0], stitles[1], studentInfo[n].scores[1], stitles[2], studentInfo[n].scores[2], studentInfo[n].scores[0] + studentInfo[n].scores[1] + studentInfo[n].scores[2]);

	printf("\n");
}