/**
 * Joseph Okonoboh
 * Lab 1, SUMMER 2015 CECS 424
 *
 * Header for simple standard deviation program.
 *
 * sd.h
 */

#ifndef _STANDARD_DEVIATION_H
#define _STANDARD_DEVIATION_H

/**
 * Checks if string contains only integers separated by whitespace.
 *
 * @param: string ---  A null terminated string.
 *
 * @return        ---  1 : if string contains only integers
 *                         separated by whitespace
 *                      
 *                     0 : otherwise.
 *
 * @note          --- Positive integers may not have the prefix '+'                   
 */
int is_line_valid(const char* string);

/**
 * Prompts the user till he or she enters a valid positive integer
 * in some given range.                   
 */
int my_get_num_data();

/**
 * Reads n integers from the standard input stream and stores them
 * in an n-size integer array.
 *
 * @param: n      ---  A positive integer indicating the number of integers
 *                     to read from the standard input stream.
 *
 * @return        ---  A pointer to the first integer.                 
 */
int* my_process_input(int n);

/**
 * Initial welcome message. Should be called upon program start up.                   
 */
void my_welcome();

#endif
