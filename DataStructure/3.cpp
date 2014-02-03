#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_INIT_SIZE 100

typedef char ElemType;
typedef struct node {
	ElemType *top, *base;
	int stacksize;
} Stack;

void InitStack(Stack &S) {
	S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if(!S.base) {
		printf("Malloc Error.\n");
		return ;
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}


void Push(Stack &S, ElemType e) {
	if(S.top-S.base >= S.stacksize) {
		printf("Stack is Full.\n");
		return ;
	}
	
	*S.top = e;
	S.top += 1;

}

ElemType Pop(Stack &S) {
	S.top--;
	return *(S.top);
}

int IsEmpty(Stack S) {
	if(S.top == S.base)
		return 1;
	return 0;
}

int main(void) {
	int i;
	char s[STACK_INIT_SIZE];
	Stack S;

	InitStack(S);
	while(1) {
		S.top = S.base;
		printf("Please Input(0 to exit) : ");
		scanf("%s", s);
		getchar();

		if(!strcmp(s, "0"))
			return 0;

		for(i=0; s[i]; i++) {
			Push(S, s[i]);
		}
		i = 0;
		int flag = 0;
		while(!IsEmpty(S)) {
			if(Pop(S) != s[i]) {
				flag = 1;
				printf("No\n");
				break;
			}
			i++;
		}
		if(!flag)
			printf("Yes\n");

	}
	
	return 0;
}
