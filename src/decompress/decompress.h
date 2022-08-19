/*
 * =====================================================================================
 *
 *       Filename:  compress.h
 *
 *    Description:  Prototypes for the decompression process
 *
 *        Version:  1.0
 *        Created:  08/18/22 23:55:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mateo Lelong, 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef DECOMPRESS
#define DECOMPRESS


// Decompress a given file, returns the sucess of the compression process
int decompress(char * filename);

// Decompress a given string
char * decompress_str(char * str, int len);

// Decompress a chr and returns its decompress version
char * decompress_chr(char c, char * str_number);

#endif

