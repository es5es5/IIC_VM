#include"common.h"
#include"screenOut.h"
#include"ItemData.h"
#include"ItemFunc.h"

enum {INPUT=1,SHOWALL,SEARCH,CHANGE,QUIT};

int main(void)
{
	int inputMenu=0;

	LoadDataFromFileInStruct();

	while(1)
	{
		ShowMenu();
		fputs("�����ϼ��� : ", stdout);
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
			puts("�̿��� �ּż� �����մϴ�.\n");
			break;
		}
	}

	return 0;
}