#include "my_tests.h"

#include "allocator.h"

#include <stdio.h>

void my_test_1() {
   int* A;
   int* B;

   printf("--------------------------------------------------\n");
   printf("                      Test 1.\n");
   printf("--------------------------------------------------\n");

   printf("\tAllocating memory for integer pointer A...\n");
   A = (int*) my_allocate(sizeof(int));

   printf("\t\tA is: %p.\n\n", (void*) A);

   printf("\tFreeing A...\n\n");
   my_free(A);

   printf("\tAllocating memory for integer pointer B...\n");
   B = (int*) my_allocate(sizeof(int));

   printf("\t\tB is: %p.\n\n", (void*) B);

   if(A == B) {
      printf("\tSuccess! A and B have equal addresses. \n\n");
   } else {
      fprintf(stderr, "\tFailure! A and B have different addresses.\n\n");
   }

   printf("\tFreeing B...\n\n");
   my_free(B);

   printf("--------------------------------------------------\n");
   printf("                  End of Test 1.\n");
   printf("--------------------------------------------------\n\n\n");
}

void my_test_2() {
   int* A;
   int* B;

   int dx = BLOCK_OVERHEAD_SIZE + sizeof(int);

   printf("--------------------------------------------------\n");
   printf("                      Test 2.\n");
   printf("--------------------------------------------------\n");

   printf("\tAllocating memory for integer pointer A...\n");
   A = (int*) my_allocate(sizeof(int));
   printf("\t\tA is: %p.\n\n", (void*) A);

   printf("\tAllocating memory for integer pointer B...\n");
   B = (int*) my_allocate(sizeof(int));
   printf("\t\tB is: %p.\n\n", (void*) B);

   if(((size_t)B - (size_t)A) == dx) {
      printf("\tSuccess! A and B are %d bytes apart.\n\n", dx);
   } else {
      fprintf(stderr, "\tFailure! A and B are not %d bytes apart.\n\n", dx);
   }

   printf("\tFreeing A...\n\n");
   my_free(A);

   printf("\tFreeing B...\n\n");
   my_free(B);

   printf("--------------------------------------------------\n");
   printf("                  End of Test 2.\n");
   printf("--------------------------------------------------\n\n\n");
}

void my_test_3() {
   int* A;
   int* B;
   int* C;
   double* D;

   int dx = BLOCK_OVERHEAD_SIZE + sizeof(int);

   printf("--------------------------------------------------\n");
   printf("                      Test 3.\n");
   printf("--------------------------------------------------\n");

   printf("\tAllocating memory for integer pointer A...\n");
   A = (int*) my_allocate(sizeof(int));
   printf("\t\tA is: %p.\n\n", (void*) A);

   printf("\tAllocating memory for integer pointer B...\n");
   B = (int*) my_allocate(sizeof(int));
   printf("\t\tB is: %p.\n\n", (void*) B);

   printf("\tAllocating memory for integer pointer C...\n");
   C = (int*) my_allocate(sizeof(int));
   printf("\t\tC is: %p.\n\n", (void*) C);

   printf("\tFreeing B...\n\n");
   my_free(B);

   printf("\tAllocating memory for double pointer D...\n");
   D = (double*) my_allocate(sizeof(double));
   printf("\t\tD is: %p.\n\n", (void*) D);

   if(((size_t)D - (size_t)C) == dx) {
      printf("\tSuccess! C and D are %d bytes apart.\n\n", dx);
   } else {
      fprintf(stderr, "\tFailure! C and D are not %d bytes apart.\n\n", dx);
   }

   printf("\tFreeing A...\n\n");
   my_free(A);

   printf("\tFreeing C...\n\n");
   my_free(C);

   printf("\tFreeing D...\n\n");
   my_free(D);

   printf("--------------------------------------------------\n");
   printf("                  End of Test 3.\n");
   printf("--------------------------------------------------\n\n\n");
}

void my_test_4() {
   int* my_array;
   int* A;

   int dx = BLOCK_OVERHEAD_SIZE + sizeof(int) * 100;

   printf("--------------------------------------------------\n");
   printf("                      Test 4.\n");
   printf("--------------------------------------------------\n");

   printf("\tAllocating memory for 100-integer array\n\tmy_array...\n");
   my_array = (int*) my_allocate(sizeof(int) * 100);
   printf("\t\tmy_array is: %p.\n\n", (void*) my_array);

   printf("\tAllocating memory for integer pointer A...\n");
   A = (int*) my_allocate(sizeof(int));
   printf("\t\tA is: %p.\n\n", (void*) A);

   if(((size_t)A - (size_t)my_array) == dx) {
      printf("\tSuccess! A and my_array are %d bytes apart.\n\n", dx);
   } else {
      fprintf(stderr, "\tFailure! A and my_array are not %d bytes apart.\n\n",
         dx);
   }

   printf("\tFreeing my_array...\n\n");
   my_free(my_array);

   printf("\tFreeing A...\n\n");
   my_free(A);

   printf("--------------------------------------------------\n");
   printf("                  End of Test 4.\n");
   printf("--------------------------------------------------\n\n\n");
}
