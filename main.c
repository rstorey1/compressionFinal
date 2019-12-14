#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
//#include "huffman.c"
//#include "rle.c"

void commandLineInput(int, char **, int );//done?Maybe change it to return array of the names of files
int doesFileExist(char *);//done
int isTextFile(char *);//done
void printResults(int []);
//extern encode(char *, int);
int fileSize(char *);

int main(int argc, char *argv[]){
	int numberOfFiles;
       	numberOfFiles=argc-1;
	//commandLineInput(argc, argv, numberOfFiles);
	printf("file size is %d bytes \n",fileSize(argv[1]));
	

		
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
