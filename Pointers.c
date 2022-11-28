#include <stdio.h>

int main (void)
{
    int n = 60;
    int *p = &n;

    printf("                     n = %i\n", n);
    printf("          address of n = %p\n", &n);
    printf("   p points to address = %p\n", p);
    printf("value that p points to = %i\n", *p);

    int c = *p;

    printf("            value of c = %i\n", c);
    printf("          address of c = %p\n", &c);

    char *x = "HI!";
    char *y = &x[0];

    printf("                            x = %s\n", x);
    printf("                 address of x = %p\n", x);
    printf("                            y = %s\n", y);
    printf("                 address of y = %p\n", y);
    printf("%p\n", x);
    printf("%p\n", &x[0]);
    printf("%p\n", &x[1]);
    printf("%p\n", &x[2]);
    printf("%p\n", &x[3]);

 
    
}
