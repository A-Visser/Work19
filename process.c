#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>

#define STRINGSIZE 50

int main(){
  while(1){
    char line[STRINGSIZE];
    int input_pipe = open("input.pipe", O_RDONLY);
    if(errno == -1){
      printf("Error: %s", strerror(errno));
    }
    read(input_pipe, line, STRINGSIZE);
    close(input_pipe);
    int i;
    for(i = 0; i < strlen(line); i++){
      line[i] = toupper(line[i]);
    }
    int output_pipe = open("output.pipe", O_WRONLY);
    if(errno == -1){
      printf("Error: %s", strerror(errno));
    }
    write(output_pipe, line, STRINGSIZE);
    close(output_pipe);
  }
  return 0;
}
