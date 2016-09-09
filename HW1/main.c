#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]){
	char ** word_pointers;
	int current_size = 8;
	word_pointers = (char**)calloc(current_size, sizeof(char*));
	if(word_pointers==NULL)exit(1);


	FILE * input = fopen("hw1-input.txt", "r+");

	char buff[100];
	short end_check=0;
	int word_count = 0;
	int length = 0;
    while(1){
    	end_check=fscanf(input, "%s", buff);
    	if(end_check==-1)break; //end of reading

    	//additional character space for \0
    	length = strlen(buff)+1;
    	//set up mem alloc for this word
    	word_pointers[word_count]=malloc(length*sizeof(char)); 
    	//check pointer amount
    	if(word_count == current_size){
    		current_size*=2;
    		word_pointers = realloc(word_pointers, current_size*sizeof(char*));
    		printf("realloc to be %d pointers\n", current_size);
    	}

    	strcpy(word_pointers[word_count],buff);
    	++word_count;
    }  
#if 0
    for(int i=0; i<word_count; ++i){
    	printf("%s\n",word_pointers[i] );
    }
 #endif
  	printf("total %d words\n", word_count);

	fclose(input);

	//clean up
	for(int i=0; i<current_size; ++i){
		free(word_pointers[i]);
	}
	free(word_pointers);
	return EXIT_SUCCESS;
}