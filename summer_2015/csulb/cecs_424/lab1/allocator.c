#include "allocator.h"

void* heap_ptr = NULL;

int BLOCK_OVERHEAD_SIZE = sizeof(Block);
Block* free_head;

void* my_allocate(int size) {
   /*
    * If an allocated block is being split, then this
    * will hold the data size of the unallocated portion.
    */
	int new_block_size;

   /*
    * The total number of bytes (plus overhead) that the
    * allocated block would have.
    */
	int overhead_plus_block_size = BLOCK_OVERHEAD_SIZE + size;

   /* The previous block in the iteration of the linked free blocks. */
   Block* prev_block = NULL;

   /* The current block in the iteration of the linked free blocks. */
   Block* current_block = free_head;
   
   /*
    * If an allocated block is being split, then this will
    * point to the unallocated portion.
    */
   Block* new_block = NULL;

   /* The block that will be allocated to the user. */
   Block* alloc_block = NULL;

   /* The address of the first byte of user data in the allocated block. */
   void* alloc_user_data = NULL;

   /* Get the first free block that is large enough. */
	while (current_block != NULL &&
         (current_block->block_size < size)) {
      prev_block = current_block;
		current_block = current_block->next_block;
	}

	if (current_block != NULL && size > 0) {
      /* The current block will be allocated. */
      alloc_block = current_block;

		new_block_size = alloc_block->block_size - overhead_plus_block_size;

      /*
       * Only split block if the remainder can hold overhead and
       * at least 1 byte of data.
       */
      if(new_block_size > BLOCK_OVERHEAD_SIZE) { /* split block */
		   alloc_block->block_size = size;

		   new_block = (Block*) (((unsigned char*) alloc_block) +
            overhead_plus_block_size);
		   new_block->block_size = new_block_size;
		   new_block->next_block = NULL;

         if(alloc_block == free_head) {
            free_head = new_block;
            free_head->next_block = alloc_block->next_block;
         } else {
            prev_block->next_block = new_block;
            new_block->next_block = alloc_block->next_block;
         }
      } else { /* do not split block (allocate all its size) */
         if(alloc_block == free_head) {
            free_head = alloc_block->next_block;
         } else {
            prev_block->next_block = alloc_block->next_block;
         }
      }

      alloc_user_data = (void*) (((unsigned char*) alloc_block) +
         BLOCK_OVERHEAD_SIZE);
	}
 
	return alloc_user_data;
}

void my_free(void* mem) {
	Block* temp = free_head;
	free_head = (Block*) (((unsigned char*) mem) - BLOCK_OVERHEAD_SIZE);
	free_head->next_block = temp;
}

void my_free_heap() {
	if(heap_ptr != NULL) {
      free(heap_ptr);
      heap_ptr = NULL;
   }
}

int my_initialize_heap(int size) {
   free_head = NULL;

	size = size <= 0 || size > MAX_HEAP_SIZE ? MAX_HEAP_SIZE : size; 

	heap_ptr = malloc(size);

	if (heap_ptr != NULL) {
	   free_head = (Block*) heap_ptr;

	   free_head->block_size = size - BLOCK_OVERHEAD_SIZE;
	   free_head->next_block = NULL;
      return HEAP_INIT_SUCCESS;
	}

	return HEAP_INIT_FAILURE;
}
