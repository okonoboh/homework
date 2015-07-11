#include <stdlib.h>
#include <stdio.h>

#define INT_SIZE sizeof(int)
#define MEM_ADDRESS_SIZE sizeof(void*)

#define BLOCK_OVERHEAD_SIZE (INT_SIZE + MEM_ADDRESS_SIZE) 

typedef struct Block {
	int block_size;
	struct Block* next_block;
} Block;

Block* free_head;

void* my_initialize_heap(size_t size);
void* my_allocate(size_t size);
void my_free(void* mem);


void* my_initialize_heap(size_t size) {
	// Do error checking [1024 <= size <= (1024)^2]

	void* mem = malloc(size + BLOCK_OVERHEAD_SIZE);

	if (mem == NULL) {
		fprintf(stderr, "The system has insufficient memory.\n");
		exit(1);
	}

	free_head = (Block*) mem;

	free_head->block_size = size - BLOCK_OVERHEAD_SIZE;
	free_head->next_block = NULL;

	return mem;
}

void* my_allocate(size_t size) {
	int next_block_size;
	int minimum_block_size = BLOCK_OVERHEAD_SIZE + size;

	while (free_head != NULL && (free_head->block_size < minimum_block_size)) {
		free_head = free_head->next_block;
	}

	if (free_head != NULL) {
		next_block_size = free_head->block_size - minimum_block_size;
		free_head->block_size = size;
		free_head = (Block*) (((unsigned char*) free_head) + minimum_block_size);
		free_head->block_size = next_block_size;
		free_head->next_block = NULL;
	}
	else {
		fprintf(stderr, "There are no blocks available for use.\n");
	}

	return free_head;
}


void my_free(void* mem) {
	// TODO Check mem is within legal bounds
	Block* temp = free_head;
	free_head = (Block*) mem;
	free_head->next_block = temp;
}


int main() {
	
	printf("The size of an integer is %d.\n", INT_SIZE);
	printf("The size of a memory address is %d.\n", MEM_ADDRESS_SIZE);
	return EXIT_SUCCESS;
}