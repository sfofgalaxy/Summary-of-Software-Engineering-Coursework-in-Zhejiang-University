#ifndef _MYHEADFILE_H_
#define _MYHEADFILE_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contacts{					/*定义联系人结构*/ 
	char name[20];
	char tel[3][12];
	char addr[20];
	char birth[11];
	struct contacts *next;
};


extern struct contacts;
struct contacts *inputc(struct contacts *head);
struct contacts *importc(struct contacts *head);
struct contacts *deletec(struct contacts *head); 
struct contacts *findc(char name[20],struct contacts *head);
void addtel(struct contacts *head);
struct contacts *birth_sort(struct contacts *head);
struct contacts *name_sort(struct contacts *head);
void exportc(struct contacts *head);

#endif
