#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H

#include <stdbool.h>

/* Question 1 */

// gets two floats x and y
// eturns the sum of all integers between x and y.
int sum_ints_interval(float x, float y);


/* Question 2 */

// gets a string str
// changes all digits of str to *,
// and returns the number of characters in the string that were modified.
int hide_digits(char* str);


/* Question 3 */

// gets an array of ints of length n
// returns the most frequent element in the array
// if there is more than one such element, the function may return any of them
// assumption: n>0
int most_frequent(const int* arr, int n);


/* Question 4 */

// gets pointers to three numbers
// sorts the numbers so that in the end *a <= *b <= *c
void sort3(int* a, int* b, int* c);


/* Question 5 */

// gets two strings that contain non-negative integers
// returns a string containing the sum of the two numbers
char* str_sum(const char* num1, const char* num2);

#endif
