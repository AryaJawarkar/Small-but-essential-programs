#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int main(int argc,char *argv[]){

	if(argc != 2){
		printf("less arguements\n");
		exit(EXIT_FAILURE);
	}	

	FILE *file = fopen((const char *)argv[1],"wb");

	if(!file){
		printf("file not created\n");
		exit(EXIT_FAILURE);
	}
	
	char buffer[1024];
	size_t bytesRead = 0;
	size_t partNumber = 1;
	char part_Name[50];
	bool break_the_loop = true;

	while(break_the_loop){
		
		sprintf(part_Name,"%s.part%lu",argv[1],partNumber);
		FILE *part_file = fopen(part_Name,"rb");
		if(!part_file){
			break_the_loop = false;
			exit(EXIT_FAILURE);
		}
		
		while((bytesRead = fread(buffer,1,sizeof(buffer),part_file)) > 0){
			fwrite(buffer,1,bytesRead,file);
		}
	
		fclose(part_file);

		partNumber += 1;
	}

	fclose(file);

return 0;
}
