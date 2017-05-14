#ifndef __ITEMDATA_H__
#define __ITEMDATA_H__

#define NAME_LEN 30
#define NUM_LEN 30
#define COIN_LEN  30
typedef struct __ItemData
{
	char name[NAME_LEN];
	int number[NUM_LEN];
	int coin[COIN_LEN];
	
}ItemData;

#endif