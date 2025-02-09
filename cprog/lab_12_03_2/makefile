#Папки
SRC := src/
INC := inc/
OUT := out/
UNIT := unit_tests/
FUNC := func_tests/scripts/

# Компилятор
CC := gcc
# С флаги
CFLAGS := -std=c99 -Iinc -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion
# Объектные файлы
SRCS := $(wildcard $(SRC)*.c)
OBJECTS := $(patsubst $(SRC)%.c, $(OUT)%.o, $(SRCS))
UNITS := $(wildcard $(UNIT)*.c)
OBJECTS_UNIT := $(patsubst $(UNIT)%.c, $(OUT)%.o, $(UNITS))

OBJECTS_NOT_LIB := $(filter-out out/func_array.o, $(OBJECTS)) 

OBJECTS_NOT_MAIN := $(filter-out out/main.o, $(OBJECTS)) 
# Заголовочные файлы
HEADERS := $(wildcard $(INC)*.h)

LIB := -lcheck -lm

libapp.dll: CFLAGS += -fPIC
libapp.dll: $(OBJECTS)
	$(CC) -shared -o $@ $^

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
	@mkdir out || true
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
	echo "Running with libapp.a..."
	$(MAKE) app_libapp.a
	@cd ./func_tests/scripts && bash ./func_tests.sh --valgrind && cd ./../../ || true
	echo "Running with libapp.so..."
	$(MAKE) app_libapp.so
	@cd ./func_tests/scripts && bash ./func_tests.sh --valgrind && cd ./../../ || true

unit_tests.exe: $(OBJECTS_UNIT) $(OBJECTS_NOT_MAIN)
	@mkdir out || true
	$(CC) -o $@ $^ $(LIB)

unit: unit_tests.exe

my_unit: LIB := -lcheck -lm -lpthread -lsubunit -lrt
my_unit: unit_tests.exe
	./unit_tests.exe
	
.PHONY: clean func func_v unit release debug asan msan ubsan gcov unit_tests.exe analysis graphs clean_analysis clean_data_analysis
clean:
	rm -rf ./*.exe ./*.o ./*.txt ./*gcov ./*gcda ./*.info ./*gcno ./out

