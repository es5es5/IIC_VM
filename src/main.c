#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include"game.h"
#include"common.h"
#include"screenOut.h"
#include"ItemData.h"
#include"ItemFunc.h"

int main(int argc, char *argv[]);
void Coinscreen(int coin);
void Startscreen();
void Choicemenu(int *number);
void Game();
void PrintList();
void ListToDo();
void Vendingmuchine();
void Manage();

int main(int argc, char *argv[])
{
	int number = 0;
	int coin;
	Coinscreen();
	Startscreen();
	Choicemenu(&number);
	Game();
	Vendingmuchine();
	Manage();

	while(1);
	return 0;
}

void Coininput(int *coin)																//�����Է�ȭ��
{
	printf("���� ���� : %d\n", coin);
}

void Startscreen()																	//�ʱ��ϸ� ���
{
	puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	puts("!!                                                                    !!");
	puts("!!                                                                    !!");
	puts("!!                                                                    !!");
	puts("!!                                                                    !!");
	puts("!!                                                                    !!");
	puts("!!                                                                    !!");
	puts("!!                                                                    !!");
	puts("!!                           1. GAME START                            !!");
	puts("!!                                                                    !!");
	puts("!!                                                                    !!");
	puts("!!                       2. Using Vending Machine                     !!");
	puts("!!                                                                    !!");
	puts("!!                                                                    !!");
	puts("!!                         3.. Manage Machine                         !!");
	puts("!!                                                                    !!");
	puts("!!                                                                    !!");
	puts("!!                                                                    !!");
	puts("!!                                                                    !!");
	puts("!!                                                                    !!");
	puts("!!                                                                    !!");
	puts("!!                                                                    !!");
	puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
}

void Choicemenu(int *number)
{
	while(1)
	{
		printf("�޴��� ������ �ּ���\n");
		scanf("%d",&number);
		system("cls");
		if(number == 1)
		{
			Game();
		}

		if(number == 2)
		{
			Vendingmuchine();
		}
		if(number == 3)
		{
			Manage();
		}
	}
}
void game()
{
	int number;
	printf(1. �ε�� ��Ŀ, 2. Ȧ¦);
	scanf("%d", &number);

	if(number == 1)
	{
		CardCom();
		ChoiceCard();
		resultCard();
		write();
	}
	else if(number == 2)
	{
		resultOddEven();
		ChoiceOddEven();
		resultOddEven();
		write();
	}
}

void PrintList ()
{
    puts("---------------------------------------------------\n");
    puts("���Ǳ� ��ǰ\n");
    printf("1. %7s %5d��  �������� : %4d��\n", items[0].name, items[0].price, items[0].qtr);
    printf("2. %7s %5d��  �������� : %4d��\n", items[1].name, items[1].price, items[1].qtr);
    printf("3. %7s %5d��  �������� : %4d��\n", items[2].name, items[2].price, items[2].qtr);
    printf("4. %7s %5d��  �������� : %4d��\n", items[3].name, items[3].price, items[3].qtr);
    puts("---------------------------------------------------\n");
    printf("����ݾ� : %d\n", money);
}
void ListToDo()
{
    puts("1. ��������\n");
    puts("2. ��������\n");
    puts("3. ��ǰ����\n");
    puts("4. exit\n");
}
void Vendingmuchine()
{
 	int num;

    while(1)
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
                printf("�̿����ּż� �����մϴ�.\n\n");
                roop=0;
                break;
        }
    }
}

enum {INPUT=1,SHOWALL,SEARCH,CHANGE,QUIT};

void Manage()
{
	int inputMenu=0;

		LoadDataFromFileInStruct();

		while(1)
		{
			ShowMenu();
			fputs("�����ϼ��� :  ", stdout);
			scanf("%d", &inputMenu);
			fflush(stdin);

			switch (inputMenu)
			{
			case INPUT:
				InputItemData();
				break;

			case SHOWALL:
				ShowAllData();
				break;

			case SEARCH:
				SearchItemData();
				break;

			case CHANGE:
				ChangeItemData();
				break;

			}

			if(inputMenu == QUIT)
			{
				puts("�̿��� �ּż� �����մϴ�. \n");
				break;
			}
}
