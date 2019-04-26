build: main.c ./Interface/interface.c ./Utilities/defTypes.c ./Tasks/tasks.c
	gcc -Wall main.c ./Interface/interface.c ./Utilities/defTypes.c ./Tasks/tasks.c -o tema2

clean: tema2
	rm tema2