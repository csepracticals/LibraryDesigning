TARGET: exe
libdll.a: dll.o
	ar rs libdll.a dll.o
dll.o: dll.c
	gcc -c -I . dll.c -o dll.o
exe: application.o libdll.a
	gcc application.o -o exe -L . -ldll
application.o: application.c
	gcc -c -I . application.c -o application.o
clean:
	rm *.o
	rm libdll.a
	rm exe

