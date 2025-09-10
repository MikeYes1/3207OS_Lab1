#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    struct stat sb; 
    if (stat("yoo", &sb)!= 0) {
        perror("stat failed");
        return 1;
    }
    printf("%d\n", S_ISREG(sb.st_mode));
    
    return 0;
    
    /*
    
    FILE *fptr, *fptr2;
    char charHolder;
    int i = 1;
    size_t = e;
    char buffer[1024];
    struct stat sb; 
    //struct dirent **directory;
    
    int n = stat(const char *restrict path, struct stat *restrict buf);

    if (stat(argv[argc-1], &sb) == -1) {
        perror("lstat");
        exit(EXIT_FAILURE);
    }
    
    
      
    if(S_ISDIR(sb.st_mode)){
    
        while( i != length(argv) - 2 ){
      
            fptr = fopen(argv[i], "rb");
                absolute path?
                NULL check
             
            if(getcwd(buffer, sizeof(buffer - strlen(argv[i]))) != NULL){
                strcat(buffer, argv[i]); 
            } else {
                printf("getcwd() error");
            }
             
            fptr2 = fopen(buffer, "wb");
            
            while ((e = fread(&charHolder, 1, sizeof(charHolder), fptr)) > 0) {
                fwrite(charHolder, 1, e, fptr2);
            }
             
            fclose(fptr);
            fclose(fptr2);
         
            i++;
        }
    } else {
    
        fptr = fopen(argv[1], "rb");
            check nulls
        fptr2 = fopen(argv[2], "wb");
        
        
        while ((e = fread(&charHolder, 1, sizeof(charHolder), fptr)) > 0) {
            fwrite(charHolder, 1, e, fptr2);
        }
        
        /* Realized very late that we need to copy actual data of the files, not just
         * text. Went to ChatGPT for some ideas, saw this stucture that uses two
         * pointers in a while loop with fread and fwrite. *
        
        fclose(fptr);
        fclose(fptr2);

    */
}
