mainmake: main.c huffman.c rle.c
	gcc -o tester main.c huffman.c rle.c -I.
