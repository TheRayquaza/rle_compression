/*
 * =====================================================================================
 *
 *       Filename:  compress.c
 *
 *    Description: Compress a file (compressed with RLE) 
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
#include "compress.h"

// Compress a given file, return the sucess of the compress process
int compress(char * filename)
{
    char tmp[] = ".compress";
    char * new_name = concat_str(filename, tmp);

    if (file_exist(new_name) == 1)
    {
        char answer;

        printf("%s already exists, would you like to delete this file ? [Y/N]\n", new_name);
        scanf("%c", &answer);
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
    FILE * out = fopen(new_name, "w+");
    
    char * line = NULL;
    size_t len = 0;
    size_t read;

    if (f)
    {
        while ((read = getline(&line, &len, f)) != -1)
        {
            char * tmp = compress_str(line, len);
            fputs(tmp, out);
            free(tmp);
        }
        
        printf("--> %s compressed and stored in %s \n",filename ,new_name);

        fclose(f);
        fclose(out);
        if (line)
            free(line);
        return 1;
    }
    else
    {
        printf("An issue occured while opening the file %s\n", filename);
        return 0;
    }
    return 1;
 
}

// Compress a given string 
char * compress_str(char * str, int len)
{
    int i = 0;
    char * compressed = malloc(0);

    while (i < len)
    {
        // Getting the number of repeated characters
        char current = str[i];
        if (current == '\n')
        {
            compressed = append_chr(compressed, '\n');
            i++;
        }
        else 
        {
            int count = 0;
            while (i < len && str[i] == current)
            {
                count++;
                i++;
            }
            // Writting in the buffer the number of character
            char * digit_str = convert_number(count);
            for (int j = 0;  digit_str[j] != '\0'; j++)
                compressed = append_chr(compressed, digit_str[j]);
            compressed = append_chr(compressed, current);
        }
    }

    return compressed;
}


