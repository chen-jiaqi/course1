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
 * @file stats.c
 * @brief implement functions and the main()
 *
 * all functions except main() have been declared in stats.h
 *
 * @author Chen JIaqi
 * @date Nov 25 2020
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  int test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  int *p;
  int len;
  p = test;
  len = 30;

  print_array(p, len);

  int avg;
  avg = find_mean(p, len);
  printf("\tMean = %d\n", avg);

  int max;
  max = find_maximum(p,len);
  printf("\tMax = %d\n", max);

  int min;
  min = find_minimum(p,len);
  printf("\tMin = %d\n", min);

  int test2[SIZE];
  for (int i = 0; i<SIZE; i++){test2[i]=test[i];}
  int *q = sort_array(test2,len);
  print_array(q,len);

  int med;
  med = find_median(q,len);
  printf("\tMedian = %d\n", med);
}

/* Add other Implementation File Code Here */
void print_array(int *p, int len) {
  int print_size;
  if (len<SIZE){
    print_size = len;
  }
  else {
    print_size = SIZE;
  }
  printf("This is the target array:\n");
  for(int i = 0; i < print_size; i++){
    if ((i + 1)%8 > 0){
      printf("%d\t", *(p+i));
    }
    else {
      printf("%d\n", *(p+i));
    }
  }
  printf("\n");
}

/* locat function */
int find_mean(int *p, int len) {
  int stats_size;
  int stats_avg;
  stats_size = len;
  stats_avg = 0;

  if(stats_size>SIZE){
    stats_size = SIZE;
  }
  for (int i = 0; i < stats_size; i++){
    stats_avg += *(p+i);
  }
  stats_avg = stats_avg/SIZE;
  return stats_avg;
}

/* local function*/
int find_maximum(int *p, int len) {
  int stats_size = len;
  if(stats_size>SIZE) {
    stats_size = SIZE;
  }
  int max = *p;
  for(int i=0; i<stats_size; i++){
    if(max<*(p+i)){
      max = *(p+i);
    }
  }
  return max;
}

/* local function */
int find_minimum(int *p, int len) {
  int stats_size = len;
  if (stats_size > SIZE){
    stats_size = SIZE;
  }
  int min = *p;
  for(int i=0; i<stats_size; i++){
    if(min>*(p+i)){
      min = *(p+i);
    }
  }
  return min;
}

/* local function */
int find_median(int *p, int len) {
  int stats_size = len;
  if (stats_size > SIZE){
    stats_size = SIZE;
  }
  int med = *(p+len/2-1);

  return med;
}

/* local function*/
int * sort_array2(int *p, int len){
  int stats_size = len;
  if (stats_size > SIZE){
    stats_size = SIZE;
  }
  int test[stats_size];
  int temp;

  for (int i = 0; i<stats_size; i++){
    test[i] = *p;
    p++;
  }


  for (int i = 0; i<stats_size; i++){
    for (int j = i+1; j<stats_size; j++){
        if (test[i]<test[j]){
          temp = test[i];
          test[i]=test[j];
          test[j]=temp;
        }
    }
  }
  print_array(test, stats_size);
  return p;
}

/* local function*/
int * sort_array(int *p, int len){
  int stats_size = len;
  if (stats_size > SIZE){
    stats_size = SIZE;
  }
  int temp;

  for (int i = 0; i<stats_size; i++){
    for (int j = i+1; j<stats_size; j++){
        if (*(p+i)<*(p+j)){
          temp = *(p+i);
          *(p+i)=*(p+j);
          *(p+j)=temp;
        }
    }
  }
  return p;
}
