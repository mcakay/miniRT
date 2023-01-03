#ifndef UTILS_H
#define UTILS_H

#define FILE_ERR 1
#define INVALID_ELEMENT_ERR 2
#define INVALID_RANGE_ERR 3

void ft_free(char **strs);
void ft_error(char *str, int error_code);
int *ft_atoi_array(char **strs);
double *ft_atod_array(char **strs);

#endif