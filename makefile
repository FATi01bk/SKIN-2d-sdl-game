prog:fonctionss.o mains.o 
	gcc fonctionss.o mains.o -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer -o prog  
	
mains.o:mains.c 
	gcc -c mains.c 
	
fonctionss.o:fonctionss.c 
	gcc -c fonctionss.c -g

