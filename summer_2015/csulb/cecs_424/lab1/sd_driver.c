/**
 * Joseph Okonoboh
 * Lab 1, SUMMER 2015 CECS 424
 *
 * A simple standard deviation program using dynamically allocated input
 * from our allocator.
 *
 * sd_driver.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "allocator.h"
#include "sd.h"

int main() {
   int i;           /* Used for indexing. */
   int n;           /* The number of data. */
   int* my_data;    /* The array to hold the data set. */
   int sum = 0;     /* The sum of the data set. */

   double mean;     /* The mean of the data set. */
   double sd = 0.0; /* The standard deviation of the data set. */

   /* Initialize allocator. */
   if(my_initialize_heap(MAX_HEAP_SIZE) == HEAP_INIT_FAILURE) {
		fprintf(stderr, "The system couldn't initialize the allocator.\n");
		exit(1);
   }

   my_welcome();                    /* Print greetings. */
   n = my_get_num_data();           /* Get the number of data. */
   my_data = my_process_input(n);   /* Input and store data. */

   /* Get the sum of data. */
   for(i = 0; i < n; ++i) {
      sum += my_data[i];
   }

   /* Get the mean. */
   mean = ((double) sum) / n;

   /* Get the standard deviation. */
   for(i = 0; i < n; ++i) {
      sd += ((double) my_data[i] - mean) * ((double) my_data[i] - mean);
   }

   sd = sqrt(sd / n);

   printf("The standard deviation of the data set is %f.\n", sd);

   my_free(my_data);

   /* Release allocator. */
   my_free_heap();
   
	return EXIT_SUCCESS;
}