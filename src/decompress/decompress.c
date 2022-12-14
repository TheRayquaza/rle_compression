/*
 * =====================================================================================
 *
 *       Filename:  decompress.c
 *
 *    Description: Decoompress a file (compressed with RLE) 
 *
 *        Version:  1.0
 *        Created:  08/18/22 23:47:23
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
#include <unistd.h>

#include "../utils/utils.h"
#include "decompress.h"

// Compress a given file, return the sucess of the compress process
int decompress(char * filename)
{
    char * new_name = concat_str(filename, ".deco");

    if (file_exist(new_name) == 1)
    {
        char answer;

        printf("%s already exists, would you like to delete this file ? [Y/N]\n", new_name);
        scanf(" %c", &answer);
        // Yes anwser : delete the file
        if (answer == 'Y')
        {
            if (remove(new_name) != 0)
            {
                printf("Unable to remove %s\n", new_name);
                return 0;
            }
        }
        else
        {
            printf("%s was skipped\n", new_name);
            return 1;
        }

    }
    
    FILE * f = fopen(filename, "r");
    FILE * out = fopen(new_name, "w");
    
    char * line = NULL;
    size_t len = 0;
    size_t read;

    if (f)
    {
        while ((read = getline(&line, &len, f)) != -1)
        {
            char * tmp = decompress_str(line, len);
            fputs(tmp, out);
            free(tmp);
        }
        
        printf("--> %s decompressed and stored in %s \n",filename,new_name);

        fclose(f);
        fclose(out);
        if (line)
            free(line);
        return 1;
    }
    else
    {
        fclose(f);
        fclose(out);
        printf("An issue occured while opening the file %s\n", filename);
        return 0;
    }
    return 1;
 
}

// Compress a given string 
char * decompress_str(char * str, int len)
{
    int i = 0;
    char * decompressed = malloc(0);

    while (i < len)
    {
        // Getting the number of repeated characters
        char * str_number = malloc(sizeof(char));
        str_number[0] = '\0';
        while (i < len && is_digit(str[i]))
        { 
            str_number = append_chr(str_number, str[i]);
            i++;
        }
        str_number = append_chr(str_number, '\0');
        // Writting in the buffer the number of character
        char * tmp = decompress_chr(str[i], str_number);
        for (int j = 0; tmp[j] != '\0'; j++)
            decompressed = append_chr(decompressed, tmp[j]);
        // Free buffers
        free(tmp);
        free(str_number);
        i++;
    }

    return decompressed;
}

char * decompress_chr(char c, char * str_number)
{
    char * result = malloc(0);
    int i;
    
    int number = 0;
    for (i = 0; str_number[i] != '\0'; i++)
        number = number * 10 + ((int) str_number[i]) - 48;

    for (i = 0; i < number; i++)
        result = append_chr(result, c);

    result = append_chr(result, '\0');

    return result;
}

int is_digit(char c)
{
    int value = ((int) c) - 48;
    return value >= 0 && value <= 9;
}

