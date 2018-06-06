CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o read_file_into_array main.c
stable:clean
	$(CC) $(CFLAGS) -o read_file_into_array main.c
clean:
	rm -vfr *~ read_file_into_array
