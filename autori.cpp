#include <iostream>
#include <cstdio>
#include <ctype.h>
#include <string>
using namespace std;

int main () 
{
      string string1;
          cin >> string1;
              for(int i =0; i < string1.length(); i++)
                    {
                              if (isupper(string1[i]))
                                        {
                                                      printf("%c", string1[i]);
                                                              }
                                                                  }
                                                                      printf("\n");
                                                                          return 0;
}
