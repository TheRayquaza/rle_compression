/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description: Main program of the rle compression 
 *
 *        Version:  1.0
 *        Created:  08/18/22 23:40:57
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

#include "utils/utils.h"
#include "compress/compress.h"
#include "decompress/decompress.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Compress a file using the RLE compression. \n"); 
        printf("rle_compression <filenames> <...>\n");
    }
    else 
    {
        for (int i = 1; i < argc; i++)
        {
            if (file_exist(argv[i]))
            {
                char answer;
                printf("Compress / Decompress [C/D] %s\n", argv[i]);
                scanf("%c", &answer);
                if (answer == 'C')
                {
                    if (!compress(argv[i]))
                        printf("Unable to find %s\n", argv[i]);
                }
                else if (answer == 'D')
                {
                    if (!decompress(argv[i]))
                        printf("Unable to find %s\n", argv[i]);
                }
                else
                    printf("Invalid option %c !\n", answer);
            }
            else
                printf("Unable to find %s\n", argv[i]);
        }
    }
    return 0;
}
