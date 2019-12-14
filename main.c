#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include "huffman.c"
//#include "rle.c"

void commandLineInput(int argc, char *argv[]);
int doesFileExist(char *);
void printResults(int []);
extern encode(char *, int);
int main(int argc, char *argv[]){
	commandLineInput(argc, argv);
	int temp= doesFileExist(argv[1]);
	printf("%d\n", temp);

	encode(argv, 20);	
}

void printResults(int results[]){
		
}




void commandLineInput(int argc, char *argv[]){
	char *fileName=NULL; 
	fileName= argv[1];
	printf("file name is- %s\n", fileName);


}

int doesFileExist(char *f){
	FILE *file;
	if(file=fopen(f, "r")){
		fclose(file);
		return 1;
	}
	free(file);
	return 0;
}
