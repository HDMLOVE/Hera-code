all:
	gcc -c -fpic Math.c -o Math.o
	gcc -shared -o libMath.so Math.o
	gcc main.c -ldl
.PHONY:clean
clean:
	rm -rf *.o *.so a.out
