CC=gcc

all:exam_q3

exam_q3:exam_q3.c
	$(CC) -o exam_q3 exam_q3.c


clean:
	rm -rf *.o exam_q3


