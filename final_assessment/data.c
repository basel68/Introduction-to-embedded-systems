/**
 * @file data.c
 * @brief Abstraction of the basic data manipulation operations
 *
 * This implementation file provides an abstraction of the basic data manipulation operations
 * like converting integer to string and vice versa via function calls.
 * 
 * @author Bassel Mohammed 
 * 
 *
 */#include <stdint.h>
#include <stddef.h>
#include "memory.h"
#include "data.h"
#include "platform.h"


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
  uint8_t isNegative= 0;
  uint8_t digitCounter= 0;
  uint8_t remainder= 0;  

  // Check if data is zero
  if (data == 0)
  {
    *(ptr) = '0';
    *(ptr + 1) = '\0';
    return 2;
  }
  
  // Check if data is negative
  if (data < 0)
  {
    isNegative = 1;
    data = data*-1;
  }  
  // Convert int to ASCII for all bases
  while (data != 0)
  {
    remainder = data % base;
    *(ptr + digitCounter)= ( remainder > 9 ) ? ( remainder - 10 ) + 'a' : remainder + '0';
    digitCounter++;
    data= data / base;
  }  
  // Add -ve sign if negative data
  if (isNegative)
  {
    *(ptr + digitCounter) = '-';
    digitCounter++;
  }  
  digitCounter++;
  *(ptr + digitCounter) = '\0';

  // Reverse the string index order  
  my_reverse(ptr, (digitCounter - 1));
  
  return digitCounter;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
  int32_t number = 0;
  uint8_t isNegative = 0;

  // Check sign
  if(*ptr == '-')
  {
    isNegative = 1;
    // Move on to the next digit
    ptr++;
    // One less digit to deal with
    digits--;
  }

  digits--;

  for(int i = 0; i < digits; i++)
  {
     number = (*ptr >= 'a') ? (*ptr - 'a' + 10) : (*ptr - '0');
     ptr++;
  }

  // Apply the negative sign if needed
  if(isNegative)
  {
    number = -number;
  }

  return number;
}