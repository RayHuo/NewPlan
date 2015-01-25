/* 
 * File:   util.h
 * Author: yzf
 *
 * Created on January 24, 2015, 11:22 PM
 */

#ifndef UTIL_H
#define	UTIL_H

#include <cstdio>
#include "EpisDNF.h"

void print(FILE *out, const PropTerm &prop_term, bool print_new_line = false);
void print(FILE *out, const PropDNF &prop_dnf, bool print_new_line = false);
void print(FILE *out, const EpisTerm &epis_term, bool print_new_line = false);
void print(FILE *out, const EpisDNF &epis_dnf);

#endif	/* UTIL_H */

