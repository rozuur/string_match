/*
 * string_match.c
 *
 *  Created on: 2013-7-19
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/time.h>
#include <unistd.h>

#include "string_match.h"

int substring_testcase1(char* sub, int sublen, char* target, int targetlen);
int test_substringcase1(void);

int main(int argc, char **argv)
{
	int rc;

#if 1
	rc= test_substringcase1();
#else
	rc= rabin_karp_test(argc, argv);
#endif

	return rc;
}

int test_substringcase1(void)
{
	char* sub;
	int sublen;
	char* target;
	int targetlen;
	int argc;
	char* argv[3];

	long mtime;
	struct timeval start, end;

	/**
	 * string
	 */
	sublen = 1024;
	sub = malloc (sublen);
	if(sub == NULL)
		return -1;

	targetlen = 1024*1024;
	target = malloc (targetlen);
	if(target == NULL)
	{
		free(sub);
		return -2;
	}

	substring_testcase1(sub, sublen, target, targetlen);

	argc=3;
	argv[0]="brute_force";
	argv[1]=sub;
	argv[2]=target;

	printf("test with %s\n", argv[0]);
    gettimeofday(&start, NULL);
	brute_force_test(argc, argv );
    gettimeofday(&end, NULL);
    mtime=getTimeDiffer(start, end);
	printf("done in %ld milliseconds\n", mtime);

	printf("test with %s\n", argv[0]);
    gettimeofday(&start, NULL);
    rabin_karp_test(argc, argv );
    gettimeofday(&end, NULL);
    mtime=getTimeDiffer(start, end);
	printf("done in %ld milliseconds\n", mtime);

    free(target);
	free(sub);

	return 0;
}

/**
 * patten: aaab
 * target: aaaaaaaaaaaaaaaaaab
 */
int substring_testcase1(char* sub, int sublen, char* target, int targetlen)
{
	int i;

	for(i=0;i<sublen-2;i++)
	{
		sub[i]='a';
	}
	sub[sublen-2]='b';
	sub[sublen-1]=0;


	for(i=0;i<targetlen-2;i++)
	{
		target[i]='a';
	}
	target[targetlen-2]='b';
	target[targetlen-1]=0;

	return 0;
}
