build: main.c ./Interface/interface.c ./Utilities/defTypes.c ./Tasks/tasks.c
	touch tree.out
	touch hierarchy.out
	touch queries.out
	gcc -Wall main.c ./Interface/interface.c ./Utilities/defTypes.c ./Tasks/tasks.c -o tema2

clean:
	rm tema2
	rm tree.out
	rm hierarchy.out
	rm queries.out