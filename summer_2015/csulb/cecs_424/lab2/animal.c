/**
 * Joseph Okonoboh
 * Lab 2, SUMMER 2015 CECS 424
 * 
 *
 * animal.c
 */

#include <stdio.h>

#include "animal.h"

void Construct_Cat(Cat* a) {
   a->numberOfLives = MAX_CAT_LIVES;
   a->speak_fp = Speak_Cat;
   a->get_cost_fp = Get_Cost_Cat;
}

void Construct_Dog(Dog* a) {
   a->weight = 30.0;
   a->speak_fp = Speak_Dog;
   a->get_cost_fp = Get_Cost_Dog;
}

double Get_Cost_Cat(Animal* a) {
   Cat* c = (Cat*) a;
   return 100.00 + 5.50 * c->age - 8 * (9 - c->numberOfLives);
}

double Get_Cost_Dog(Animal* a) {
   Dog* d = (Dog*) a;
   return 7.50 * (d->weight / 3.0);
}

void Speak_Cat() {
   printf("Meow");
}

void Speak_Dog() {
   printf("Woof");
}
