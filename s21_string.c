#include <string.h>
#include <stdio.h>
#include "s21_string.h"
#include <stdarg.h>

void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
//char *strerror(int errnum);
size_t s21_strlen(const char* str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

char *itos(char *res, long num);
int add_digit(char *res, long num, int offset, int base);
char *ftos(char *res, double num, int accuracy);

int s21_sscanf(const char *str, const char *format, ...);
int s21_sprintf(char *str, const char *format, ...);

int read_specificator(char *str, const char *format, int len, char specificator, va_list args);
double max(double a, double b);
double min(double a, double b);

double max(double a, double b) {
    return a > b ? a : b;
}

double min(double a, double b) {
    return a < b ? a : b;
}

int s21_sscanf(const char *str, const char *format, ...) {
    va_list args;
    // int n = 3;
    // va_start(args, n);
    // for(int i = 0; i < n; i++) {
    //     printf("%d", va_arg(args, int));
    // }

    // va_end(args);
}



const char *specifications = "cdieEfgGosuxXpn";
typedef struct {
    int flag_minus;
    int flag_plus;
    int flag_space;
    int flag_hash;
    int flag_zero;
    int lenght;
    int accuracy;
    int reading_acc;
    int reading_lenght;
} specification_read;

int d_specificator(char *str, specification_read spec_read, int num) {
    char *ptr = str;
    char num_str[1024] = {0};
    itos(num_str, num);
    int num_len = s21_strlen(num_str);
    spec_read.accuracy = max(0, spec_read.accuracy - num_len);
    if(num < 0)
        *(ptr++) = '-';
    else if(spec_read.flag_plus)
        *(ptr++) = '+';
    else if(spec_read.flag_space)
        *(ptr++) = ' ';
    if(spec_read.accuracy > 0)
    {
        int add = spec_read.accuracy;
        s21_memset(ptr, '0', add);
        ptr += add;
    }
    strncpy(ptr, num_str, num_len);
    return ptr + num_len - str;
}

int f_specificator(char *str, specification_read spec_read, double num) {
    if(spec_read.accuracy == 0)
        spec_read.accuracy = 6;
    char *ptr = str;
    char num_str[1024] = {0};
    ftos(num_str, num, spec_read.accuracy);
    int num_len = s21_strlen(num_str);
    if(num < 0)
        *(ptr++) = '-';
    else if(spec_read.flag_plus)
        *(ptr++) = '+';
    else if(spec_read.flag_space)
        *(ptr++) = ' ';
    strncpy(ptr, num_str, num_len);
    return ptr + num_len - str;
}

int s_specificator(char *str, specification_read spec_read, char *str2) {
    int rez = s21_strlen(str2);
    if(spec_read.reading_acc) {
        rez = spec_read.accuracy;
    }
    s21_strncat(str, str2, rez);
    return rez;
}

int u_specificator(char *str, specification_read spec_read, unsigned int num) {
    char *ptr = str;
    char num_str[1024] = {0};
    itos(num_str, num);
    int num_len = s21_strlen(num_str);
    spec_read.accuracy = max(0, spec_read.accuracy - num_len);
    if(num < 0)
        *(ptr++) = '-';
    else if(spec_read.flag_plus)
        *(ptr++) = '+';
    else if(spec_read.flag_space)
        *(ptr++) = ' ';
    if(spec_read.accuracy > 0)
    {
        int add = spec_read.accuracy;
        s21_memset(ptr, '0', add);
        ptr += add;
    }
    strncpy(ptr, num_str, num_len);
    return ptr + num_len - str;
}

const char *flags = "-+ #0";

int read_specificator(char *str, const char *format, int len, char specificator, va_list args) {
    specification_read spec_read = {0};
    for(int i = 0; i < len; i++) {
        char c = format[i];
        if(c == '-')
            spec_read.flag_minus = 1;
        else if(c == '+')
            spec_read.flag_plus = 1;
        else if(c == ' ')
            spec_read.flag_space = 1;
        else if(c == '#')
            spec_read.flag_hash = 1;
        else if(c == '0')
            spec_read.flag_zero = 1;
        else if(c == '.')
            spec_read.reading_acc = 1;
        else if(c >= '0' && c <= '9') {
            if(spec_read.reading_acc) {
                spec_read.accuracy *= 10;
                spec_read.accuracy += c - '0';
            } else {
                spec_read.lenght *= 10;
                spec_read.lenght += c - '0';
            }
        }
    }
    char spec_str[1024] = {0};
    int spec_len = 0;
    switch(specificator)
    {
        case 'c':
            *spec_str = va_arg(args, int);
            spec_len += 1;
            break;
        case 'd':
            spec_len += d_specificator(spec_str, spec_read, va_arg(args, int));
            break;
        case 'f':
            spec_len += f_specificator(spec_str, spec_read, va_arg(args, double));
            break;
        case 's':
            spec_len += s_specificator(spec_str, spec_read, va_arg(args, char *));
            break;
        case 'u':
            spec_len += u_specificator(spec_str, spec_read, va_arg(args, unsigned int));
            break;
    }
    spec_read.lenght = max(0, spec_read.lenght - spec_len);
    char empty = spec_read.flag_zero? '0' : ' ';
    int add = spec_len + spec_read.lenght;
    if(spec_read.flag_minus) {
        s21_strncat(str, spec_str, spec_len);
        str += spec_len;
        for(int i = 0; i < spec_read.lenght; i++)
            *(str++) = empty;
    } else {
        for(int i = 0; i < spec_read.lenght; i++)
            *(str++) = empty;
        s21_strncat(str, spec_str, spec_len);
    }

    return add;
}

void reverse_str(char *str) {
    int i = 0, j = s21_strlen(str) - 1, temp; 
    while (i < j) { 
        temp = str[i]; 
        str[i] = str[j]; 
        str[j] = temp; 
        i++; 
        j--; 
    } 
}

char *ftos(char *res, double num, int accuracy) {
    int ipart = (int)num; 
 
    // Extract floating part 
    double fpart = num - (double)ipart; 
 
    // convert integer part to string 
    itos(res, num);
    int i = s21_strlen(res);
    res += i;
 
    // check for display option after point 
    if (accuracy != 0) {
        *(res++) = '.'; // add dot 
 
        double pow = 1;

        for(int i = 0; i < accuracy; i++) {
            pow *= 10;
        }

        fpart = fpart * pow; 
        if(fpart == 0) {
            for(int i = 0; i < accuracy; i++)
                *(res++) = '0';
        } else
            itos(res, (int)fpart);
    } 

    return res;
}

char *itos(char *str, long num) {
    int i = 0; 
    if(num < 0) {
        // *(str++) = '-';
        num *= -1;
    }
    while (num) { 
        str[i++] = (num % 10) + '0'; 
        num = num / 10; 
    }

    reverse_str(str); 
    str[i] = '\0'; 

    return str;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    char *start = str;

    va_start(args, format);
    int rez = 0;
    char *find = s21_strchr(format, '%');
    while (find != S21_NULL)
    {
        s21_strncpy(str, format, find - format);
        str += find - format;
        format = find + 1;
        find = s21_strpbrk(format, specifications);
        str += read_specificator(str, format, find - format, *find, args);
        format = find + 1;
        find = s21_strchr(format, '%');
    }
    
    s21_strncpy(str, format, s21_strlen(format));
    return str - start;
}

int main() {
    char res[1024] = {0};
    char real_res[1024] = {0};
    //0 with .(2) with d not works
    const char *format = "format:%6.0f"; 
    //int rez = s21_sprintf(res, format, 33, 12);
    int real_rez = sprintf(real_res, format, 33.f, 12);

    //printf("%d:%s\n", rez, res);
    printf("%d:%s\n", real_rez, real_res);

    return 0;
}

void *s21_memchr(const void *str, int c, size_t n) {
    const unsigned char *ptr = str;
    int find = 0;
    for(size_t i = 0; i < n && !find; i++) {
        int b = *(ptr++);
        if(b == c) {
            find = 1;
            ptr--;
        }
    }
    if(!find)
        ptr = S21_NULL;
    return (void*)ptr;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
    int rez = 0;
    for(int i = 0; i < n && rez == 0; i++) {
        rez = *(unsigned char*)(str1 + i) - *(unsigned char*)(str2 + i);
    }

    return rez;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
    for(int i = 0; i < n; i++) {
        *(unsigned char*)(dest + i) = *(unsigned char*)(src + i);
    }
    return dest;
}

void *s21_memset(void *str, int c, size_t n) {
    for(int i = 0; i < n; i++) {
        *(unsigned char*)(str + i) = c;
    }
    return str;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
    while(*dest != '\0') dest++;
    int i = 0;
    for(; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char *s21_strchr(const char *str, int c) {
    char *res = S21_NULL;
    while(*str != '\0' && res == S21_NULL) {
        if(c == *str)
            res = (char*)str;
        str++;
    }
    return res;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
    int rez = 0;
    for(int i = 0; i < n && rez == 0 && *str1 != '\0' && *str2 != '\0'; i++) {
        rez = *(str1++) - *(str2++);
    }

    return rez;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
    for(int i = 0; i < n && *src != '\0'; i++) {
        *(dest++) = *(src++);
    }
    return dest;
}

size_t s21_strcspn(const char *str1, const char *str2) {
    char *find = s21_strpbrk(str1, str2);
    size_t max = s21_strlen(str1);
    if(find != S21_NULL)
        max = find - str1;

    return max;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *rez = S21_NULL;
    size_t len = s21_strlen(str2);
    while(*str1 != '\0' && rez == S21_NULL) {
        for(int i = 0; i < len; i++) {
            if(*(str2 + i) == *str1)
                rez = (char *)str1;
        }
        str1++;
    }
    return rez;
}

size_t s21_strlen(const char* str) {
    char *ptr = (char*)str;
    while(*ptr != '\0') ptr++;
    return ptr - str;
}

char *s21_strrchr(const char *str, int c) {
    char *find = S21_NULL;
    while(*str != '\0') {
        if(c == *str)
            find = (char *)str;
        str++;
    }
    return find;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char *res = S21_NULL;
    char *find = s21_strchr(haystack, *needle);
    size_t len = s21_strlen(needle);
    while(find != S21_NULL && res == S21_NULL) {
        if(s21_strncmp(find, needle, len) == 0)
            res = find;
        find = s21_strchr(find + 1, *needle);
    }
    return res;
}

char *s21_strtok(char *str, const char *delim) {
    static char *old;
    char *find = S21_NULL;
    if(str == S21_NULL)
        str = old;
    if(str != S21_NULL)
    {
        find = str;
        str += s21_strcspn(str, delim);
        if(*str != '\0')
        {
            *str = '\0';
            old = str + 1;
        } else
        {
            old = S21_NULL;
        }
    }
    return find;
}