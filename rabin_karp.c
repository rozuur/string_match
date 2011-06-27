#include<stdio.h>
#include<string.h>

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

int hash(const char *str, int len)
{
  return 1;
}

int rehash(int hash, char remove, char add)
{
  return 1;
}

/*
  Implemented using rolling hash function.
 */
int rabin_karp(const char *needle, const char *haystack)
{
  // Rolling hash function for needle is calculated.
  int len = strlen(needle);
  int hash_needle = hash(needle, len);
  int roll_hash = hash(haystack, len);
  
  const char *win_start = haystack;
  const char *win_end = haystack + len;
  for(;hash_needle != roll_hash; ++win_end, ++win_start){
    if(*win_end == '\0')
      return -1;
    roll_hash = rehash(roll_hash, *win_start, *win_end);
  }
  return strstarts(needle, win_start);
}

int main(int argc, char **argv)
{
#if DEBUG
  {
    char needle[100];
    char haystack[1000];
    while(scanf("%s %s", needle, haystack) != -1){
      int index = rabin_karp(needle, haystack);
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
  int index = rabin_karp(argv[1], argv[2]);
  if(index >= 0)
    printf("Found %s in %s at %d\n", argv[1], argv[2], index);
  else
    printf("Failed to find %s in %s\n", argv[1], argv[2]);
#endif
  return 0;
}
