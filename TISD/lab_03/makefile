#Папки
SRC := src/
INC := inc/
OUT := out/
UNIT := unit_tests/
FUNC := func_tests/scripts/
# Компилятор
CC := gcc
# С флаги
CFLAGS := -std=c99 -Iinc -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -g
# Объектные файлы
# OBJECTS := func_array_io.o my_stdlib.o
SRCS := $(wildcard $(SRC)*.c)
OBJECTS := $(patsubst $(SRC)%.c, $(OUT)%.o, $(SRCS))
UNITS := $(wildcard $(UNIT)*.c)
OBJECTS_UNIT := $(patsubst $(UNIT)%.c, $(OUT)%.o, $(UNITS))

OBJECTS_NOT_MAIN := $(filter-out out/main.o, $(OBJECTS)) 
# Заголовочные файлы
LIBRARIES := $(wildcard $(INC)*.h)

# Ключи func
VERBOSE := $(filter --verbose,$(MAKEFLAGS))

# Исполняемый файл.
app.exe: $(OBJECTS)
	$(CC) -o $@ $^ -lm

# Получение объектного файла
$(OUT)%.o: $(SRC)%.c
	mkdir -p out || true
	$(CC) $(CFLAGS) -c -MD $< -o $@

# Получение объектного файла unit
$(OUT)%.o: $(UNIT)%.c
	$(CC) $(CFLAGS) -c -MD $< -o $@

# ifeq ($(mode), debug)
# 	CFLAGS += -g3
# endif

# ifeq ($(mode), release)
# 	CFLAGS += -DNDDEBUG -g0
# endif

include $(wildcard $(OUT)*.d)

release: $(CFLAGS) += -DNDDEBUG -g0
release: app.exe

debug: $(CFLAGS) += -g3 
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

gcov: $(CFLAGS) += --coverage -O0
gcov: app.exe
	@cd func_tests/scripts && bash ./func_tests.sh 2>/dev/null && cd ./../../ || true
	@lcov -t "app" -o app.info -c -d .
	@genhtml -o ./out/report_coverage app.info
	@mv ./*.info ./out/ && rm ./*.exe

.SILENT: func


func:
	echo "Running debug..."
	$(MAKE) debug
	cd ./func_tests/scripts && bash ./func_tests.sh $(VERBOSE) 2>/dev/null && cd ./../../ || true
	$(MAKE) clean
	echo "Running asan..."
	$(MAKE) asan
	cd ./func_tests/scripts && bash ./func_tests.sh $(VERBOSE) 2>/dev/null && cd ./../../ || true
	$(MAKE) clean
	echo "Running msan..."
	$(MAKE) msan
	cd ./func_tests/scripts && bash ./func_tests.sh $(VERBOSE) 2>/dev/null && cd ./../../ || true
	$(MAKE) clean
	echo "Running ubsan..."
	$(MAKE) ubsan
	cd ./func_tests/scripts && bash ./func_tests.sh $(VERBOSE) 2>/dev/null && cd ./../../ || true
	$(MAKE) clean
	echo "Running valgrind..."
	$(MAKE) debug
	cd ./func_tests/scripts && bash ./func_tests.sh $(VERBOSE) --valgrind 2>/dev/null && cd ./../../ || true
	#$(MAKE) clean
	# $(MAKE) gcov
	# @cd ./func_tests/scripts && bash ./func_tests.sh $(VERBOSE) 2>/dev/null && cd ./../../ || true
	# gcov app-*.exe


analysis:
	@rm -f ./time_tests/temp/* ./time_tests/data/* || true
	@cd ./time_tests && bash run_time.sh || true

	 
.PHONY: clean func unit release debug asan msan ubsan gcov unit_tests.exe sorts.png
clean:
	rm -f ./*.exe ./*.o ./*gcov ./*gcda ./*gcno ./out/*.o ./out/*.d
