/*
 * =====================================================================================
 *
 *       Filename:  compress.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/18/22 23:55:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef COMPRESS
#define COMPRESS


// Compress a given file, returns the sucess of the compression process
int compress(char * filename);

// Compress a given string
char * compress_str(char * str, int len);

#endif /* ifndef COMPRESS */

