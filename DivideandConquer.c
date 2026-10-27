#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

uint32_t split_and_convert(const char *s, size_t start, size_t len)
{
    uint32_t temp = 0;
    for (size_t i = 0; i < len; i++)
        temp = temp * 10 + (uint32_t)(s[start + i] - '0');

    return temp;
}

int CalculateByFormula(const char *a, const char *b, size_t m, size_t n)
{   
    // b high/low Lengths
    size_t len_b = strlen(b);
    size_t b_low = strlen(b) - n; // 8(b_low)13
    size_t b_high = len_b - b_low;
    
    uint32_t x = split_and_convert(a, 0, m-n); // 39
    uint32_t y = split_and_convert(a, m-n, n); // 26
    uint32_t w = split_and_convert(b, 0, b_low); // 8
    uint32_t z = split_and_convert(b, b_low, b_high); // 13

    return (x * w * pow(10, 2*n)) + (x * z + w * y) * pow(10, n) + y * z;
}

int main(void)
{
    char *a = "3926";
    char *b = "813";
    
    size_t m = strlen(a);
    size_t n = m/2;
    
    printf("%d\n\n", CalculateByFormula(a, b, m, n));
    return 0;
}