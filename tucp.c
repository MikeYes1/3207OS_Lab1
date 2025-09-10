#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fptr, *fptr2;
    char charHolder; 
    int i = 1;
    size_t e;
    char buffer[1024];
    struct stat sb; 
    //struct dirent **directory; a relic of a forgotten time

    if (stat(argv[argc-1], &sb) == -1) {
        perror("lstat");
        exit(EXIT_FAILURE);
    }
    
    if(S_ISDIR(sb.st_mode)){
    
        while( i != sizeof(argv) - 2 ){
      
            fptr = fopen(argv[i], "rb");
            if(fptr == NULL) {
            printf("Could not locate file\n");
            exit(-1);
            }      
                
            /*Obtain the name of the current directory, store it in buffer, then append 
             * the destination directory and the file name to the variable*/
            if(getcwd(buffer, sizeof(buffer) - strlen(argv[i])) != NULL){
                strcat(buffer, "/");
                strcat(buffer, argv[argc-1]);
                strcat(buffer, "/");
                strcat(buffer, argv[i]); 
            } else {
                printf("getcwd() error");
            }
             
            fptr2 = fopen(buffer, "wb");
            if(fptr2 == NULL) {
            printf("Could not locate file\n");
            exit(-1);
            }  
            
            while ((e = fread(&charHolder, 1, 1, fptr)) > 0) {
                fwrite(&charHolder, 1, e, fptr2);
            }
             
            fclose(fptr);
            fclose(fptr2);
         
            i++;
        }
    } else {
    
        fptr = fopen(argv[1], "rb");
        if(fptr == NULL) {
        printf("Could not locate file\n");
        exit(-1);
        }  

        fptr2 = fopen(argv[2], "wb");
        if(fptr2 == NULL) {
        printf("Could not locate file\n");
        exit(-1);
        }  
        
        while ((e = fread(&charHolder, 1, 1, fptr)) > 0) {
            fwrite(&charHolder, 1, e, fptr2);
        }
        
        /* Realized very late that we need to copy actual data of the files, not just
         * text. Went to ChatGPT for some ideas, saw this stucture that uses two
         * pointers in a while loop with fread and fwrite. */
        
        fclose(fptr);
        fclose(fptr2);
    }
    
    return 0;
}
