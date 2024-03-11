all: main.c q-sort-array.c quiz1.c
	gcc -o array main.c q-sort-array.c
	gcc -o quiz1 quiz1.c
qSortArray:	main.c q-sort-array.c
	gcc -o main main.c q-sort-array.c
qSortList: quiz1.c
	gcc -o main quiz1.c