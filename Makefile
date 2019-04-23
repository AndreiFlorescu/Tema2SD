build: main.c ./Interface/interface.c ./Utilities/defTypes.c
	touch tree.out
	gcc -Wall main.c ./Interface/interface.c ./Utilities/defTypes.c -o tema2

clean:
	rm tema2
	rm tree.out