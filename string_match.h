/*
 * string_match.h
 *
 *  Created on: 2013-7-19
 */

#ifndef STRING_MATCH_H_
#define STRING_MATCH_H_

extern int strstarts(const char *p, const char *q);

extern int brute_force(const char *needle, const char *haystack);
extern int brute_force_test(int argc, char **argv);

extern int hash(const char *str, int len);
extern int rehash(int hash, char remove, char add, int maxpow);
extern int mod_pow(int base, int pow, int mod);
extern int rabin_karp(const char *needle, const char *haystack);
extern int rabin_karp_test(int argc, char **argv);

#endif /* STRING_MATCH_H_ */
