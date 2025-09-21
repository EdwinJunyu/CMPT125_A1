#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assignment1.h"

int sum_ints_interval(float x, float y) {
  float minV, maxV;
  if (x<y)    //deciding which one is bigger;
  {
    minV = x;
    maxV = y;
  }else{
    minV = y;
    maxV = x;
  }

  int start = (int)minV;
  if (minV > 0 && minV != (float)start) {
      start = start + 1;   //round up; e.g 2.3 -> 3
  }

  int end = (int)maxV;
  if (maxV < 0 && maxV != (float)end) {
      end = end - 1;   //round down; -1.2 -> -2
  }

  if (start > end) {
      return 0;
  }

  int sum = 0;
  for (int i = start; i <= end; i++)
  {
    sum += i;   //sum up the intervel from minV to maxV
  }
  
  return sum;   //return sum, the data type is int;
}  

int hide_digits(char* str) {
  int i = 0;
  int count = 0;
  while (str[i] != '\0')  //go through the string
  {
    if (str[i] >= '0' && str[i] <= '9') //Checking targets by ACSII code;
    {
      count++;  //if it is a target, count plus one
      str[i] = '*';   // replace target from number to *
    }
    i++;  //go to next position
  } 
  
  return count;
}

int most_frequent(const int* arr, int n) {
  int res = arr[0];   //Initializing the return value firstly.
  int count = 0;
  int max = 0;
  if (n == 0) // empty array
  {
    return 0;
  }
  if (n == 1)   // only one element in array
  {
    return arr[0];  // return itself.
  }
  
  for(int i = 0; i < n; i++){   //go through array, point i; 
    for (int j = 0; j < n; j++)   //go through array, point j;
    {
      if (arr[i] == arr[j])   //check equal value
      {
        count++;
      } 
    }
    if (count > max)  //if the current element (its counting) bigger than the maximal number it recorded before, now cover the old data.
    {
      max = count;
      res = arr[i];   //update new res;
    }  
  }
  return res;
}


void sort3(int* a, int* b, int* c) {
  int temp = 0;   //set up temp value so that I can easy to exchange value.
  if (*a > *b)
  {
    temp = *a; //exchange a and b by intermediate variable - temp;
    *a = *b;
    *b = temp;
  }
  if (*a > *c)  //exchange a and c
  {
    temp = *a;
    *a = *c;
    *c = temp;
  }
  if (*b > *c)  //exchange b and c
  {
    temp = *b;
    *b = *c;
    *c = temp;
  }
}   //void function, no return value

char* str_sum(const char* num1, const char* num2) {
  int len1 = 0;
  int i = 0;
  while (num1[i] != '\0')   //get the len of num1
  {
    len1++;
    i++;
  }

  int len2 = 0;
  int j = 0;
  while (num2[j] != '\0')   //get the len of num2
  {
    len2++;
    j++;
  }
  int capacity = 0;
  if (len1>len2)
  {
    capacity = len1 + 2;  //plus two due to carry and '\0'
  }else{
    capacity = len2 + 2;
  }
  char* res = (char*)malloc(sizeof(char) * capacity);
  if (res == NULL)
  {
    return NULL;
  }
  int num1End = len1 - 1;   //get the last index of num1
  int num2End = len2 - 1;   //get the last index of num2
  int k = capacity -2;
  int carry = 0;
  res[capacity - 1] = '\0';   //set up return value - res array the ending signal
  while (num1End >= 0 || num2End >= 0 || carry > 0) {
      int di = (num1End >= 0) ? num1[num1End] - '0' : 0;  //figure out num1
      int dj = (num2End >= 0) ? num2[num2End] - '0' : 0;  //figure out num2
      int sum = di + dj + carry;
      res[k] = (char)('0' + (sum % 10));
      carry = sum / 10;
      num1End--;  //num1 go to next position, from right to left
      num2End--;   //num2 go to next position, from right to left
      k--;  //Move forward from the end of the result array
  }

  int start = k + 1;
  int resultLen = capacity - start;
  memmove(res, res + start, resultLen);   //Move the result to the beginning of the array
  return res;
}  