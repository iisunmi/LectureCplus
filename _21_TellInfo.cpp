#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define NAME_LEN		20
#define TEL_LEN			20
#define MAX_PERSON_NUM	100

/*c++���� struct�� class�� 99%����
 �������� struct�� �⺻������ ��� ���� public ���� �����̰�,
 class�� �⺻������ ��� ���� private ���� �����̴�.
 �̷��� ������ 
 1) c++������ c �ڵ带 �����ϱ� ���ؼ�, ��, �ڵ� ȣȯ���� ����.
    c���� ����ü�� ����� �׳� �����Ѵ�(public)
 2) class�� �⺻������ private�� ������ ���������� ���������� �Լ����� ���� �����ϸ鼭 ����ġ ���� bug �߻��� �����߱⶧���̴�. 
    �׷��� ���������� ���� ��� ������ ����ϵ��� �ϴ� ��ġ�� ����*/

class Person
{
	//��������� ���� ������ ���� ���� ��Ģ���� ��
private: //�� �ᵵ private���� üũ��.
	char name[NAME_LEN];
	char phone[TEL_LEN];

	//��� ��������� ����Լ��� ���� �����ϵ��� ��
public:
	//getter
	char* getName() {
		return name;
	}
	//setter
	void setName(char* _name) {
		strncpy(name, _name, strlen(_name));
		name[strlen(_name)] = '\n'; //==0 or NULL

	}
	char* getphone() {
		return phone;
	}

	void setPhone(char* _phone) {

		strncpy(phone, _phone, strlen(_phone));
		name[strlen(_phone)] = '\n'; //==0 or NULL
	}

	void showPerson() {

		printf("name : %s\n", name);
		printf("phone : %s\n", phone);
	}
};

/*c++������ �̷� �Լ��� '�����Լ�'��� �θ���*/
void ShowMenu();
void InsertTelInfo(Person* par, int* pnum);
void DeleteTelInfo(Person* par, int* pnum);
void SearchTelInfo(Person* par, int num);
void PrintAll(Person* par, int num);
void ClearScreen();

void main()
{
	int choice = 0;						// �޴�����
	int nPersonNum = 0;

	Person* perArr = NULL;
	int perNum = 0;						// ����� �ο���

	printf("������ �ο����� ����Դϱ�? : ");
	scanf("%d", &nPersonNum);
	perArr = new Person[nPersonNum];


	while (1)
	{
		ShowMenu();
		printf("Choose the item : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			InsertTelInfo(perArr, &perNum);
			break;
		case 2:
			DeleteTelInfo(perArr, &perNum);
			break;
		case 3:
			SearchTelInfo(perArr, perNum);
			break;
		case 4:
			PrintAll(perArr, perNum);
			break;
		case 5:
		
			delete[] perArr;
			return;
			break;
		default:
			printf("illegal selection.. \n");
			break;
		}
	}
}

void ShowMenu()
{
	ClearScreen();
	printf("\n------------- Menu -------------\n");
	printf("	1. Insert \n");
	printf("	2. Delete \n");
	printf("	3. Search \n");
	printf("	4. Print All \n");
	printf("	5. Exit \n");
}

void InsertTelInfo(Person* par, int* pnum)
{
	char name[NAME_LEN];
	char phone[TEL_LEN];
	printf("[ INSERT ] \n");
	printf("Input Name : ");
	scanf("%s", name);
	printf("Input Tel Number : ");
	scanf("%s", phone);

	par[*pnum].setName(name);
	par[*pnum].setPhone(phone);
	//strcpy(par[*pnum].name, name);
	//strcpy(par[*pnum].phone, phone);
	(*pnum)++;

	printf("-----------> Data Inserted......\n");
}

void DeleteTelInfo(Person* par, int* pnum)
{
	int i = 0, j = 0;
	char name[NAME_LEN];

	printf("[ Delete ] \n");
	printf("Input Name for Removing : ");
	scanf("%s", name);

	for (i = 0; i < *pnum; i++)
	{
		if (strcmp(par[i].getName(), name) == 0)
		{
			for (j = i + 1; j < *pnum; j++)
			{
				strcpy(par[j - 1].getName(), par[j].getName());
				strcpy(par[j - 1].getphone(), par[j].getphone());
			}
			(*pnum)--;
			return;
		}
	}

	printf("-------------> Data Not Found..........\n");
}

void SearchTelInfo(Person* par, int num)
{
	int i = 0;
	char name[NAME_LEN];

	printf("[ Search ] \n");
	printf("Input Name for Searching : ");
	scanf("%s", name);

	for (i = 0; i < num; i++)
	{
		if (strcmp(par[i].getName(), name) == 0)
		{
			par[i].showPerson();
			return;
		}
	}

	printf("-------------> Data Not Found..........\n");
}

void PrintAll(Person* par, int num)
{
	int i = 0;

	printf("[ Print All Data ] \n");

	for (i = 0; i < num; i++)
		par[i].showPerson();

	getchar();
	getchar();
}

void ClearScreen() {

	//console�� dos���� �� ����
	system("cls");
}