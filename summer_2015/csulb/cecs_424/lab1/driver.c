#include <stdlib.h>
#include <stdio.h>

#include "allocator.h"

void test1();
void test2();
void test3();

int main() {
		printf("%d.\n", add(3));
		exit(0);
   if(my_initialize_heap(0) == HEAP_INIT_FAILURE) {
		fprintf(stderr, "The system couldn't initialize the allocator.\n");
		exit(1);
   }

   test1();
   //test2();

   my_free_heap();
   
	return EXIT_SUCCESS;
}

void test1() {
   int* x;

   printf("-------\n");
   printf("Test 1:\n");
   printf("-------\n");

   printf("\tAllocating memory for an integer...\n");
   x = (int*) my_allocate(sizeof(int));

   printf("\t\tThe address of this memory is: %p.\n\n", (void*) x);

   printf("\tFreeing memory %p...\n\n", (void*) x);
   my_free(x);

   printf("\tAllocating memory for another integer...\n");
   x = (int*) my_allocate(sizeof(int));

   printf("\t\tThe address of this memory is: %p.\n\n", (void*) x);

   printf("\tFreeing memory %p...\n\n", (void*) x);
   my_free(x);   
}

void test2() {
   int* x;
   int* y;

   printf("-------\n");
   printf("Test 2:\n");
   printf("-------\n");

   printf("\tAllocating memory for integer 1...\n");
   x = (int*) my_allocate(sizeof(int));

   printf("\t\tThe address of this memory is: %p.\n\n", (void*) x);

   printf("\tAllocating memory for integer 2...\n");
   y = (int*) my_allocate(sizeof(int));

   printf("\t\tThe address of this memory is: %p.\n\n", (void*) y);

   printf("\tFreeing memory...\n\n");
   my_free(x);
   my_free(y);

}
