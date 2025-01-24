prog :main.o entitesecondaire.o
	gcc -o prog main.o entitesecondaire.o -lSDL -lSDL_image  -lSDL_mixer 
main.o :main.c
	gcc -o main.o -c  main.c  -lSDL -lSDL_image  -lSDL_mixer 
entitesecondaire.o :entitesecondaire.c
	gcc -o entitesecondaire.o -c entitesecondaire.c -lSDL -lSDL_image  -lSDL_mixer 



