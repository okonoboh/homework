#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMCHAR   1024

static void* child_infinite(void* unused) {
   while(1) {
      sleep(5);
      printf("I am stuck in an infinite loop.\n");
   }

   return NULL;
}

static void eat_input() {
   char unused_string[NUMCHAR];

   fgets(unused_string, NUMCHAR >> 1, stdin);
}

int main(int argc, char* argv[]) {
   pthread_t child_thread;
   int code;

   code = pthread_create(&child_thread, NULL, child_infinite, NULL);

   if(code) {
      fprintf(stderr, "pthread_create failed with code %d.\n", code);
      exit(EXIT_FAILURE);
   }

   printf("Please enter a string: ");
   eat_input();

   code = pthread_cancel(child_thread);

   if(code) {
      fprintf(stderr, "pthread_cancel failed with code %d.\n", code);
      exit(EXIT_FAILURE);
   }

   printf("Main thread: I have terminated the useless child thread.\n");

   return EXIT_SUCCESS;
}
