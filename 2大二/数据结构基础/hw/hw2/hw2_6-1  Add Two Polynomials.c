Polynomial Add(Polynomial a, Polynomial b) {
	Polynomial ptr1, ptr2, p, newhead, tail;
	tail = p = newhead = NULL;
	newhead = (Polynomial)malloc(sizeof(struct Node));
	newhead->Next = NULL;
	tail = newhead;
	if (a == NULL)return b;
	else if (b == NULL)return a;
	else
	{
		ptr1 = a->Next;
		ptr2 = b->Next;
		while (1) {
			if (ptr1 != NULL && ptr2 != NULL) {
				p = (Polynomial)malloc(sizeof(struct Node));
				if (newhead->Next == NULL) {
					newhead->Next = p;
				}
				if (ptr1->Exponent >= ptr2->Exponent) {
					p->Coefficient = ptr1->Coefficient;
					p->Exponent = ptr1->Exponent;
					p->Next = NULL;
					tail->Next = p;
					tail = p;
					ptr1 = ptr1->Next;
				}
				else {
					p->Coefficient = ptr2->Coefficient;
					p->Exponent = ptr2->Exponent;
					p->Next = NULL;
					tail->Next = p;
					tail = p;
					ptr2 = ptr2->Next;
				}
			}
			else if (ptr1 == NULL&&ptr2!=NULL) {
				while (ptr2 != NULL) {
					p = (Polynomial)malloc(sizeof(struct Node));
					p->Coefficient = ptr2->Coefficient;
					p->Exponent = ptr2->Exponent;
					p->Next = NULL;
					tail->Next = p;
					tail = p;
					ptr2 = ptr2->Next;
				}
				break;
			}
			else if (ptr2 == NULL&&ptr1 != NULL) {
				while (ptr1 != NULL) {
					p = (Polynomial)malloc(sizeof(struct Node));
					p->Coefficient = ptr1->Coefficient;
					p->Exponent = ptr1->Exponent;
					p->Next = NULL;
					tail->Next = p;
					tail = p;
					ptr1 = ptr1->Next;
				}
				break;
			}
			else {
				return newhead;
			}
		}
		p = newhead->Next;
		tail = newhead;
		while (p->Next != NULL)
		{
			if (p->Exponent == p->Next->Exponent) {
				p->Coefficient = p->Coefficient + p->Next->Coefficient;
				p->Next = p->Next->Next;
				tail = p;
				p = p->Next;
				if (p == NULL)break;
			}
			else p = p->Next;
		}
		tail = newhead;
		p = newhead->Next;
		while (p != NULL) {
			if (p->Coefficient == 0) {
				tail->Next = p->Next;
				p = p->Next;
			}
			else {
				tail = tail->Next;
				p = p->Next;
			}
		}
	}
	return newhead;
}