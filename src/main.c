//��� ù��° �ҽ�

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>


void PrintList ()
{
	puts("---------------------------------------------------\n");
	puts("�� ���\n");
	puts("1. �ݶ�   --��\n");
	puts("2. ���̴� --��\n");
	puts("3. ȯŸ   --��\n");
	puts("---------------------------------------------------\n");
}

void ListToDo()
{
	puts("1. ��������\n");
	puts("2. ��������\n");
	puts("3. ��ǰ����\n");
	puts("4. printlist\n");
	puts("5. listtodo\n");
	puts("6. exit\n");
}


void user()
{
	int num;
	int roop=1;
	while(roop)
	{

		system("cls");
		PrintList();
		ListToDo();

		printf("���ϴ� �۾��� �����ϼ��� : ");
		scanf("%d", &num);

		switch(num)
		{
		case 1:
			InsertCoin();
			break;

		case 2:
			Refund();
			break;

		case 3:
			Order();
			break;

		case 4:
			PrintList();
			break;

		case 5:
			ListToDo();
			break;

		case 6:
			printf("�̿����ּż� �����մϴ�.\n\n");
			roop=0;
			break;
		}
	}
}

int InsertCoin()
{
	puts("InsertCoin�Դϴ�.");
	Sleep(2000);
	return 0;
}

int Refund()
{
	puts("Refund�Դϴ�.");
	Sleep(2000);
	return 0;
}

int Order()
{
	puts("Order�Դϴ�.");
	Sleep(2000);
	return 0;
}

int main (void)
{

	user();

	return 0;
}
