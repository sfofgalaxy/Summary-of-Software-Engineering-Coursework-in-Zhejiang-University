#include "myheadfile.h"

struct contacts *findc(char name[20],struct contacts *head){
	struct contacts *ptr,*p;
	for(ptr = head;ptr;ptr=ptr->next){
		if(!strcmp(name,ptr->name))break;
	}
	return ptr;
}
