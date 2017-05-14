/**
 *   @file vendingmachine.c
 *   @b 자판기프로그램 사용자부분
 */

#include "vendingmachine.h"

void refund()
{
    printf("잔돈은 %d원입니다.", coin);
    coin=0;
}


void Order (int item, int qt)
{
    item-=1;
    if(qt>ItemList[item]->number)
        printf("물품 수량이 부족합니다.");   //수량 부족
    
    else if(coin>=qt*(ItemList[item]->cost))
    {
        ItemList[item]->number-=qt;
        coin-=qt*ItemList[item]->cost;
    }
    
    else printf("금액이 부족합니다.");//금액부족
    
}
