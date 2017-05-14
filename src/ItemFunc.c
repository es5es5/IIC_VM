#include"common.h"
#include"ItemData.h"
#include"screenOut.h"
#include"ItemFunc.h"

#define LIST_NUM 50

int numOfData=0;//��ǰ�� ����
ItemData* ItemList[LIST_NUM];//����ü ItemData�� �������� ����

void InputItemData(void)
{
	ItemData* pdata;
	int i;

	if(numOfData>=LIST_NUM)
	{
		puts("�޸� ������ �����մϴ�.");
		return;
	}
	pdata = (ItemData*)malloc(sizeof(ItemData));

	fputs("��ǰ �Է� : ", stdout);
	gets(pdata->name);

	printf("��ǰ���� �Է� : ");
	scanf("%d", &pdata->number);

	printf("���ΰ��� �Է� : ");
	scanf("%d", &pdata->coin);

	ItemList[numOfData] = pdata;
	numOfData++;

	StoreDataToFileInStruct();

	puts("�Է��� �Ϸ�Ǿ����ϴ�.");
	getchar();
}

void ShowAllData(void)
{
	int i;
	for(i=0; i<numOfData; i++)
	{
		ShowItemInfoByPtr(ItemList[i]);
	}

	puts("����� �Ϸ�Ǿ����ϴ�.");
	getchar();
}

void SearchItemData(void)
{
	int i;
	int searchSte=0;
	char searchName[NAME_LEN];
	fputs("ã�� ��ǰ��? ", stdout);
	gets(searchName);

	for(i=0; i<numOfData; i++)
	{
		if(!strcmp(ItemList[i]->name, searchName))
		{
			ShowItemInfoByPtr(ItemList[i]);
			searchSte = 1;
		}
	}
	if(searchSte == 0)
		puts("ã�� ��ǰ�� �����Ͱ� �˻����� �ʾҽ��ϴ�.");
	else
		puts("�˻��� �Ϸ��߽��ϴ�.");
	getchar();
}

void ChangeItemData(void)
{
	int i;
	char searchName[NAME_LEN];
	int newItemNumber=0;
	int newItemCoin=0;

	int idxOfMatchingData[LIST_NUM];
	int matchedCount = 0;
	int selection = 0;
	int delIdx = 0;

	fputs("ã�� ��ǰ��? ", stdout);
	gets(searchName);

	for(i=0; i<numOfData; i++)
	{
		if(!strcmp(ItemList[i]->name, searchName))
		{
			idxOfMatchingData[matchedCount++] = i;
		}
	}
	if(matchedCount == 0)
	{
		puts("���� ��� �̸��� �������� �ʽ��ϴ�.");
		getchar();
		return;
	}
	else if(matchedCount == 1)
	{
		delIdx = idxOfMatchingData[0];
	}
	else
	{
		for(i=0; i<matchedCount; i++)
		{
			printf("NUM. %d \n", i+1);
			ShowItemInfoByPtr(ItemList[idxOfMatchingData[i]]);
		}

		fputs("���� : ", stdout);
		scanf("%d", &selection);
		fflush(stdin);

		delIdx=idxOfMatchingData[selection-1];
	}
	fputs("������ ������?", stdout);
	scanf("%d", &newItemNumber);
	*ItemList[delIdx]->number = newItemNumber;

	fputs("������ ���� ������?", stdout);
	scanf("%d", &newItemCoin);
	*ItemList[delIdx]->coin = newItemCoin;

	StoreDataToFileInStruct();
	puts("���� �Ϸ�");
	getchar();
}

void StoreDataToFileInStruct(void)
{
	int i;

	FILE * fp = fopen("Record.dat", "wb");

	fwrite(&numOfData, sizeof(int), 1, fp);

	for(i=0; i<numOfData; i++)
	{
		fwrite(ItemList[i], sizeof(ItemData), 1, fp);
	}
	fclose(fp);
}

void LoadDataFromFileInStruct(void)
{
	int i;
	FILE * fp = fopen("Record.dat", "rb");
	if(fp == NULL)
		return;

	fread(&numOfData, sizeof(int), 1, fp);

	for(i=0; i<numOfData; i++)
	{
		ItemList[i] = (ItemData*)malloc(sizeof(ItemData));
		fread(ItemList[i], sizeof(ItemData), 1, fp);
	}
	fclose(fp);
}