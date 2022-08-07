To get .i file (preprocessing only don't compile, assemble or link)
gcc -E file.c -o file.i

To get .s file (compile only but don't assemble or link)
gcc -S file.c -o file.s

To get .o file (compile & assemble but don't link)
gcc -c file.c -o file.o

To get .exe file
gcc file.c -o file.exe