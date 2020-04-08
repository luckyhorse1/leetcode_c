#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
	struct ListNode *root = malloc(sizeof(*root));
	root->next = NULL;
	struct ListNode *cur = root;
	int extra = 0;
	while (l1 || l2 || extra) {
		int sum = 0;
		if (l1) {
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			sum += l2->val;
			l2 = l2->next;
		}
		if (extra) {
			sum += extra;
		}
		struct ListNode *node = malloc(sizeof(*node));
		node->next = NULL;
		node->val = sum%10;
		extra = sum/10;
		cur->next = node;
		cur = node;
	}
	return root->next;
}

struct ListNode *node_build(char *s) {
	char *p = s;
	struct ListNode *ret = NULL;
	for (; *p; p++) {
		struct ListNode *node = malloc(sizeof(*node));
		node->val = *p-'0';
		node->next = ret;
		ret = node;
	}
	return ret;
}

void show(struct ListNode *l) {
	for (; l; l=l->next) {
		printf("%d", l->val);
		if (l->next) {
			printf("->");
		}
	}
	printf("\n");
}

int main(int argc, char **argv) {
	if (argc != 3) {
		fprintf(stderr, "usage: ./a.out n1 n2\n");
		exit(1);
	}
	
	struct ListNode *l1 = node_build(argv[1]);
	struct ListNode *l2 = node_build(argv[2]);
	struct ListNode *ret = addTwoNumbers(l1, l2);
	show(l1);
	show(l2);
	show(ret);
	return 0;
}
