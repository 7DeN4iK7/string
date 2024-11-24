//#include <s21_string.h>
#include <string.h>
#include <stdio.h>

void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);

int main() {
   unsigned char src[15]="1234567899";
   unsigned char dst[15]="1234567891";

   // Сравниваем первые 10 байт массивов
   // и результат выводим на экран
   int res = memcmp (src, dst, 10);
   printf("%d", res);

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

    return rez;
}

