#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fphzk = NULL;
	FILE* fp = fopen("output.txt", "w");
	int i, j, k, offset, operation;
	int flag;
	unsigned char buffer[32];
	unsigned char word[1000][3];
	unsigned char key[8] = {
		0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01
	};
	fphzk = fopen("hzk16", "rb");
	if (fphzk == NULL) {
		fprintf(stderr, "error hzk16\n");
		return 1;
	}

	//处理汉字
	printf("请输入汉字:\n");
	for (int m = 0;; m++) {
		fgets(word[m], 3, stdin);
		word[m][3] = 0;
		if (word[m][0] == '\n')
			break;
	}
	for (int m = 0;; m++)
	{
		if (word[m][0] == '\n')
			break;
		offset = (94 * (unsigned int)(word[m][0] - 0xa0 - 1) + (word[m][1] - 0xa0 - 1)) * 32;
		fseek(fphzk, offset, SEEK_SET);
		fread(buffer, 1, 32, fphzk);
		for (k = 0; k < 16; k++) {
			for (j = 0; j < 2; j++) {
				for (i = 0; i < 8; i++) {
					flag = buffer[k * 2 + j] & key[i];
					printf("%s", flag ? "●" : "○");
				}
			}
			printf("\n");
		}
		printf("\n");
	}

	//选择模式
	while (1)
	{
		printf("请选择模式：\n0.退出\n1.文件输出\n2.放大\n3.斜体\n4.倒立\n5.变色\n6.动态显示\n");
		scanf("%d", &operation);
		system("cls");
		system("color 0F");
		switch (operation)
		{
		case 0:
			return 0;
		case 1:
			for (int m = 0;; m++)
			{
				if (word[m][0] == '\n')
					break;
				offset = (94 * (unsigned int)(word[m][0] - 0xa0 - 1) + (word[m][1] - 0xa0 - 1)) * 32;
				fseek(fphzk, offset, SEEK_SET);
				fread(buffer, 1, 32, fphzk);
				for (k = 0; k < 16; k++)
				{
					for (j = 0; j < 2; j++) {
						for (i = 0; i < 8; i++) {
							flag = buffer[k * 2 + j] & key[i];
							fprintf(fp, "%s", flag ? "● " : "○ ");
						}
					}
					fprintf(fp, "\n");
				}
				fprintf(fp,"\n");
			}
			break;
		case 2:
			for (int m = 0;; m++)
			{
				if (word[m][0] == '\n')
					break;
				offset = (94 * (unsigned int)(word[m][0] - 0xa0 - 1) + (word[m][1] - 0xa0 - 1)) * 32;
				fseek(fphzk, offset, SEEK_SET);
				fread(buffer, 1, 32, fphzk);
				for (k = 0; k < 16; k++)
				{
					for (j = 0; j < 2; j++) {
						for (i = 0; i < 8; i++) {
							flag = buffer[k * 2 + j] & key[i];
							printf("%s", flag ? "●●" : "○○");
						}
					}
					printf("\n");
					for (j = 0; j < 2; j++) {
						for (i = 0; i < 8; i++) {
							flag = buffer[k * 2 + j] & key[i];
							printf("%s", flag ? "●●" : "○○");
						}
					}
					printf("\n");
				}
				printf("\n\n");
			}
			break;
		case 3:
			for (int m = 0;; m++)
			{
				if (word[m][0] == '\n')
					break;
				offset = (94 * (unsigned int)(word[m][0] - 0xa0 - 1) + (word[m][1] - 0xa0 - 1)) * 32;
				fseek(fphzk, offset, SEEK_SET);
				fread(buffer, 1, 32, fphzk);
				for (k = 0; k < 16; k++) {
					for (int n = 0; n < 16-k; n++)
					{
						printf(" ");
					}
					for (j = 0; j < 2; j++) {
						for (i = 0; i < 8; i++) {
							flag = buffer[k * 2 + j] & key[i];
							printf("%s", flag ? "●" : "○");
						}
					}
					printf("\n");
				}
				printf("\n");
			}
			break;
		case 4:
			for (int m = 0;; m++)
			{
				if (word[m][0] == '\n')
					break;
				offset = (94 * (unsigned int)(word[m][0] - 0xa0 - 1) + (word[m][1] - 0xa0 - 1)) * 32;
				fseek(fphzk, offset, SEEK_SET);
				fread(buffer, 1, 32, fphzk);
				for (k = 15; k >=0; k--) {
					for (j = 1; j >=0; j--) {
						for (i = 7; i >= 0; i--) {
							flag = buffer[k * 2 + j] & key[i];
							printf("%s", flag ? "●" : "○");
						}
					}
					printf("\n");
				}
				printf("\n");
			}
			break;
		case 5:
			system("color 0C");
			for (int m = 0;; m++)
			{
				if (word[m][0] == '\n')
					break;
				offset = (94 * (unsigned int)(word[m][0] - 0xa0 - 1) + (word[m][1] - 0xa0 - 1)) * 32;
				fseek(fphzk, offset, SEEK_SET);
				fread(buffer, 1, 32, fphzk);
				for (k = 0; k < 16; k++) {
					for (j = 0; j < 2; j++) {
						for (i = 0; i < 8; i++) {
							flag = buffer[k * 2 + j] & key[i];
							printf("%s", flag ? "●" : "○");
						}
					}
					printf("\n");
				}
				printf("\n");
			}
			break;
		case 6:
			for (int n = 1; n <= 20; n++)
			{
				for (int m = 0;; m++)
				{
					if (word[m][0] == '\n')
						break;
					offset = (94 * (unsigned int)(word[m][0] - 0xa0 - 1) + (word[m][1] - 0xa0 - 1)) * 32;
					fseek(fphzk, offset, SEEK_SET);
					fread(buffer, 1, 32, fphzk);
					for (k = 0; k < 16; k++) {
						for (j = 0; j < 2; j++) {
							for (i = 0; i < 8; i++) {
								flag = buffer[k * 2 + j] & key[i];
								printf("%s", flag ? "●" : "○");
							}
						}
						printf("\n");
					}
					printf("\n");
				}
				_sleep(100);
				system("cls");
				_sleep(100);
			}
			
		default:
			break;
		}
	}
	fclose(fphzk);
	fphzk = NULL;
	fclose(fp);
	system("pause");
	return 0;
}
