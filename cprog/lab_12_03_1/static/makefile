#Папки
SRC := src/
INC := inc/
OUT := out/
UNIT := unit_tests/
FUNC := func_tests/scripts/

# Компилятор
CC := gcc
# С флаги
CFLAGS := -std=c99 -Iinc -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion -g
# Объектные файлы
# OBJECTS := func_array_io.o my_stdlib.o
SRCS := $(wildcard $(SRC)*.c)
OBJECTS := $(patsubst $(SRC)%.c, $(OUT)%.o, $(SRCS))
UNITS := $(wildcard $(UNIT)*.c)
OBJECTS_UNIT := $(patsubst $(UNIT)%.c, $(OUT)%.o, $(UNITS))

OBJECTS_NOT_LIB := $(filter-out out/func_array.o, $(OBJECTS)) 

OBJECTS_NOT_MAIN_LIB := $(filter-out out/main.o, $(OBJECTS_NOT_LIB)) 
# Заголовочные файлы
HEADERS := $(wildcard $(INC)*.h)

LIB := -lcheck -lm

libapp.a: $(OUT)func_array.o
	ar cr $@ $^

app_libapp.a: libapp.a $(OBJECTS_NOT_LIB)
	$(CC) $(CFLAGS) $(OBJECTS_NOT_LIB) $< -o app.exe

# Получение объектного файла
$(OUT)%.o: $(SRC)%.c
	@mkdir -p out || true
	$(CC) $(CFLAGS) -c -MD $< -o $@

# Получение объектного файла unit
$(OUT)%.o: $(UNIT)%.c
	@mkdir -p out || true
	$(CC) $(CFLAGS) -c -MD $< -o $@

include $(wildcard $(OUT)*.d)

.SILENT: func

func_v:
	@mkdir -p out || true
	echo "Running debug..."
	$(MAKE) app_libapp.a
	@cd ./func_tests/scripts && ./func_tests.sh -v 2>/dev/null && cd ./../../ || true
	echo "Running valgrind..."
	@cd ./func_tests/scripts && bash ./func_tests.sh -v --valgrind 2>/dev/null && cd ./../../ || true
	$(MAKE) clean

func:
	@mkdir -p out || true
	$(MAKE) app_libapp.a
	echo "Running debug..."
	@cd ./func_tests/scripts && ./func_tests.sh 2>/dev/null && cd ./../../ || true
	echo "Running valgrind..."
	@cd ./func_tests/scripts && bash ./func_tests.sh --valgrind 2>/dev/null && cd ./../../ || true
	$(MAKE) clean

unit_tests.exe: libapp.a $(OBJECTS_UNIT) $(OBJECTS_NOT_MAIN_LIB)
	@mkdir -p out || true
	$(CC) $(CFLAGS) $(OBJECTS_UNIT) $(OBJECTS_NOT_MAIN_LIB) libapp.a -o $@ $(LIB)

unit: unit_tests.exe

my_unit: LIB := -lcheck -lm -lpthread -lsubunit -lrt
my_unit: unit_tests.exe
	./unit_tests.exe

.PHONY: clean func func_v unit release debug asan msan ubsan gcov unit_tests.exe analysis graphs clean_analysis clean_data_analysis
clean:
	rm -rf ./*.exe ./*.o ./*.txt ./*gcov ./*gcda ./*.info ./*gcno ./out

