#Папки
SRC := src/
INC := inc/
OUT := out/
UNIT := unit_tests/
FUNC := func_tests/scripts/
# Компилятор
CC := gcc
# С флаги
CFLAGS := -std=gnu99 -Iinc -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion
# Объектные файлы
# OBJECTS := func_array_io.o my_stdlib.o
SRCS := $(wildcard $(SRC)*.c)
OBJECTS := $(patsubst $(SRC)%.c, $(OUT)%.o, $(SRCS))
UNITS := $(wildcard $(UNIT)*.c)
OBJECTS_UNIT := $(patsubst $(UNIT)%.c, $(OUT)%.o, $(UNITS))

OBJECTS_NOT_MAIN := $(filter-out out/main.o, $(OBJECTS)) 
# Заголовочные файлы
HEADERS := $(wildcard $(INC)*.h)

LIB := -lcheck -lm

# Исполняемый файл.
app.exe: $(OBJECTS)
	$(CC) -o $@ $^ -lm

# Получение объектного файла
$(OUT)%.o: $(SRC)%.c
	@mkdir -p out || true
	$(CC) $(CFLAGS) -c -MD $< -o $@

# Получение объектного файла unit
$(OUT)%.o: $(UNIT)%.c
	@mkdir -p out || true
	$(CC) $(CFLAGS) -c -MD $< -o $@

include $(wildcard $(OUT)*.d)

release: CFLAGS += -DNDDEBUG -g0
release: app.exe

debug: CFLAGS += -g3 
debug: app.exe

asan: $(CC) := clang
asan: $(CFLAGS) += -fsanitize=address -fno-omit-frame-pointer -g3
asan: app.exe

msan: $(CC) := clang
msan: $(CFLAGS) += -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -g3
msan: app.exe

ubsan: $(CC) := clang
ubsan: $(CFLAGS) += -fsanitize=undefined -fno-omit-frame-pointer -g3
ubsan: app.exe

coverage: $(CFLAGS) += --coverage -o0 -fprofile-arcs -ftest-coverage
coverage: app.exe
coverage:
	@cd ./func_tests/scripts && ./func_tests.sh
	gcov $(SRCS)

lcov: coverage
	lcov --capture --directory . --output-file ./out/app.info
	genhtml ./out/app.info --output-directory out

.SILENT: func func_v

func_v:
	@mkdir -p out || true
	echo "Running debug..."
	$(MAKE) debug
	@cd ./func_tests/scripts && ./func_tests.sh -v 2>/dev/null && cd ./../../ || true
	$(MAKE) clean
	echo "Running asan..."
	$(MAKE) asan
	@cd ./func_tests/scripts && bash ./func_tests.sh -v 2>/dev/null && cd ./../../ || true
	$(MAKE) clean
	echo "Running msan..."
	$(MAKE) msan
	@cd ./func_tests/scripts && bash ./func_tests.sh -v 2>/dev/null && cd ./../../ || true
	$(MAKE) clean
	echo "Running ubsan..."
	$(MAKE) ubsan
	@cd ./func_tests/scripts && bash ./func_tests.sh -v 2>/dev/null && cd ./../../ || true
	$(MAKE) clean
	echo "Running valgrind..."
	$(MAKE) debug
	@cd ./func_tests/scripts && bash ./func_tests.sh -v --valgrind 2>/dev/null && cd ./../../ || true
	$(MAKE) clean

func:
	@mkdir -p out || true
	echo "Running debug..."
	$(MAKE) debug
	@cd ./func_tests/scripts && ./func_tests.sh 2>/dev/null && cd ./../../ || true
	$(MAKE) clean
	echo "Running asan..."
	$(MAKE) asan
	@cd ./func_tests/scripts && bash ./func_tests.sh 2>/dev/null && cd ./../../ || true
	$(MAKE) clean
	echo "Running msan..."
	$(MAKE) msan
	@cd ./func_tests/scripts && bash ./func_tests.sh 2>/dev/null && cd ./../../ || true
	$(MAKE) clean
	echo "Running ubsan..."
	$(MAKE) ubsan
	@cd ./func_tests/scripts && bash ./func_tests.sh 2>/dev/null && cd ./../../ || true
	$(MAKE) clean
	echo "Running valgrind..."
	$(MAKE) debug
	@cd ./func_tests/scripts && bash ./func_tests.sh --valgrind && cd ./../../ || true

unit_tests.exe: $(OBJECTS_UNIT) $(OBJECTS_NOT_MAIN)
	@mkdir out || true
	$(CC) -o $@ $^ $(LIB)

unit: unit_tests.exe

my_unit: LIB := -lcheck -lm -lpthread -lsubunit -lrt
my_unit: unit_tests.exe
	./unit_tests.exe

my_unit_valgrind: LIB := -lcheck -lm -lpthread -lsubunit -lrt
my_unit_valgrind: unit_tests.exe
	valgrind --leak-check=yes -q ./unit_tests.exe

.PHONY: clean func func_v unit release debug asan msan ubsan gcov unit_tests.exe
clean:
	rm -rf ./*.exe ./*.o ./*.txt ./*gcov ./*gcda ./*.info ./*gcno ./out

