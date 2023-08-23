/**
 * @file data.h
 * @brief Abstraction of some basic data manipulation
 *
 * This header file provides an abstraction of the basic data manipulation,
 * converting data from int to ASCII, and vice-versa
 *
 * @author Bassel Mohamed
 *
 *
 */

#ifndef __data_H__
#define __data_H__
#include <stdint.h>  
#include <math.h>

/**
 * @brief Converts given data from integer to ASCII string
 *
 * Given a pointer to a char dataset, this will set a provided
 * index into that dataset to the value provided.
 * Regarding the signed numbers, the function handles the base 10 signed numbers only.
 *
 * @param data The int number to be converted
 * @param ptr Pointer to data array
 * @param base Base to convert to
 *
 * @return length of the converted data.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts given data from ASCII string to integer
 *
 * Given a pointer to a char dataset, this will set a provided
 * index into that dataset to the value provided.
 * The function handles the base 10 signed numbers.
 *
 * @param ptr Pointer to the string to be converted
 * @param digits Number of digits in the character set
 * @param value Base to convert to
 *
 * @return the converted integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

/**
 * @brief Calculates the power of a nymber
 * 
 * @param number The base number
 * @param power The power factor
 *
 * @return the result.
 */
int32_t powerFunction(int32_t number, uint8_t power);
#endif