/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * stats.h 
 * function declarations 
 *
 * declare only, do not implement it
 *
 * Chen Muye
 * Nov 25 2011
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

 
void print_statistics(char *p, int len);
/**
 * @brief: print out min, max mean and median of an array
 *
 * input array assumed to be integer
 *
 * @param int *p: a pointer pointing to the start of array
 * @param int len: length of the array
 
 * @return nothing
 */

void print_array(char *p, int len);
/**
 * @brief: print out the 1D int array
 * @param: int *p and int len
 * @return nothing
 */



#endif /* __STATS_H__ */
