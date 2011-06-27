#include<stdio.h>

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

/*
  Checks at each point if the needle is substring of haystack
 */
int brute_force(const char *needle, const char *haystack)
{
  const char *h = haystack;
  for(;*h;++h){
    if(strstarts(needle, h) == 0)
      return h - haystack;
  }
  return -1;
}

int main(int argc, char **argv)
{
#if DEBUG
  {
    char needle[100];
    char haystack[1000];
    while(scanf("%s %s", needle, haystack) != -1){
      int index = brute_force(needle, haystack);
      if(index >= 0)
        printf("Found %s in %s at %d\n", needle, haystack, index);
      else
        printf("Failed to find %s in %s\n", needle, haystack);
    }
  }
#elif
  if(argc < 3){
    printf("Usage : <command> <pattern> <string>\n");
    return 0;
  }
  int index = brute_force(argv[1], argv[2]);
  if(index >= 0)
    printf("Found %s in %s at %d\n", argv[1], argv[2], index);
  else
    printf("Failed to find %s in %s\n", argv[1], argv[2]);
#endif
  return 0;
}
