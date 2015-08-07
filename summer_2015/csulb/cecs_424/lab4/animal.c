/**
 * Joseph Okonoboh
 * Lab 2, SUMMER 2015 CECS 424
 *
 * animal.c
 */

#include <stdio.h>

#include "animal.h"

static void* Cat_Vtable[2] = {Speak_Cat, Get_Cost_Cat};
static void* Dog_Vtable[2] = {Speak_Dog, Get_Cost_Dog};
static void* Lion_Vtable[2] = {Speak_Lion, Get_Cost_Cat};

void Construct_Cat(Cat* c) {
   c->numberOfLives = MAX_CAT_LIVES;
   c->vtable = Cat_Vtable;
}

void Construct_Dog(Dog* d) {
   d->weight = 30.0;
   d->vtable = Dog_Vtable;
}

void Construct_Lion(Lion* l) {
   Construct_Cat((Cat*) l);
   l->vtable = Lion_Vtable;
}

double Get_Cost_Cat(Animal* a) {
   Cat* c = (Cat*) a;
   return 100.00 + 5.50 * c->age - 8 * (MAX_CAT_LIVES - c->numberOfLives);
}

double Get_Cost_Dog(Animal* a) {
   Dog* d = (Dog*) a;
   return 7.50 * (d->weight / 3.0);
}

void Speak_Cat(Animal* a) {
   printf("Meow");
}

void Speak_Dog(Animal* a) {
   printf("Woof");
}

void Speak_Lion(Animal* a) {
   printf("ROAR! I weigh %.2f pounds", ((Lion*) a)->weight);
}