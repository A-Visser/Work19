#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define STRINGSIZE 50
int main(){
  mkfifo("input.pipe",01644);
  mkfifo("output.pipe",01644);
  while(1){
    char line[STRINGSIZE];
    printf("input string: \n");
    fgets(line, STRINGSIZE, stdin);
    int input_pipe = open("input.pipe", O_WRONLY);
    if(errno == -1){
      printf("Error: %s", strerror(errno));
    }
    write(input_pipe, line, STRINGSIZE);
    close(input_pipe);
    int output_pipe = open("output.pipe", O_RDONLY);
    if(errno == -1){
      printf("Error: %s", strerror(errno));
    }
    read(output_pipe, line, STRINGSIZE);
    close(output_pipe);
    printf("Processed output: %s \n", line);
  }
  return 0;
}
