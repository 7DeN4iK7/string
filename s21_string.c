//#include <s21_string.h>
#include <string.h>
#include <stdio.h>

void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);

int main() {

    char str1[15] = "catpopa";
    char str2[30] = "catpopa";

    int rez = s21_strncmp(str1, str2, 20);

    printf("%d - %d", strncmp(str1, str2, 20), s21_strncmp(str1, str2, 20));

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
        ptr = NULL;
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
    char *res = NULL;
    while(*str != '\0' && res == NULL) {
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
