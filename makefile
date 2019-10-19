Lab_2 : Lab_2.o
	gcc Lab_2.o -o Lab_2
	rm Lab_2.o
Lab_2.o : Lab_2.c
	gcc  -g -c Lab_2.c
