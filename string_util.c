/*
 * string_util.c
 *
 *  Created on: 2013-7-19
 */

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>


/*
  Checks if char* q starts with char* p
 */
int strstarts(const char *p, const char *q)
{
  while(*p && *p == *q){
    ++p;
    ++q;
  }
  // if *p is null return false else return diff
  return *p ? *p - *q: 0;
}


int getTimeDiffer(struct timeval start,  struct timeval end)
{
    long mtime, seconds, useconds;

    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;

    return mtime;
}

