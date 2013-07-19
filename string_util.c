/*
 * string_util.c
 *
 *  Created on: 2013-7-19
 */

/*
  Checks if char* q starts with char* p
 */
int strstarts(const char *p, const char *q)
{
  while(*p && *p == *q){
    ++p;
    ++q;
  }
  // if *p is null return true else return diff
  return *p ? *p - *q: 0;
}




