#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include"common.h"
#include"screenOut.h"
#include"ItemData.h"
#include"ItemFunc.h"

int main(int argc, char *argv[]);
void Coininput(int coin);
void Coinoutput(int coin);
void Startscreen();
void Choicemenu(int *number);
void Game();
void Vendingmuchine();
void Manage();

int main(int argc, char *argv[])
{
	int number = 0;
	int coin;
	Coininput();
	Coinoutput();
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
	printf("몇개의 코인을 넣을신건가요??\n");
	scanf("%d", coin);
}

void Coinoutput(int coin)																//현재코인화면
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
	printf("메뉴를 선택해 주세요\n");
		scanf("%d",&number);

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
/*void game()
{

}

void Vendingmuchine()
{

}
*/
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
