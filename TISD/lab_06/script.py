def process_file(input_file, output_file):
    try:
        with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
            i = 1
            c = 1
            for line in infile:
                # Убираем пробелы в начале и конце строки
                stripped_line = line.strip()
                
                # Проверяем, начинается ли строка с маленькой буквы
                if stripped_line and stripped_line[0].islower():
                    # Добавляем символ "_" к строке
                    modified_line = stripped_line + "_" * i
                    i += 1
                    if i == 100:
                        c += 1
                        i = c
                else:
                    modified_line = stripped_line
                
                # Записываем строку в выходной файл
                outfile.write(modified_line + '\n')

        print(f"Обработка завершена. Результаты записаны в '{output_file}'.")

    except Exception as e:
        print(f"Произошла ошибка: {e}")

# Укажите здесь имена входного и выходного файлов
input_filename = 'data.txt'  # файл, который нужно обработать
output_filename = 'data_1.txt'  # файл для записи результата

# Запускаем процесс
process_file(input_filename, output_filename)