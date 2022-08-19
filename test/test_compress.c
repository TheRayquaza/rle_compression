/*
 * =====================================================================================
 *
 *       Filename:  test_compress.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/19/22 02:13:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include "../src/utils/utils.h"
#include "../src/compress/compress.h"
#include "criterion/criterion.h"

Test(compress, compress_str)
{
    cr_expect(are_str_equal(compress_str("HHHBBB", 6), "3H3B"));

    cr_expect(are_str_equal(compress_str("NNNNNO", 6), "5N1O"));

    cr_expect(are_str_equal(compress_str("NONONO", 6), "1N1O1N1O1N1O"));
}
