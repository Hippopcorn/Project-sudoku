#ifndef PARSE_H
# define PARSE_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "struct_values.h"

char *read_file();

struct cell  **parse_grid(char *buf);

#endif
