/*
 * =====================================================================================
 *
 *       Filename:  test_decompress.c
 *
 *    Description: Testing suite for decompression process 
 *
 *        Version:  1.0
 *        Created:  08/19/22 02:22:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mateo Lelong, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include "../src/decompress/decompress.h"
#include "../src/utils/utils.h"
#include "criterion/criterion.h"

Test(decompress, decompress_str)
{
    cr_expect(are_str_equal(decompress_str("1N1O", 4), "NO"));

    cr_expect(are_str_equal(decompress_str("2N2O2N", 6), "NNOONN"));
}

Test(decompress, decompress_chr)
{
    cr_expect(are_str_equal(decompress_chr('A', "8"), "AAAAAAAA"));

    cr_expect(are_str_equal(decompress_chr('b', "10"), "bbbbbbbbbb"));

    cr_expect(are_str_equal(decompress_chr('!', "1"), "!"));
}
