/**
 * Joseph Okonoboh
 * Lab 2, SUMMER 2015 CECS 424 
 *
 * driver.c
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal.h"
#include "allocator.h"

#define MAX_CHAR_PER_LINE 1024
#define DOG 1
#define CAT 2
#define INVALID 0

static char line[MAX_CHAR_PER_LINE];

int empty_string(char* string);
long int get_age();
long int get_animal_type();
long int get_cat_lives();
double get_dog_weight();

void print_animal(Animal* a);

int main() {
   Animal* a;
   Cat* c;
   Dog* d;

   long int type = get_animal_type();

   /* Initialize allocator. */
   if(my_initialize_heap(MAX_HEAP_SIZE) == HEAP_INIT_FAILURE) {
		fprintf(stderr, "The system couldn't initialize the allocator.\n");
		exit(1);
   }

   if(type == DOG) {
      d = (Dog*) my_allocate(sizeof(Dog));
      Construct_Dog(d);

      d->weight = get_dog_weight();
      a = (Animal*) d;
   } else { /* cat */
      c = (Cat*) my_allocate(sizeof(Cat));
      Construct_Cat(c);

      c->numberOfLives = get_cat_lives();
      a = (Animal*) c;
   }

   a->age = get_age();

   print_animal(a);

   my_free(a);

   return EXIT_SUCCESS;
}

int empty_string(char* string) {
   while(*string) {
      if(!isspace(*string++)) {
         return 0;
      }
   }
   
   return 1;
}

long int get_age() {
   long int age;
   char* next_char;

   do {
      printf("Enter the age of this animal (must be at least 1): ");
      fgets(line, MAX_CHAR_PER_LINE, stdin);
      age = strtol(line, &next_char, 10);

      if(age < 1 || !empty_string(next_char)) {
         age = INVALID;
         printf("\n\tError: invalid input...\n\n");
      }
   } while(age < 1);

   return age;
}

long int get_animal_type() {
   long int type;
   char* next_char;

   do {
      printf("Enter %d for dog and %d for cat: ", DOG, CAT);
      fgets(line, MAX_CHAR_PER_LINE, stdin);
      type = strtol(line, &next_char, 10);

      if((type != DOG && type != CAT) || !empty_string(next_char)) {
         type = INVALID;
         printf("\n\tError: invalid input...\n\n");
      }
   } while(type != DOG && type != CAT);

   return type;
}

long int get_cat_lives() {
   long int lives;
   char* next_char;

   do {
      printf("Enter number of cat lives (1 <= lives <= 9): ");
      fgets(line, MAX_CHAR_PER_LINE, stdin);
      lives = strtol(line, &next_char, 10);

      if(lives < MIN_CAT_LIVES || lives > MAX_CAT_LIVES ||
         !empty_string(next_char)) {
         lives = INVALID;
         printf("\n\tError: invalid input...\n\n");
      }
   } while(lives < MIN_CAT_LIVES || lives > MAX_CAT_LIVES);

   return lives;
}

double get_dog_weight() {
   double weight = 0.0;
   char* next_char;

   do {
      printf("Enter dog's weight (must be positive): ");
      fgets(line, MAX_CHAR_PER_LINE, stdin);
      weight = strtod(line, &next_char);

      if(weight <= 0.0 || !empty_string(next_char)) {
         printf("\n\tError: invalid input...\n\n");
         weight = 0.0;
      } 
   } while(weight <= 0.0);

   return weight;
}

void print_animal(Animal* a) {
   printf("Animal says: \"");
   a->speak_fp(a);
   printf("\"\n");
   printf("This animal costs: $%.2f.\n", a->get_cost_fp(a));
}