//#include <string.h>
#include <stdio.h>
#include "s21_string.h"

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

int main() {

    char string[] = "Hope you are doing fine";
    char *delimiter = " ";
    char *token;

    printf("%s\n", string);

    token = s21_strtok(string, delimiter);
    while(token != S21_NULL) {
        printf("%s\n", token);
        token = s21_strtok(S21_NULL, delimiter);
    }

    printf("%s\n", string);

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
    printf("AAA\t");
    if(str == S21_NULL)
        str = old;
    if(str != S21_NULL)
    {
        find = str;
        str += s21_strcspn(str, delim);
    } else {
        printf("END");
    }
    if(*str != '\0')
    {
        *str = '\0';
        old = str + 1;
    } else
    {
        old = S21_NULL;
    }
    return find;

    // if(str == S21_NULL)
    //     str = old;

    // printf("%s\t", str);
    // str += s21_strcspn(str, delim);
    // printf("%s\t", str);

    // if (*str == '\0')
    // {
    //     old = str;
    //     return (S21_NULL);
    // }

    // /* Find the end of the token.  */
    // find = str;
    // str = s21_strpbrk(find, delim);
    // printf("%s\t", str);
    // if (str == NULL)
    //     /* This token finishes the string.  */
    //     old = s21_strchr(find, '\0');
    // else
    // {
    //     /* Terminate the token and make OLDS point past it.  */
    //     *str = '\0';
    //     old = str + 1;
    // }

    return find;
}