#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main(int argc,char *argv[]){
	
	if(argc != 3){
		printf("fewer arguements");
		exit(EXIT_FAILURE);
	}
	/*openeing input file*/
	FILE *fp = fopen(argv[1],"r");	

	if(!fp){
		printf("Not able to open input file");
		exit(EXIT_FAILURE);
	}
	/*opening output file*/
	FILE *ofp = fopen(argv[2],"w");
	
	printf("some message \" /* this is not a comment */");
	
	if(!ofp){
		printf("not able to open output file");
	}
	char curr = fgetc(fp);
	char next;
	bool started_comment = false;
	bool started_quotes = false;
	/*reading a file*/
	while (curr != EOF) {
		if(started_comment){
			if(curr == '*' && (next = fgetc(fp))== '/'){
				fputc('\n',ofp);	
				started_comment = false;	
			}
			else{
				fputc(curr,ofp);
			}
		}
		else if(started_quotes){
			if(curr == '\\'){
				next = fgetc(fp);
			}
			else if(curr == '"'){
				started_quotes = false;
			}
		}
		else{
		       	if(curr == '/' && (next = fgetc(fp)) == '*'){
				started_comment = true;
			}
			else if(curr == '"'){
				started_quotes = true;
			}
		}			
				curr = fgetc(fp);
	}
	/*work done successfully*/
	fclose(fp);
	fclose(ofp);
return 0;
}
