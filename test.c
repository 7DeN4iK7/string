#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <math.h>
#include "s21_string.h"
#include <string.h>

START_TEST(s21_strncat_1) {
  char s21_str[10] = "abc";
  char str[10] = "abc";
  char cat[4] = "def";
  int n = 5;
  char *s21_res = s21_strncat(s21_str, cat, n);
  char *res = strncat(str, cat, n);
  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(s21_strncat_2) {
  char s21_str[6] = "";
  char str[6] = "";
  char cat[3] = "def";
  int n = 3;
  char *s21_res = s21_strncat(s21_str, cat, n);
  char *res = strncat(str, cat, n);
  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(s21_memchr_1) {
  char str1[] = "";
  int n = 5;
  char *s21_res = s21_memchr(str1, ' ', n);
  ck_assert_ptr_null(s21_res);
}
END_TEST

START_TEST(s21_memchr_2) {
  char str1[] = "abc";
  int n = 3;
  char *s21_res = s21_memchr(str1, 'b', n);
  char *res = memchr(str1, 'b', n);
  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(s21_memchr_3) {
  char str1[] = "abc";
  int n = 1;
  char *s21_res = s21_memchr(str1, 'c', n);
  char *res = memchr(str1, 'c', n);
  ck_assert_ptr_null(s21_res);
}
END_TEST

START_TEST(s21_memcmp_1) {
  char str1[] = "abc";
  char str2[] = "abc";
  int n = 3;
  int s21_res = s21_memcmp(str1, str2, n);
  int res = memcmp(str1, str2, n);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(s21_memcmp_2) {
  char str1[] = "abc";
  char str2[] = "abc";
  int n = -1;
  int s21_res = s21_memcmp(str1, str2, n);
  int res = memcmp(str1, str2, n);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(s21_memcmp_3) {
  char str1[] = "abc";
  char str2[] = "abc";
  int n = 100;
  int s21_res = s21_memcmp(str1, str2, n);
  int res = memcmp(str1, str2, n);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(s21_memcmp_4) {
  char str1[] = "abc";
  char str2[] = "acb";
  int n = 100;
  int s21_res = s21_memcmp(str1, str2, n);
  int res = memcmp(str1, str2, n);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(s21_memcpy_1) {
  char str1[6] = {0};
  char str2[6] = {0};
  char copy[4] = "copy";
  int n = 4;
  char *s21_res = s21_memcpy(str1, copy, n);
  char *res = memcpy(str2, copy, n);
  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(s21_memcpy_2) {
  char str1[6] = {0};
  char str2[6] = {0};
  char copy[4] = "copy";
  int n = 2;
  char *s21_res = s21_memcpy(str1, copy, n);
  char *res = memcpy(str2, copy, n);
  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(s21_memcpy_3) {
  char str1[6] = {0};
  char str2[6] = {0};
  char copy[4] = "copy";
  int n = 0;
  char *s21_res = s21_memcpy(str1, copy, n);
  char *res = memcpy(str2, copy, n);
  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(s21_sprintf_d1) {
  char s21_str[1024] = {0};
  char str[1024] = {0};
  const char *format = "test: %d";
  int s21_res = s21_sprintf(s21_str, format, 0);
  int res = sprintf(str, format, 0);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_str, str);
}

START_TEST(s21_sprintf_d2) {
  char s21_str[1024] = {0};
  char str[1024] = {0};
  const char *format = "test: %d %hd %hhd %ld %lld";
  int s21_res = s21_sprintf(s21_str, format, -1, -1, -1, -1, -1);
  int res = sprintf(str, format, -1, -1, -1, -1, -1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_str, str);
}

START_TEST(s21_sprintf_d3) {
  char s21_str[1024] = {0};
  char str[1024] = {0};
  const char *format = "test: %10d %10hd %10hhd %10ld %10lld";
  int s21_res = s21_sprintf(s21_str, format, -1, -1, -1, -1, -1);
  int res = sprintf(str, format, -1, -1, -1, -1, -1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_str, str);
}

START_TEST(s21_sprintf_d4) {
  char s21_str[1024] = {0};
  char str[1024] = {0};
  const char *format = "test: %10.3d %10.3hd %10.3hhd %10.3ld %10.3lld";
  int s21_res = s21_sprintf(s21_str, format, -1, -1, -1, -1, -1);
  int res = sprintf(str, format, -1, -1, -1, -1, -1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_str, str);
}

START_TEST(s21_sprintf_d5) {
  char s21_str[1024] = {0};
  char str[1024] = {0};
  const char *format = "test: %0-+ #10.3d %0-+ #10.3hd %0-+ #10.3hhd %0-+ #10.3ld %0-+ #10.3lld";
  int s21_res = s21_sprintf(s21_str, format, -1, -1, -1, -1, -1);
  int res = sprintf(str, format, -1, -1, -1, -1, -1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_str, str);
}

START_TEST(s21_sprintf_f1) {
  char s21_str[1024] = {0};
  char str[1024] = {0};
  const char *format = "test: %f %f %f %f";
  int s21_res = s21_sprintf(s21_str, format, 0, 0, 0, 0L);
  int res = sprintf(str, format, 0, 0, 0, 0L);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_str, str);
}

START_TEST(s21_sprintf_f2) {
  char s21_str[1024] = {0};
  char str[1024] = {0};
  const char *format = "test: %f %f %f %f";
  int s21_res = s21_sprintf(s21_str, format, -100, 100, -0, 123.134L);
  int res = sprintf(str, format, -100, 100, -0, 123.134L);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_str, str);
}


START_TEST(s21_sprintf_f3) {
  char s21_str[1024] = {0};
  char str[1024] = {0};
  const char *format = "test: %0-+ #10.3f %0-+ #10.3f %0-+ #010.3f %0-+ #10.3f";
  int s21_res = s21_sprintf(s21_str, format, -100, 100, -0, 123.134L);
  int res = sprintf(str, format, -100, 100, -0, 123.134L);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_str, str);
}

START_TEST(s21_sprintf_u1) {
  char s21_str[1024] = {0};
  char str[1024] = {0};
  const char *format = "test: %u %hu %hu %lu %lu";
  int s21_res = s21_sprintf(s21_str, format, -1, -1, -1, -1, -1);
  int res = sprintf(str, format, -1, -1, -1, -1, -1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_str, str);
}

//------------------ALYONA------------------
START_TEST(s21_memset_1) {
  char str[6] = "piskaa";
  int c = 45;
  int n = 2;
  char *s21_res = s21_memset(str, c, n);
  char *res = memset(str, c, n);
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(s21_memset_2) {
  char str[6] = "piskaa";
  int c = 45;
  int n = 0;
  char *s21_res = s21_memset(str, c, n);
  char *res = memset(str, c, n);
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(s21_strchr_1) {
  const char str[6] = "piskaa";
  int c = 45;
  int n = 0;
  char *s21_res = s21_memset(str, c, n);
  char *res = memset(str, c, n);
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST



// START_TEST(s21_strncat_1) {
//   char str1[6] = "piskaa";
//   char str2[6] = "popkaa";
//   int n = 1;
//   char *s21_res = s21_strncat(str1, str2, n);
//   char *res = strncat(str1, str2, n);
//   ck_assert_ptr_eq(s21_res, res);
// }
// END_TEST

// START_TEST(s21_strncat_2) {
//   char str1[0] = "";
//   char str2[6] = "popkaa";
//   int n = 1;
//   char *s21_res = s21_strncat(str1, str2, n);
//   char *res = strncat(str1, str2, n);
//   ck_assert_ptr_eq(s21_res, res);
// }
// END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_strncat_1);
  tcase_add_test(tc1_1, s21_strncat_2);
  tcase_add_test(tc1_1, s21_memchr_1);
  tcase_add_test(tc1_1, s21_memchr_2);
  tcase_add_test(tc1_1, s21_memchr_3);
  tcase_add_test(tc1_1, s21_memcmp_1);
  tcase_add_test(tc1_1, s21_memcmp_2);
  tcase_add_test(tc1_1, s21_memcmp_3);
  tcase_add_test(tc1_1, s21_memcmp_4);
  tcase_add_test(tc1_1, s21_memcpy_1);
  tcase_add_test(tc1_1, s21_memcpy_2);
  tcase_add_test(tc1_1, s21_memcpy_3);
  tcase_add_test(tc1_1, s21_memset_1);
  tcase_add_test(tc1_1, s21_memset_2);
  //tcase_add_test(tc1_1, s21_strncat_1);
  //SPRINTF
  tcase_add_test(tc1_1, s21_sprintf_d1);
  tcase_add_test(tc1_1, s21_sprintf_d2);
  tcase_add_test(tc1_1, s21_sprintf_d3);
  tcase_add_test(tc1_1, s21_sprintf_d4);
  tcase_add_test(tc1_1, s21_sprintf_d5);
  tcase_add_test(tc1_1, s21_sprintf_f1);
  tcase_add_test(tc1_1, s21_sprintf_f2);
  tcase_add_test(tc1_1, s21_sprintf_f3);
  tcase_add_test(tc1_1, s21_sprintf_u1);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}