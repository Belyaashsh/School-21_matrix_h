CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
SANITIZE=-fsanitize=address -g
TST_LIBS =
ifeq ($(shell uname), Linux)
	TST_LIBS += -lpthread -lrt -lsubunit
endif
LIB_NAME = s21_matrix

SRCS=$(wildcard s21_*.c)

OBJS=$(SRCS:.c=.o)

all: clean test

clean:
	rm -rf *.o test *.a *.gcno *.gcda *.gcov *.html *.css Main SANITIZE

clang-format:
	clang-format -i *.c *.h tests/*.c tests/*.h

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIB_NAME).a: $(OBJS)
	ar rc $(LIB_NAME).a $^
	ranlib $(LIB_NAME).a
	rm -rf *.o

# check - либа для работы тестов, $(LIB_NAME) - наша либа
test: clean $(LIB_NAME).a
	$(CC) $(FLAGS) check.c tests/*.c $(LIB_NAME).a $(TST_LIBS) -o test

sanitize: clean $(LIB_NAME).a
	$(CC) $(FLAGS) $(SANITIZE) check.c tests/*.c $(LIB_NAME).a $(TST_LIBS) -o SANITIZE

main: $(LIB_NAME).a
	$(CC) $(FLAGS) main.c -L. $(LIB_NAME).a $(TST_LIBS) -o Main

add_coverage_flag:
	$(eval FLAGS += --coverage)

gcov_report: add_coverage_flag test 
# 	mi-g6 || mi-j6
	./test
	rm -rf check*.gcda check*.gcno
	gcov -b -l -p -c s21_*.gcno
	gcovr -o gcov_report.html --html --html-details

hand_test:
	gcc s21_matrix.c main.c -o test



