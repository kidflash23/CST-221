//We see that o is an integer.
#include<stdio.h>
int main(int argc, char *argv[]){
    unsigned int o;
    //This generates the print statement
    printf("decimal  hexadecimal\n");
    for (o = 0; o <= 512; o+=32)
        printf("%06d     0x%007X\n", o, o);
    return 0;
}