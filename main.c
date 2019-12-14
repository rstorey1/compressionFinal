#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
//#include "huffman.c"
//#include "rle.c"

void commandLineInput(int, char **, int );//done
int doesFileExist(char *);//done
int isTextFile(char *);//done
void printStats(char *, int, int, int);
//extern rleCompress(char *, int);
int fileSize(char *);//done
void runCompressors(char **, int);

int main(int argc, char *argv[]){
	int numberOfFiles;
       	numberOfFiles=argc-1;
	
	commandLineInput(argc, argv, numberOfFiles);
	
	runCompressors(argv, numberOfFiles);
	 	
}

void runCompressors(char *fileList[], int numFiles){
	int ogSize[numFiles];
	int newSize[numFiles];
	int times[numFiles];

	printStats("wopto.txt", 1000, 500, 20);
}
void printStats(char *name, int oldSize, int newSize, int time){

	printf("%s has been compressed. Old size:%dbytes New size:%dbytes Time:%d milliseconds\n", name, oldSize, newSize, time);
}
int fileSize(char *name){
	FILE *file;
        file=fopen(name, "r");
	int size=0;

	fseek(file, 0, SEEK_END);
	size=ftell(file);
	rewind(file);

        fclose(file);      
        free(file);
        return size;
}
int isTextFile(char *name){
	name= strrchr(name, '.');
	if((name!=NULL)&&!(strcmp(name, ".txt"))){
		return 1;
	}
	return 0;
}
void commandLineInput(int argc, char *argv[], int numFiles){
	if(numFiles==0){
		printf("No files provided, please input names of files\n");
		exit(1);
	}
	char *fileName=NULL;
	int allFilesValid=1;
	for(int i=1; i<=numFiles;i++){
		fileName=argv[i];
		if(isTextFile(fileName)&&doesFileExist(fileName)){
			;
		}
		else if(!isTextFile(fileName)&&!doesFileExist(fileName)){
                        printf("%s- is not a valid input\n", fileName);
                        allFilesValid=0;
                }
		else if(!isTextFile(fileName)&&doesFileExist(fileName)){
			printf("%s- is not a text file\n", fileName);
			allFilesValid=0;
		}
		else if(isTextFile(fileName)&&!doesFileExist(fileName)){
                        printf("%s- does not exist\n", fileName);
                        allFilesValid=0;
                }
	}
	if(!allFilesValid){
		printf("Not all files valid, please input valid files\n");
		exit(1);
	}
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
