#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "assignment1.h"

bool test_q1_1()  {
  if (sum_ints_interval(1, 4)==10 && sum_ints_interval(10, 7.1)==27)  {
    printf("Q1-1 ok\n");
    return true;
  }
  else  {
    printf("Q1-1 ERROR\n");
    return false;
  }
}

bool test_q1_2()  {
  if (sum_ints_interval(-1.1, 0.2)==-1 && sum_ints_interval(-6.5, -6.3)==0)  {
    printf("Q1-2 ok\n");
    return true;
  }
  else  {
    printf("Q1-2 ERROR\n");
    return false;
  }
}


bool test_q2_1()  {
  char s[] = "abC1231";
  int ans = hide_digits(s);

  if (strcmp(s, "abC****")==0 && ans==4) {
    printf("Q2-1 ok\n");
    return true;
  }
  else  {
    printf("Q2-1 ERROR\n");
    return false;
  }
}


bool test_q2_2()  {
  char s[101]; // create s="a0a0a0a0a0..."
  for (int i = 0; i < 50; i++) {
    s[2*i] = 'a';
    s[2*i+1] = '0';
  }
  s[100] = '\0';

  char expected_result[101]; // create expected_result="a*a*a*a*a*..."
  for (int i = 0; i < 50; i++) {
    expected_result[2*i] = 'a';
    expected_result[2*i+1] = '*';
  }
  expected_result[100] = '\0';

  int ans = hide_digits(s);

  if (strcmp(s, expected_result)==0 && ans==50) {
    printf("Q2-2 ok\n");
    return true;
  }
  else  {
    printf("Q2-2 ERROR\n");
    return false;
  }
}


bool test_q3_1()  {
  int ar[6] = {1,7,-3,7,4,7};
  int ans = most_frequent(ar,6);

  if (ans==7) {
    printf("Q3-1 ok\n");
    return true;
  }
  else  {
    printf("Q3-1 ERROR\n");
    return false;
  }
}


#define LEN 101
bool test_q3_2()  {
  int ar[LEN];
  for (int i=0;i<LEN;i++)
    ar[i] = -2 - (i%2);
  int ans = most_frequent(ar,LEN);

  if (ans==-2) {
    printf("Q3-2 ok\n");
    return true;
  }
  else  {
    printf("Q3-2 ERROR\n");
    return false;
  }
}


bool test_q4_1()  {
  int x = 10, y = 2, z = 6;
  sort3(&x,&y,&z);

  if (x==2 && y==6 && z==10)  {
    printf("Q4-1 ok\n");
    return true;
  }
  else  {
    printf("Q4-1 ERROR\n");
    return false;
  }
}

bool test_q4_2()  {
  int x = 5, y = 0, z = 0;
  sort3(&x,&y,&z);

  if (x==0 && y==0 && z==5)  {
    printf("Q4-2 ok\n");
    return true;
  }
  else  {
    printf("Q4-2 ERROR\n");
    return false;
  }
}


bool test_q5_1()  {
  char* x1 = "15";
  char* y1 = "6";

  char* x2 = "88";
  char* y2 = "0";

  char* ans1 = str_sum(x1, y1);
  char* ans2 = str_sum(x2, y2);

 
  bool ok = ans1 && strcmp(ans1,"21")==0 &&
            ans2 && strcmp(ans2,"88")==0;
  if (ans1)
    free(ans1);
  if (ans2)
    free(ans2);

  if (ok)  {
    printf("Q5-1 ok\n");
    return true;
  }
  else  {
    printf("Q5-1 ERROR\n");
    return false;
  }
}

bool test_q5_2()  {
  char* x1 = "123456789123456789";
  char* y1 = "987654321987654321";

  char* x2 = "11111111111111111111111";
  char* y2 = "22222222222222222222222";

  char* ans1 = str_sum(x1, y1);
  char* ans2 = str_sum(x2, y2);

 
  bool ok = ans1 && strcmp(ans1,"1111111111111111110")==0 &&
            ans2 && strcmp(ans2,"33333333333333333333333")==0;
  if (ans1)
    free(ans1);
  if (ans2)
    free(ans2);

  if (ok)  {
    printf("Q5-2 ok\n");
    return true;
  }
  else  {
    printf("Q5-2 ERROR\n");
    return false;
  }
}


// when testing your code, it may be convenient 
// to comment out some of the test cases
// and focus only on the one you are working on right now
int main()  {
  test_q1_1();
  test_q1_2();
  
  test_q2_1();
  test_q2_2();
  
  test_q3_1();
  test_q3_2();

  test_q4_1();
  test_q4_2();
  
  test_q5_1();
  test_q5_2();
  
  return 0;
}
