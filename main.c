#include <stdio.h>
#include "template_impl.h"

int main(void)
{
    printf("Hello World!!! %d\n", get_rand_int());
    char buff[0x0100];
    int len = get_hello_str(buff, "Alexey");
    printf("%s\t%d\n", buff, len);
    return 0;
}

