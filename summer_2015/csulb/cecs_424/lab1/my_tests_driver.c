/**
 * Joseph Okonoboh
 * Lab 1, SUMMER 2015 CECS 424
 *
 * Allocator testing.
 *
 * my_tests_driver.c
 */

#include <stdlib.h>
#include <stdio.h>

#include "allocator.h"
#include "my_tests.h"

int main() {
   if(my_initialize_heap(MAX_HEAP_SIZE) == HEAP_INIT_FAILURE) {
		fprintf(stderr, "The system couldn't initialize the allocator.\n");
		exit(1);
   }

   my_test_1();
   my_test_2();
   my_test_3();

   my_free_all_blocks();

   my_test_4();

   my_free_heap();
   
   return EXIT_SUCCESS;
}