#ifndef _ALLOCATOR_H
#define _ALLOCATOR_H

#include <stdlib.h>

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
 * Frees memory used by allocator. This should be called at the end of the
 * program, or when the allocator is no longer needed.
 */
void  my_free_heap();

/**
 * Initializes the allocator.
 *
 * @param: size ---  The total number of bytes of the allocator. If [size] is
 *                   nonpositive or greater than 32KB, then the allocator will
 *                   be 32 kilo bytes.
 *
 * @return      ---  HEAP_INIT_SUCCESS
 *                      if the initialization was a success.
 *                   HEAP_INIT_FAILURE
 *                      if the initialization was not success.
 */
int my_initialize_heap(int size);








/*void  print_mem(void* mem) {
   Block* head = (Block*) mem;
   int i = 1;
   int total = 0;

   do {
      printf("Block %d:\n\tSize: %5d\tData: %p\n\n", i++, head->block_size,
         ((unsigned char*) head) + BLOCK_OVERHEAD_SIZE);
      total += (BLOCK_OVERHEAD_SIZE + head->block_size);
      head = (Block*) (((unsigned char*) head) +
         BLOCK_OVERHEAD_SIZE + head->block_size);
   } while(total < MAX_HEAP_SIZE);
}

void  print_free_list() {
   Block* head = free_head;
   int i = 1;
   
   while(head != NULL) {
      printf("Free Block %d:\n\t\tSize: %5d\tData: %p\n\n", i++,
         head->block_size, ((unsigned char*) head) + BLOCK_OVERHEAD_SIZE);
      
      head = head->next_block;
   }
}*/

#endif
