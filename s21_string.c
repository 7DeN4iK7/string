//#include <s21_string.h>
#include <string.h>
#include <stdio.h>

void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);

int main() {
   // Исходный массив данных
   unsigned char src[10]="1234567890";

   // Вывод массива src на консоль
   printf ("src old: %s\n",src);

   // Копируем 3 байт
   memmove (&src[4], &src[3], 3);

   // Вывод массива src на консоль
   printf ("src new: %s\n", src);

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
