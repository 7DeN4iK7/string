#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(s21_strncat_1) {
  char s21_str[6] = "abc";
  char str[6] = "abc";
  char cat[3] = "def";
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
  char copy[7] = "copy";
  int n = 100;
  char *s21_res = s21_memcpy(str1, str2, n);
  char *res = memcpy(str1, str2, n);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(s21_memcpy_2) {
  char str1[6] = {0};
  char str2[6] = {0};
  char copy[7] = "copy";
  int n = 3;
  char *s21_res = s21_memcpy(str1, str2, n);
  char *res = memcpy(str1, str2, n);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(s21_memcpy_3) {
  char str1[6] = {0};
  char str2[6] = {0};
  char copy[7] = "copy";
  int n = -1;
  char *s21_res = s21_memcpy(str1, str2, n);
  char *res = memcpy(str1, str2, n);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

// char s21_str[6] = "abc";
// char str[6] = "abc";
// char cat[3] = "def";
// int n = 5;
// char *s21_res = s21_strncat(s21_str, cat, n);
// char *res = strncat(str, cat, n);
// ck_assert_str_eq(s21_res, res);

START_TEST(s21_strtok) {
  char s21[6] = "ababab";
  char orig[6] = "ababab";
  char del_s21 = "a";
  char del_orig = "a";
  char *s21_res = s21_strtok(s21, del_s21);
  char *res = strtok(orig, del_orig);
  ck_assert_str_eq(s21_res, res);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc1_1);
  // tcase_add_test(tc1_1, s21_strncat_1);
  tcase_add_test(tc1_1, s21_strncat_2);
  tcase_add_test(tc1_1, s21_memchr_1);
  tcase_add_test(tc1_1, s21_memchr_2);
  tcase_add_test(tc1_1, s21_memchr_3);
  tcase_add_test(tc1_1, s21_memcmp_1);
  tcase_add_test(tc1_1, s21_memcmp_2);
  tcase_add_test(tc1_1, s21_memcmp_3);
  tcase_add_test(tc1_1, s21_memcmp_4);
  tcase_add_test(tc1_1, s21_memcpy_1);
  // tcase_add_test(tc1_1, s21_memcpy_2);
  // tcase_add_test(tc1_1, s21_memcpy_3);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}