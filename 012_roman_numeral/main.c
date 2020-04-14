#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_ *Node;

typedef struct Stack_ *Stack;

struct Node_ {
	int index;
	int num;
	Node pre;
};

struct Stack_ {
	Node top;
};

void push(Stack stack, int index, int num) {
	Node node = malloc(sizeof(*node));
	node->index = index;
	node->num = num;
	node->pre = stack->top;
	stack->top = node;
}

void pop(Stack stack) {
	if (stack->top) {
		stack->top = stack->top->pre;
	}
}

int isEmpty(Stack stack) {
	return !stack->top;
}

char *intToRoman(int num) {
	char *one[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	char *two[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	char *three[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	char *four[10] = {"", "M", "MM", "MMM"};
	int k = num;
	char ret[20] = "";
	int i=1;
	Stack stack = malloc(sizeof(*stack));
	stack->top = NULL;
	while (k!=0) {
		push(stack, i, k%10);
		k/=10;
		i++;
	}
	while (!isEmpty(stack)) {
		Node cur = stack->top;
		switch(cur->index) {
			case 1:
				strcat(ret, one[cur->num%10]);
				break;
			case 2:
				strcat(ret, two[cur->num%10]);
				break;
			case 3:
				strcat(ret, three[cur->num%10]);
				break;
			case 4:
				strcat(ret, four[cur->num%10]);
				break;
			default:
				break;			
		}
		pop(stack);
	}
	char *str = malloc(strlen(ret)+1);
    strcpy(str, ret);
	return str;
}

int main(int argc, char **argv) {
	printf("%s\n", intToRoman(atoi(argv[1])));
}
