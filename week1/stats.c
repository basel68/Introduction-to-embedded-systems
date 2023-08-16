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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

   /* Other Variable Declarations Go Here */
  unsigned char minimum = 0;
  unsigned char maximum = 0;
  float mean = 0;
  unsigned char median = 0;

  /* Statistics and Printing Functions Go Here */
  printf("Array before sorting: \n");
  print_array(&test, SIZE);
  median = find_median(&test, SIZE);
  mean = find_mean(&test, SIZE);
  maximum = find_maximum(&test, SIZE);
  minimum = find_minimum(&test, SIZE);
  print_statistics(minimum, maximum, mean, median);
  sort_array(&test, SIZE);
  printf("Array after sorting: \n");
  print_array(&test, SIZE);
} 


void print_statistics (unsigned char minimum, unsigned char maximum, float mean, unsigned char median){
  printf("The minimum is %d \n", minimum);
  printf("The maximum is %d \n", maximum);
  printf("The mean is %f \n", mean);
  printf("The median is %d \n", median);
}

float find_mean (char *ptr, int count){
  unsigned int accumulator = 0; // variable to store the accumulator value throughout the mean finding process
  float mean = 0;
  for (int i=0; i<count; i++){
    accumulator = accumulator + ptr[i] /* *(ptr + i) */;
  }
  printf("acc = %d \n", accumulator);
  mean = accumulator / ((float) count); //must type cast one of the two integers to float for accurate calculation.
  return mean;
}


void print_array (char *ptr,int count){
  for (int i=0; i<count; i++){
    printf("%d,", *(ptr + i));
  }
  printf("\n");
}
int find_median (char *ptr, int count){
  unsigned char median = 0;
  median = *(ptr + (count / 2) -1);
  return median;
}


int find_maximum(char * ptr, int count){
int max=*ptr;

 for (int i=1; i<count; i++){ 
    if (*(ptr + i) > max){
      max= *(ptr + i);
    }
    
  }

return max;

}
int find_minimum(char * ptr, int count){
  int min=*ptr;

for (int i=1; i<count; i++){ 
    if (*(ptr + i) < min){
      min= *(ptr + i);
    }
    
  }

return min;
} 

void sort_array (unsigned char *array, unsigned int count){
  char flag = 0; //this flag is to indicate if a swap process has occurred at least once in the loop
  unsigned char temp;
  do {
    flag =0; //set flag to default at every new 'do' operation
    for (int index=0; index<count; index++){
      if (array[index] > array[index +1] || array[index] == array[index +1]) {
        continue;
      }
      else if (array[index] < array[index +1]) {
        //swap elements//
        temp = array[index];
        array[index] = array[index+1];
        array[index+1] = temp;

        flag = 1; // a swap process has occurred at least once in this loop
      }
    }
  }
  while (flag ==1); // the array is not sorted as long as a swap operation is occurred at least once
}








/* Add other Implementation File Code Here */
