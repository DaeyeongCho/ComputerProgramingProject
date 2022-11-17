#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> //system("cls"); �Լ��� ȣ���ϱ� ���� �������. system("cls"); = ȭ���� �����ϰ� ����ϴ�.

struct Student { //����ü. �л��� ���� ���� ����
	char name[13]; //�̸� ���� 12��, �ѱ� 4�ڱ��� ���� �� �ֽ��ϴ�.
	int age; //����
	char phone[12]; //��ȭ��ȣ
	char address[31]; //�ּ�
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


void studentInformation(void); //�л� �������� ���� �Լ� ����
int addInfo(int n); //�л� �߰� �� ����ϴ� �Լ� ����
void inquiryInfo(int n); //�л� ��ȸ �� ����ϴ� �Լ� ����
int deleteInfo(int n); //�л� ���� ���� �� ����ϴ� �Լ� ����

void attendance(void); //������ �Լ� ����

void grade(void); //�������� �Լ� ����

void seat(void); //�¼����� �Լ� ����




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



void studentInformation(void) { //�л� �������� ���� �Լ�. ���뿵 ���
	int select; //�޴� ���� �� �Է� �� ���� ����
	static int studentCount = 0; //��ϵ� �л��� ���ڸ� ��Ÿ��. ��� �� �л� �� ��ŭ �ݺ��� ���� ������.
	system("cls");

	printf("********************\n�л� �������� ���� ���\n");

	while (1) {
		printf("********************\n\t-�޴�-\n1.�л� �߰�\n2.�л� ��ȸ\n3.�л� ���� ����\n4.������\n********************\n�Է�: ");
		scanf_s("%d", &select);

		switch (select) {
		case 1:
			if (addInfo(studentCount)) { //�л� �߰� �Լ��� �б�
				studentCount++; //���������� �л� �߰� �� �л� �� 1 ����
			}
			break;
		case 2:
			inquiryInfo(studentCount); //�л� ��ȸ �Լ��� �б�
			break;
		case 3:
			if (deleteInfo(studentCount)) { //�л� ���� ���� �Լ��� �б�
				studentCount--; //���������� �л� ���� ���� �Ϸ� �� �л� �� 1 ����
			}
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

int addInfo(int n) { //�л� �߰� �� ����ϴ� �Լ�
	if (n >= 20) { //�л��� 20�� ��ϵǾ� �� ���ԵǸ� �� �̻� ��� �Ұ������� �˸��� false ����
		printf("�� �̻� �л��� ����� �� �����ϴ�.");
		return 0;
	}
	printf("�̸�(�ִ� 12Byte): ");
	scanf("%s", studentInfo[n].name); //�̸��� �Է� �޾� studentInfo �迭�� ���ʴ�� �������
	printf("����: ");
	scanf_s(" %d", &studentInfo[n].age); //���̸� �Է� �޾� studentInfo �迭�� ���ʴ�� �������
	printf("�޴��� ��ȣ('-'����x): ");
	scanf("%s", studentInfo[n].phone);
	printf("�ּ�(�ִ� 30Byte): ");
	scanf("%s", studentInfo[n].address);
	printf("---�߰� �Ϸ�---\n");
	return 1; //���������� ����Ǿ� true ����
}

void inquiryInfo(int n) { //�л� ��ȸ �� ����ϴ� �Լ� 
	if (n == 0) { //��� �� �л��� �� �� ������ ������ �˸��� �Լ� ����
		printf("�л� ������ �����ϴ�.\n");
		return;
	}
	system("cls");
	printf("�л� ���� ���\n****************************************\n��ȣ\t\t�̸�\t\t����\t\t�޴��� ��ȣ\t\t�ּ�\t\t\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t\t%s\t\t%d\t\t%s\t\t%s\n", i, studentInfo[i].name, studentInfo[i].age, studentInfo[i].phone, studentInfo[i].address);
	}
}

int deleteInfo(int n) { //�л� ���� ���� �� ����ϴ� �Լ�. ���������� ȸ���� �����Ǿ����� ���θ� ������
	int m; //�� ��° �л��� ���� �� �� ��ȣ�� �޴� ����
	if (n == 0) {
		printf("���� �� �л� ������ �����ϴ�.\n");
		return 0;
	}
	inquiryInfo(n);
	printf("�����ϰ� ���� �л� ������ ��ȣ�� �Է��ϼ���.");
	scanf("%d", &m);
	if (m < 0 || m >= n) { //���� �л� ��ȣ �Է� �� ���� ��� �� �Լ� ����. false�� ���� ��
		printf("�߸��� ���Դϴ�.\n");
		return 0;
	}
	for (int i = m + 1; i < n; i++) { //�л� ���� ���� �� �迭 ������ �л� ������ ������ ���.
		strcpy(studentInfo[i - 1].name, studentInfo[i].name);
		studentInfo[i - 1].age = studentInfo[i].age;
		strcpy(studentInfo[i - 1].phone, studentInfo[i].phone);
		strcpy(studentInfo[i - 1].address, studentInfo[i].address);
	}
	return 1; //true�� ���� ��
}



void attendance(void) { //������ �Լ�. ������ ���
	//���⿡ �����Ͻø� �˴ϴ�. �� �Լ� �ٱ��ʿ� ���� �ۼ��Ͻ� �� �����ø� �� �κ��� ���� �ּ����� ǥ�����ֽø� ���� Ȯ���ؼ� �����ϵ��� �ϰڽ��ϴ�.
}



void grade(void) { //�������� �Լ�. ����� ���
	//���⿡ �����Ͻø� �˴ϴ�. �� �Լ� �ٱ��ʿ� ���� �ۼ��Ͻ� �� �����ø� �� �κ��� ���� �ּ����� ǥ�����ֽø� ���� Ȯ���ؼ� �����ϵ��� �ϰڽ��ϴ�.
}



void seat(void) { //�¼����� �Լ�. ������ ���
	//���⿡ �����Ͻø� �˴ϴ�. �� �Լ� �ٱ��ʿ� ���� �ۼ��Ͻ� �� �����ø� �� �κ��� ���� �ּ����� ǥ�����ֽø� ���� Ȯ���ؼ� �����ϵ��� �ϰڽ��ϴ�.
}