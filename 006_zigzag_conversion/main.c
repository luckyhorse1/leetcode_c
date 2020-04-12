#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List {
	char c;
	struct List *next;
};

char *convert(char *s, int numRows) {
	if (numRows <= 1) return s;
	struct List table[numRows];
	struct List *tail[numRows];
	int i=0, count=0, index=0;
	int len = strlen(s);
	if (len==0) return "";
	char *ret = malloc(len+1);
	for (i=0; i<numRows && *s; i++, s++) {
		table[i].c = *s;
		table[i].next = NULL;
		tail[i] = &table[i];
	}
	while (*s) {
		for (index=numRows-2; index>0 && *s; index--, s++) {
			struct List *node = malloc(sizeof(*node));
			node->next = NULL;
			node->c = *s;
			tail[index]->next = node;
			tail[index] = node;
		}
		for (index = 0; index<numRows && *s; index++, s++) {
			struct List *node = malloc(sizeof(*node));
			node->next = NULL;
			node->c = *s;
			tail[index]->next = node;
			tail[index] = node;
		}
	}
	for (i=0; i<numRows && count<len; i++) {
		struct List *p = &table[i];
		for (; p; p=p->next) {
			ret[count++] = p->c;
		}
	}
	ret[count] = '\0';
	return ret;
}

char *convert2(char *s, int numRows) {
	if (numRows<=1) return s;
	int len = strlen(s);
	char *ret = malloc(len+1);
	char *p = ret;
	int i=0;
	for (i=0; i<numRows; i++) {
		int iv1 = 2*numRows-2*i-2;
		int iv2 = 2*i;
		int flag = 0;
		int delta = 0;
		int index = i;
		while (index<len) {
			*p++ = s[index];
			delta = flag==0? iv1: iv2;
			flag = !flag;
			if (delta==0) {
				delta = flag==0? iv1: iv2;
				flag = !flag;
			}
			index += delta;
		}
	}
	ret[len] = '\0';
	return ret;
}

int main(int argc, char **argv) {
	printf("%s\n", convert2(argv[1], atoi(argv[2])));
	return 0;
}
