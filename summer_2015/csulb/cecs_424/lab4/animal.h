/**
 * Joseph Okonoboh
 * Lab 4, SUMMER 2015 CECS 424 
 *
 * animal.h
 */

#ifndef _ANIMAL_H
#define _ANIMAL_H

#define MIN_CAT_LIVES 1
#define MAX_CAT_LIVES 9

typedef struct _Animal {
	void** vtable;
   int age;
} Animal;

typedef struct _Dog {
	void** vtable;
   int age;
   double weight;
} Dog;

typedef struct _Cat {
	void** vtable;
   int age;
   int numberOfLives;
} Cat;

typedef struct _Lion {
	void** vtable;
   int age;
   int numberOfLives;
   double weight;
} Lion;

void Construct_Cat(Cat* a);
void Construct_Dog(Dog* a);
void Construct_Lion(Lion* a);

double Get_Cost_Cat(Animal* a);
double Get_Cost_Dog(Animal* a);

void Speak_Cat(Animal* a);
void Speak_Dog(Animal* a);
void Speak_Lion(Animal* a);

#endif