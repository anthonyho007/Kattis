// #include <stdlib.h>
// #include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main () {
        char date[100];
        char input_format[100];
        char out_format[100];
        char year[5];
        char month[3];
        char day[3];
        int ctr = 0;
        while (scanf("%s %s %s", date, input_format, out_format)==3) {
                // search for year, month and day
                int size = strlen(input_format);
                int year_f = 0;
                int month_f = 0;
                int day_f = 0;
                for ( int i = 0; i < size; i++)
                {
                        if ( input_format[i] == 'y' && year_f == 0) {
                                for( int j = 0; j < 4; j++ ) {
                                        year[j] = date[i+j];
                                        // printf("%c", year[j]);
                                }
                                i += 4;
                                year_f = 1;
                        }
                        else if ( input_format[i] == 'm' && month_f == 0) {
                                for (int j = 0; j < 2; j++) {
                                        month[j] = date[i+j];
                                        // printf("%c", month[j]);
                                }
                                i+= 2;
                                month_f = 1;
                        } else if ( input_format[i] == 'd' && day_f == 0) {
                                for (int j = 0; j <2 ; j++ ) {
                                        day[j] = date[i+j];
                                        // printf("%c", day[j]);
                                }
                                i += 2;
                                day_f = 1;
                        }
                }
                // finished extraction, now to put them in place
                int size2 = strlen(out_format);
                int year_f2 = 0;
                int month_f2 = 0;
                int day_f2 = 0;
                for ( int i = 0; i < size2; i++)
                {
                        if ( out_format[i] == 'y' && year_f2 == 0) {
                                for( int j = 0; j < 4; j++ ) {
                                        out_format[i+j] = year[j];
                                        // printf("%c", year[j]);
                                }
                                i += 4;
                                year_f = 1;
                        }
                        else if ( out_format[i] == 'm' && month_f2 == 0) {
                                for (int j = 0; j < 2; j++) {
                                        out_format[i+j] = month[j];
                                        // month[j] = date[i+j];

                                }
                                i+= 2;
                                month_f = 1;
                        } else if ( out_format[i] == 'd' && day_f2 == 0) {
                                for (int j = 0; j <2 ; j++ ) {
                                        out_format[i+j] = day[j];
                                        // day[j] = date[i+j];
                                }
                                i += 2;
                                day_f = 1;
                        }
                }
                // print out_format out
                printf("%s", out_format);
        }
        
}
