#include<stdio.h>

int strcmp(const char *p, const char *q)
{
  while(*p && *p == *q){
    ++p;
    ++q;
  }
  return *p - *q;
}

/*
  Checks at each point if the needle is substring of haystack
 */
int brute_force(const char *needle, const char *haystack)
{
  const char *h = haystack;
  while(*h++){
    if(strcmp(needle, h) == 0)
      return h - haystack;
  }
  return -1;
}

int main(int argc, char **argv)
{
  if(argc < 3){
    printf("Usage : <command> <pattern> <string>\n");
    return 0;
  }
  int index = brute_force(argv[1], argv[2]);
  if(index >= 0)
    printf("Found %s in %s at %d\n", argv[1], argv[2], index);
  else
    printf("Failed to find %s in %s\n", argv[1], argv[2]);
  return 0;
}
