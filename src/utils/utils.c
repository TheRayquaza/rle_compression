/*
 * =====================================================================================
 *
 *       Filename:  utils.c
 *
 *    Description:  Utils' functions definitions for rle project
 *
 *        Version:  1.0
 *        Created:  08/18/22 23:59:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mateo Lelong, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

int are_str_equal(char * str1, char * str2)
{
    int i = 0;
    
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
        i++;

    return str1[i] == str2[i];
}

// Convert an int number into its 
char * convert_number(unsigned int number)
{
    if (number == 0)
        return "0";
    else 
    {
        char * str_number = malloc(0);
        int len  = 0;
        // Converting
        while (number != 0)
        {
            str_number = realloc(str_number,1);
            str_number[len] = convert_digit(number % 10);
            number /= 10;
            len++;
        }
        // Reverse
        int i = 0;
        while (i < len/2)
        {
            char tmp = str_number[i];
            str_number[i] = str_number[len - i - 1];
            str_number[len - i - 1] = tmp;
            i++;
        }
        str_number[len] = '\0';
        return str_number;
    }
}

// Convert a digit into its string representation
char convert_digit(unsigned int digit)
{
   return (char) (digit + 48); 
}

// Append a chracter into the string str
char * append_chr(char * str, char c)
{
    int len = strlen(str);
    char * tmp = malloc((len+1) * sizeof(char));

    strcpy(tmp, str);
    tmp[len] = c;
    tmp[len+1] = '\0';

    return tmp;
}

//Concat two strings 
char * concat_str(char * str1, char * str2)
{
    size_t i = 0;
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t len  = len1 + len2;
    char * str = calloc(len+1, sizeof(char));
    
    for (i = 0; i < len1; i++)
        str[i] = str1[i];
    for (i = len1; i < len; i++)
        str[i] = str2[i - len1];

    str[len] = '\0';

    return str;
}

// Remove the last null byte
char * remove_null_byte(char * str)
{
    int i = 0;
    size_t len = strlen(str);
    if (len == 0)
        return str;
    else
    {
        char * buffer = malloc(sizeof(char) * (len-1));
        while (str[i] != '\0')
        {
           buffer[i] = str[i];
           i++;
        }
        return buffer;
    }
}
// Verify whether a file exist
int file_exist(char * filename)
{
    FILE * f = fopen(filename, "r");
    if (f)
    {
        fclose(f);
        return 1;
    }
    else
        return 0;
}
