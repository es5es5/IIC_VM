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

void Coininput(int *coin)																//코인입력화면
{
	printf("현재 코인 : %d\n", coin);
}

void Startscreen()																	//초기하면 출력
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
		printf("메뉴를 선택해 주세요\n");
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
	printf(1. 인디언 포커, 2. 홀짝);
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
    puts("자판기 물품\n");
    printf("1. %7s %5d원  남은수량 : %4d개\n", items[0].name, items[0].price, items[0].qtr);
    printf("2. %7s %5d원  남은수량 : %4d개\n", items[1].name, items[1].price, items[1].qtr);
    printf("3. %7s %5d원  남은수량 : %4d개\n", items[2].name, items[2].price, items[2].qtr);
    printf("4. %7s %5d원  남은수량 : %4d개\n", items[3].name, items[3].price, items[3].qtr);
    puts("---------------------------------------------------\n");
    printf("현재금액 : %d\n", money);
}
void ListToDo()
{
    puts("1. 동전투입\n");
    puts("2. 동전빼기\n");
    puts("3. 상품선택\n");
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

        printf("원하는 작업을 선택하세요 : ");
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
                printf("이용해주셔서 감사합니다.\n\n");
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
			fputs("선택하세요 :  ", stdout);
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
				puts("이용해 주셔서 감사합니다. \n");
				break;
			}
}
