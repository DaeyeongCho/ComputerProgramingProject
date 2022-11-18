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

//-----------------------------------------------------------------------------------������ ����, �Լ� ����

void attendance(void); //������ �Լ� ����

//-----------------------------------------------------------------------------------����� ����, �Լ� ����

void grade(void); //�������� �Լ� ����
void Run();
int SelectMenu();//�޴� ��� �� ����
void AddStudent();//�л� ������ �Է�
void RemoveStudent();//�л� ������ ����
void FindStudent();//�л� �˻�
void ListStudent();//��� ����
int IsAvailNum(int num);//��ȿ�� ��ȣ���� �Ǻ�
int IsAvailScore(double score);//��ȿ�� �������� �Ǻ�

//-----------------------------------------------------------------------------------������ ����, �Լ� ����

void seat(void); //�¼����� �Լ� ����

//-----------------------------------------------------------------------------------




int main(void) {
	int select; //�޴� ���� �� �Է� �� ���� ����
	int escape = 1; //�Ʒ� while�� �ݺ��� ����. case 5:���� escape ���� 0���� �ٲ� Ż���մϴ�.

	printf("********************\n�л� ���� ��\nMade By ���뿵, �����, ������, ������\n"); //Ÿ��Ʋ ���

	while (escape) {
		printf("********************\n\t-�޴�-\n1.�л� �������� ����\n2.��� ����\n3.���� ����\n4.�¼� ����\n5.������\n********************\n�Է�: "); //�޴� ���
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
		case 4: //�¼����� �Լ� �б�
			seat();
			system("cls");
			break;
		case 5: //���α׷� ����
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
		printf("********************\n\t-�޴�-\n1.�л� �߰�\n2.�л� ��ȸ\n3.�л� ���� ����\n4.���� ȭ������\n********************\n�Է�: ");
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
	scanf("%d", &m);
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


//-----------------------------------------------------------------------------------������ �Լ�. ������ ���


void attendance(void) {
	//���⿡ �����Ͻø� �˴ϴ�. �� �Լ� �ٱ��ʿ� ���� �ۼ��Ͻ� �� �����ø� �� �κ��� ���� �ּ����� ǥ�����ֽø� ���� Ȯ���ؼ� �����ϵ��� �ϰڽ��ϴ�.
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
	printf("1: �л� ������ �Է� 2: �л� ������ ���� 3: �л� �˻� 4: ��� ���� 0: ���� ȭ������ \n");
	printf("*****************************************************************\n");
	scanf_s("%d", &key);
	return key;
}

void AddStudent() { //�л� ������ �Է�


	/*int num = 0;
	Student* stu = 0;
	int s = 0;

	printf("�߰��� �л� ��ȣ(1~%d): ", MAX_STUDENT);
	scanf_s("%d", &num);

	if (IsAvailNum(num) == 0)//��ȿ�� ��ȣ�� �ƴ� ��
	{
		printf("������ ��� �л� ��ȣ�Դϴ�.\n");
		return;
	}

	if (stues[num - 1].num)//�̹� ��ȣ�� ������ ������ ��
	{
		printf("�̹� �߰��Ͽ����ϴ�\n");
		return;
	}

	//stues���� 1�� �л� �����͸� �����ϴ� �޸� �ּ�
	//���� stues+(num-1)�� num�� �л� �����͸� �����ϴ� �޸� �ּ�
	stu = stues + (num - 1);
	stu->num = num;
	printf("�̸�: ");
	scanf_s("%s", stu->name, sizeof(stu->name));

	for (s = 0; s < MAX_SUBJECT; s++)
	{
		printf("%s ����:", stitles[s]);
		scanf_s("%lf", stu->scores + s);

		if (IsAvailScore(stu->scores[s]) == 0)//��ȿ�� ������ �ƴ� ��
		{
			stu->scores[s] = -1;
			printf("�Է��� ������ ��ȿ���� �ʾƼ� %s ������ �Է� ó������ �ʾҽ��ϴ�.\n", stitles[s]);
		}
	}*/
}

void RemoveStudent() {//�л� ������ ����

}

void FindStudent() { //�л� �˻�

}

void ListStudent() { //��� ����

}
int IsAvailNum(int num) { //��ȿ�� ��ȣ���� �Ǻ�

}
int IsAvailScore(double score) { //��ȿ�� �������� �Ǻ�

}


//-----------------------------------------------------------------------------------�¼����� �Լ�. ������ ���


void seat(void) {
	//���⿡ �����Ͻø� �˴ϴ�. �� �Լ� �ٱ��ʿ� ���� �ۼ��Ͻ� �� �����ø� �� �κ��� ���� �ּ����� ǥ�����ֽø� ���� Ȯ���ؼ� �����ϵ��� �ϰڽ��ϴ�.
}