//Run Length Encoding
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000
void rleCompress(char* src){
	FILE* filePointer;
	int a=0;
	char c;
	filePointer=fopen(src, "r");
	for(a=getc(filePointer);a!=EOF; a=getc(filePointer))
		a+=a;
	int rLen;
   	char count[MAXSIZE];
    	int len = a;
   	char* dest=(char*)malloc(sizeof(char)*(len*2+1));
    	int i, j = 0, k; 
	FILE* filePointerWrite;
	filePointerWrite=fopen("compressed.txt", "w+");
	
   	for (i = 0; i < len; i++){
        	dest[j++] = src[i];
       		rLen = 1;
      		while (i + 1 < len && src[i] == src[i + 1]){
            		rLen++;
            		i++;
       		}
       		sprintf(count, "%d", rLen);
        	for (k = 0; *(count + k); k++, j++){
           		dest[j] = count[k];
        	}
   	}
   	dest[j] = '\0'; 

	fclose(filePointer);
	fclose(filePointerWrite);
	free(filePointer);
	free(filePointerWrite);
	//need to write dest to file "compressed.txt"
   
}  
