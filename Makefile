CC = gcc

TARGET = sibl
SRC = main.c check.c runfunc.c algpars.c

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean
