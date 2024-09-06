#include<stdio.h>
#include<stdlib.h>

void splitfile(const char *filename,int parts){
	FILE *file;
	file = fopen(filename,"rb");
	if(!file){
		printf("file not created\n");
		exit(EXIT_FAILURE);
	}

	fseek(file,0,SEEK_END);
	long filesize = ftell(file);
	fseek(file,0,SEEK_SET);

	long partSize = filesize/parts;
	long lastpartSize = partSize + (filesize%parts);
	
	char buffer[1024];
	size_t bytesRead;
	
	for(int i = 0;i < parts;i++){
		char partname[50];
		sprintf(partname,"%s.part%d",filename,i+1);
		
		FILE *part_file;
		part_file = fopen(partname,"wb+");

		if(!part_file){
			printf("file not created\n");
			exit(EXIT_FAILURE);
		}

		long curpart = (i == (parts-1))?lastpartSize:partSize;
		long written = 0;

		while(written < curpart && (bytesRead = fread(buffer,1,partSize,file)) > 0){
			fwrite(buffer,1,bytesRead,part_file);
			written += bytesRead;
		}
		fclose(part_file);
	}
	fclose(file);
	printf("files created\n");

}

int main(int argc,char *argv[]){
	
	if(argc != 3){
		printf("less arguements\n");
		return EXIT_FAILURE;
	}

	const char *filename = argv[1];
	int parts = atoi(argv[2]);

	if(parts <= 0){
		printf("parting not possible\n");
		return EXIT_FAILURE;
	}

	splitfile(filename,parts);

return 0;
}
