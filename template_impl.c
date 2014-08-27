#include "template_impl.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


int get_rand_int()
{
    srand(time(NULL));
    return rand();
}

int get_hello_str(char *res, const char *name)
{
    return sprintf(res, "Hello, my dear %s!", name);
}
