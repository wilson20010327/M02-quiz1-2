all: main.c q-sort-array.c quiz1.c quiz1_linux_list.c
	gcc -o array main.c q-sort-array.c
	gcc -o quiz1 quiz1.c
	gcc -o quiz1_linux_list quiz1_linux_list.c
qSortArray:	main.c q-sort-array.c
	gcc -o array main.c q-sort-array.c
qSortList: quiz1.c
	gcc -o quiz1 quiz1.c
quiz1Linux: quiz1_linux_list.c
	gcc -o quiz1_linux_list quiz1_linux_list.c