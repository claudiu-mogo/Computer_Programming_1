FLAG = -g -Wall -lm -std=c99
 
build: task1 task2 task3 task4

task1: task1.c
	gcc -o task1 task1.c $(FLAG)

task2: task2.c
	gcc -o task2 task2.c $(FLAG)

task3: task3.c
	gcc -o task3 task3.c $(FLAG)

task4: task4.c
	gcc -o task4 task4.c $(FLAG)

browser: browser.c
	gcc -o browser browser.c $(FLAG) -lncurses -lmenu

# Regulile de clean 
.PHONY : clean
clean :
	rm -f task1 task2 task3 task4
	rm -f *.out
