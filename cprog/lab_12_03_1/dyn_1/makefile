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
SRCS := $(wildcard $(SRC)*.c)
OBJECTS := $(patsubst $(SRC)%.c, $(OUT)%.o, $(SRCS))
UNITS := $(wildcard $(UNIT)*.c)
OBJECTS_UNIT := $(patsubst $(UNIT)%.c, $(OUT)%.o, $(UNITS))

OBJECTS_NOT_LIB := $(filter-out out/func_array.o, $(OBJECTS)) 

OBJECTS_NOT_MAIN := $(filter-out out/main.o, $(OBJECTS))
OBJECTS_NOT_MAIN_LIB := $(filter-out out/func_array.o, $(OBJECTS_NOT_MAIN)) 
# Заголовочные файлы
HEADERS := $(wildcard $(INC)*.h)

LIB := -lcheck -lm

libapp.so: CFLAGS += -fPIC
libapp.so: $(OUT)func_array.o
	$(CC) -shared -o $@ $^

app_dyn_1: $(OBJECTS_NOT_LIB)
app_dyn_1: libapp.so
	$(CC) -o app.exe $(OBJECTS_NOT_LIB) libapp.so -Wl,-rpath=.

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
	@echo "Running debug..."
	$(MAKE) app_dyn_1
	@cd ./func_tests/scripts && ./func_tests.sh -v 2>/dev/null && cd ./../../ || true
	@echo "Running valgrind..."
	@cd ./func_tests/scripts && bash ./func_tests.sh -v --valgrind 2>/dev/null && cd ./../../ || true
	$(MAKE) clean

func:
	@mkdir -p out || true
	$(MAKE) app_dyn_1
	echo "Running debug..."
	@cd ./func_tests/scripts && ./func_tests.sh 2>/dev/null && cd ./../../ || true
	@echo "Running valgrind..."
	@cd ./func_tests/scripts && bash ./func_tests.sh --valgrind 2>/dev/null && cd ./../../ || true
	$(MAKE) clean


unit_tests.exe: CFLAGS += -fPIC
unit_tests.exe: libapp.so $(OBJECTS_UNIT) $(OBJECTS_NOT_MAIN_LIB)
	@mkdir -p out || true
	$(CC) -o $@ $(OBJECTS_UNIT) $(OBJECTS_NOT_MAIN_LIB) libapp.so -Wl,-rpath=. $(LIB)

unit: unit_tests.exe

my_unit: LIB := -lcheck -lm -lpthread -lsubunit -lrt
my_unit: unit_tests.exe
	./unit_tests.exe

.PHONY: clean func func_v unit release debug asan msan ubsan gcov unit_tests.exe analysis graphs clean_analysis clean_data_analysis
clean:
	rm -rf ./*.exe ./*.o ./*.txt ./*gcov ./*gcda ./*.info ./*gcno ./out

