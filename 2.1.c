#include<stdio.h>
#include<limits.h>
#include<float.h>

int main()
{
    printf("Display limits from <limits.h>:\n");
    
    printf("CHAR_BIT: %d bits in a char.\n", CHAR_BIT);
    
    // signed 
    printf("signed types\n");
    printf("CHAR_MIN: minimum value of char is %d\n", CHAR_MIN);
    printf("CHAR_MAX: maximum value of char is %d\n", CHAR_MAX);

    printf("SHRT_MIN: minimum value of short is %d\n", SHRT_MIN);
    printf("SHRT_MAX: maximum value of short is %d\n", SHRT_MAX);

    printf("INT_MIN: minimum value of integer is %d\n", INT_MIN);
    printf("INT_MAX: maximum value of integer is %d\n", INT_MAX);

    printf("LONG_MIN: minimum value of long is %ld\n", LONG_MIN);
    printf("LONG_MAX: maximum value of long is %ld\n", LONG_MAX);

    // unsigned
    printf("unsigned types\n");
    printf("UCHAR_MIN: maximum value of unsigned char is %d\n", UCHAR_MAX);
    printf("USHRT_MAX: maximum value of unsigned short is %d\n", USHRT_MAX);
    printf("UINT_MAX: maximum value of unsigned integer is %u\n", UINT_MAX);
    printf("ULONG_MAX: maximum value of unsigned long is %lu\n", ULONG_MAX);

    printf("Compute limits:\n");
    // Could not come up with an anwser to this question!
    // The trick is to flip all bits to 1, shift 1 bit to the right for signed types 
    // (sign is kept inside the left most bit), and convert to each type (char, int, short, long)
    
    // signed
    printf("signed char min: %d\n", -(char)((unsigned char)~0 >> 1));
    printf("signed char max: %d\n", (char)((unsigned char)~0 >> 1));
    printf("signed short min: %d\n", -(short)((unsigned short)~0 >> 1));
    printf("signed short max: %d\n", (short)((unsigned short)~0 >> 1));
    printf("signed int min: %d\n", -(int)((unsigned int)~0 >> 1));
    printf("signed int max: %d\n", (int)((unsigned int)~0 >> 1));
    printf("signed long min: %ld\n", -(long)((unsigned long)~0 >> 1));
    printf("signed long max: %ld\n", (long)((unsigned long)~0 >> 1));

    // unsigned
    printf("unsigned char max: %d\n", ((unsigned char)~0));
    printf("unsigned short max: %d\n", ((unsigned short)~0));
    printf("unsigned int max: %u\n", ((unsigned int)~0));
    printf("unsigned long max: %lu\n", ((unsigned long)~0));

    return 0;
}




