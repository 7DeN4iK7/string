

all:
	gcc -Wall -pedantic -std=c11 s21_string.c -lm
	echo "RESULT:"
	./a.out