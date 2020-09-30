#ifndef _MYHEADFILE_H_
#define _MYHEADFILE_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct terms{
	double coefficient;
	int power;
	struct terms *next;
};

struct terms *inputmultinomial(void);
struct terms *multinomialplus(struct terms *multihead1,struct terms *multihead2);
struct terms *multinomialsubtract(struct terms *multihead1,struct terms *multihead2);
struct terms *combineterms(struct terms *head);
struct terms *multiplication(struct terms *multihead1,struct terms *multihead2);
void printmultinomial(struct terms *head); 
struct terms *sortterms(struct terms *head);

#endif
