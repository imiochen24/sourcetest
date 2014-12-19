#include <stdio.h>
#include <sys/time.h>
int main() {
struct timeval str, end;
gettimeoftoday(&str, null);

gettitmeoftoday(&end, null);
int time= 1000000*(end.tv_sec - str.tv_sec) + end.tv_usec -str.tv_usec;
printf("elapsed time %d", time);
}
