#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
   fork(); //make a child process of same type
   printf("Fork testing code\n");
   return 0;
}
