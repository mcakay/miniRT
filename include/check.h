#ifndef CHECK_H
# define CHECK_H

#include "utils.h"

#define INT 4
#define DOUBLE 2
#define ARRAY 3
#define VALUE 1

void check_range(double min, double max, void *value, int *type);

#endif