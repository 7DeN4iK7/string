CC="gcc"

all:
	gcc -Wall -pedantic -std=c11 s21_string.c -lm
	echo "RESULT:"
	./a.out

s21_string.a:
	gcc s21_string.c -c
	ar rcs s21_string.a s21_string.o

run_test:
	rm -rf test
	@make test

test: s21_string.a
	$(CC) test.c s21_string.c -lm -lcheck -lsubunit -o test
	./test

gcov_report: s21_string.a
	#mkdir logs
	@$(CC) -fprofile-arcs -ftest-coverage s21_string.a test.c s21_string.c -o logs/gcov_report -lm -lcheck -lsubunit
	# ./logs/gcov_report
	# @echo "Building gcov report..."
	# gcovr --html-details -o logs/report.html
	# @echo "Building report..."
	# @open logs/report.html