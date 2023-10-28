/**
 *
 * Silly little standard library for tost.
 * Intended to be deleted and replaced by a tost native stdlib sooner than later
 *
 * Just exists to make writing programs nicer
 *
 */

#include <stdio.h>

/**
 * print an i64
 **/
void printd(long x) {
    printf("%ld", x);
}

/**
 * print a char
 **/
void printc(char x) {
    char c = x;
    putc(c, stdout);
}

/**
 * test if two chars are equal.
 * exists because i dont have operator overloading (yet)
 **/
char char_eq(char a, char b) {
    return a == b;
}

/**
 * test if two chars are not equal.
 * exists because i dont have operator overloading (yet)
 **/
char char_neq(char a, char b) {
    return a != b;
}
