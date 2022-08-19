/*
 * =====================================================================================
 *
 *       Filename:  test_utils.c
 *
 *    Description:  Testing for utils' functions
 *
 *        Version:  1.0
 *        Created:  08/19/22 02:03:02
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

#include "../src/utils/utils.h"
#include "criterion/criterion.h"

Test(utils, are_str_equal)
{
    cr_expect(are_str_equal("Hello", "Hello"));

    cr_expect(!are_str_equal("Noooo", "Noooooooo"));

    cr_expect(are_str_equal("Hey you !", "Hey you !"));

}

Test(utils, convert_number)
{
    cr_expect(are_str_equal(convert_number(10), "10"));

    cr_expect(are_str_equal(convert_number(123456), "123456"));

    cr_expect(are_str_equal(convert_number(0), "0"));
}

Test(utils, convert_digit)
{
    cr_expect(convert_digit(0) == '0');

    cr_expect(convert_digit(9) == '9');
}

Test(utils, append_chr)
{
    char * test = append_chr("Hello", 'c');
    printf("%s", test);

    cr_expect(are_str_equal(append_chr("Hello", '!'), "Hello!"));

    cr_expect(are_str_equal(append_chr("", 'N'), "N"));

    cr_expect(are_str_equal(append_chr("Hey !", '!'), "Hey !!"));
}

Test(utils, concat_str)
{
   cr_expect(are_str_equal(concat_str("Hey ", "You !"), "Hey You !"));

   cr_expect(are_str_equal(concat_str("", "You !"), "You !"));
}
