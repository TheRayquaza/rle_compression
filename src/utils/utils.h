/*
 * =====================================================================================
 *
 *       Filename:  utils.h
 *
 *    Description:  Utils' prototype for rle project
 *
 *        Version:  1.0
 *        Created:  08/18/22 23:59:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mateo Lelong, 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef UTILS
#define UTILS

// Verify whether two strings are equal
int are_str_equal(char * str1, char * str2);

// Convert a number into its string representation
char * convert_number(unsigned int number);

// Convert a digit into its character representation
char convert_digit(unsigned int digit);

// Add character to a string
char * append_chr(char * str, char c);

// Concat two strings into a single one
char * concat_str(char * str1, char * str2);

// Verify whether a file exists
int file_exist(char * filename);

#endif
