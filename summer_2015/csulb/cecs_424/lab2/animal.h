/**
 * Joseph Okonoboh
 * Lab 2, SUMMER 2015 CECS 424 
 *
 * animal.h
 */

#ifndef _ANIMAL_H
#define _ANIMAL_H

#define MIN_CAT_LIVES 1
#define MAX_CAT_LIVES 9

typedef struct _Animal {
	void (*speak_fp)(struct _Animal* a);
   double (*get_cost_fp)(struct _Animal* a);
   int age;
} Animal;

typedef struct _Dog {
	void (*speak_fp)(struct _Animal* a);
   double (*get_cost_fp)(struct _Animal* a);
   int age;
   double weight;
} Dog;

typedef struct _Cat {
	void (*speak_fp)(struct _Animal* a);
   double (*get_cost_fp)(struct _Animal* a);
   int age;
   int numberOfLives;
} Cat;

void Construct_Cat(Cat* a);
void Construct_Dog(Dog* a);

double Get_Cost_Cat(Animal* a);
double Get_Cost_Dog(Animal* a);

void Speak_Cat(Animal* a);
void Speak_Dog(Animal* a);

#endif