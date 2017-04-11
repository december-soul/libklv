all:
	gcc main.c libklv.c -g -o klv


test:
	./test_data/getdata.sh
	./klv Day_Flight.mpg
