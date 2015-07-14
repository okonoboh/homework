/**
 * Joseph Okonoboh
 * Lab 1, SUMMER 2015 CECS 424
 * A simple dynamic memory allocator that uses a free list.
 *
 * allocator.h
 */

#ifndef _ALLOCATOR_H
#define _ALLOCATOR_H

#define KB 1024
#define MAX_HEAP_SIZE 32 * KB

#define HEAP_INIT_SUCCESS 0
#define HEAP_INIT_FAILURE 1

typedef struct _Block {
	int block_size;
	struct _Block* next_block;
} Block;

/*
 * Book-keeping for a Block.
 */
extern int BLOCK_OVERHEAD_SIZE;

/*
 * The first free block.
 */
extern Block* free_head;

/**
 * Allocates memory on the allocator.
 *
 * @param: size ---  The number of bytes that the allocator should dynamically
 *                   allocate.
 *
 * @return      ---  Returns a pointer to the first byte of the newly allocated
 *                   data if there is sufficient memory; otherwise returns a
 *                   NULL pointer.
 */
void* my_allocate(int size);

/**
 * Frees memory.
 *
 * @param: mem  --- The address of the first byte of the data to be freed.
 */
void  my_free(void* mem);


/** 
 * Heap will have one free block (of maximum size) after this function
 * has returned.
 */
void my_free_all_blocks();


/**
 * Frees memory used by allocator. This should be called at the end of the
 * program, or when the allocator is no longer needed.
 */
void  my_free_heap();

/**
 * Initializes the allocator.
 *
 * @param: size ---  The total number of bytes of the allocator. If [size] is
 *                   nonpositive or greater than MAX_HEAP_SIZE, then the
 *                   allocator will default to MAX_HEAP_SIZE bytes.
 *
 * @return      ---  HEAP_INIT_SUCCESS
 *                      if the initialization was successful.
 *                   HEAP_INIT_FAILURE
 *                      if the initialization was not successful.
 */
int my_initialize_heap(int size);

#endif