all:
	gcc -c hw0501.c
	gcc -c rotate.c
	gcc hw0501.o rotate.o -lm -o hw0501
	gcc -c hw0502.c
	gcc -c mymemcmp.c
	gcc hw0502.o mymemcmp.o -o hw0502
	gcc hw0503.c -o hw0503
	gcc -c hw0505.c
	gcc -c lib0505.c
	gcc -shared -fPIC -o lib0505.so lib0505.c
	gcc -o hw0505 -L. -l lib0505 hw0505.c
	gcc -c hw0504.c
	gcc -c division.c
	gcc hw0504.o division.o -o hw0504
