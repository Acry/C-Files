#include <stdio.h>
#include <stdlib.h>

/* read file from argument and print to standard out */

char * read_file(char *);

int main(int argc, char **argv) {
	
    if (argc<2)
	    fprintf(stderr,"No file provided in arguments\n");
    if (argc>2)
	    fprintf(stderr,"Too many arguments, just reading one file.\n");
    if (argc==2){
	read_file(argv[1]);
	char * array=read_file(argv[1]);
	printf("%s",array);
    }
    return EXIT_SUCCESS;
}

char * read_file(char *filename)
{
	long length = 0;
	char *result = NULL;
	FILE *file = fopen(filename, "r");
	if(file) {
		int status = fseek(file, 0, SEEK_END);
		if(status != 0) {
			fclose(file);
			return NULL;
		}
		length = ftell(file);
		status = fseek(file, 0, SEEK_SET);
		if(status != 0) {
			fclose(file);
			return NULL;
		}
		result = malloc((length+1) * sizeof(char));
		if(result) {
			size_t actual_length = fread(result, sizeof(char), length , file);
			result[actual_length++] = '\0';
		} 
		fclose(file);
		return result;
	}
	fprintf(stderr,"Couldn't read %s", filename);
	return NULL;
}
