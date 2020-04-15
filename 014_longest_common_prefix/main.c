#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize){
	if(strsSize==0) return "";
    char *s = malloc(strlen(strs[0])+1);
    int index = 0;
    for (int i=0; i<strlen(strs[0]); i++,index++) {
        s[index] = strs[0][i];
        for (int j=1; j<strsSize; j++) {
            if (strs[j][i]=='\0' || strs[j][i] != s[index]) {
                s[index] = '\0';
                return s;
            }
        }
    }
    s[index] = '\0';
    return s;
}

int main(int argc, char **argv) {
	char *strs[] = {"flower", "flow", "flight"};
	printf("%s\n", longestCommonPrefix(strs, 3));
}
