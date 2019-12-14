//Run Length Encoding
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* encode(char* src,int size){
    int rLen;
    char count[size];
    int len = strlen(src);
    char* dest = (char*)malloc(sizeof(char) * (len * 2 + 1));
    int i, j = 0, k;    
    for (i = 0; i < len; i++) {
        dest[j++] = src[i];
        rLen = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            rLen++;
            i++;
        }
        sprintf(count, "%d", rLen);
        for (k = 0; *(count + k); k++, j++) {
            dest[j] = count[k];
        }
    }
    dest[j] = '\0'; 
    return dest; 
}  
