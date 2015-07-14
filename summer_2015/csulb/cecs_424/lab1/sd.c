/**
 * Joseph Okonoboh
 * Lab 1, SUMMER 2015 CECS 424
 *
 * Module for simple standard deviation program.
 *
 * sd.c
 */

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "sd.h"
#include "allocator.h"

#define MAX_NUM_DATA ((MAX_HEAP_SIZE - BLOCK_OVERHEAD_SIZE) / sizeof(int))
#define MAX_CHAR_PER_LINE 1024

static char line[MAX_CHAR_PER_LINE];

int is_line_valid(const char* string) {
   size_t num_digits = 0;
   size_t string_length = strlen(string);
   size_t i;

   for(i = 0; i < string_length; ++i) {
      if((string[i] == '-' && (
         i == (string_length - 1) || !isdigit(string[i + 1]) ||
         (i != 0 && !isspace(string[i - 1])))) ||
         (string[i] != '-' && !isdigit(string[i]) && !isspace(string[i]))) {
         return 0;
      }

      if(isdigit(string[i])) {
         ++num_digits;
      }
   }

   return num_digits > 0 ? 1 : 0;
}

int my_get_num_data() {
   int n;

   do {
      printf("Please enter n, the number of data (1 <= n <= %ld): ",
         MAX_NUM_DATA);
      
      fgets(line, MAX_CHAR_PER_LINE, stdin);

      n = is_line_valid(line) ? atoi(line) : 0;
   } while(n < 1 || n > (int) MAX_NUM_DATA);

   return n;
}

int* my_process_input(int n) {
   int* my_data = (int*) my_allocate(n * sizeof(int));
   int current_index = 0;
   char* integer_string;

   printf("\nPlease enter your data:\n");
   printf("   You may enter more than 1 integer (separated by whitespace);\n");
   printf("   however, each line may not have more than 1023 characters.\n\n");

   while(current_index < n) {
      printf(":  ");
      fgets(line, MAX_CHAR_PER_LINE, stdin);

      if(is_line_valid(line)) {
         integer_string = strtok(line, " ");

         while (integer_string != NULL && current_index < n) {
            my_data[current_index++] = atoi(integer_string);
            integer_string = strtok (NULL, " ");
         }

         if(current_index < n) {            
            printf("%d more to enter.\n", n - current_index);
         }
      } else {
         printf("Your data is invalid. Please re-enter.\n");
      }
   }

   return my_data;
}

void my_welcome() {
   printf("\n------------------------------------------\n");
   printf("Welcome to the standard deviation program.\n");
   printf("------------------------------------------\n\n");
}