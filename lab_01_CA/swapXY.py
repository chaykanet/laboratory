# Открываем файл для чтения
with open("delta_xy.txt", "r") as file:
    lines = file.readlines()  # Читаем все строки из файла

# Меняем местами x и y в каждой строке
swapped_lines = []
for line in lines:
    x, y = line.strip().split()  # Разделяем строку на x и y
    swapped_lines.append(f"{y} {x}\n")  # Меняем местами и добавляем в список

# Записываем измененные данные обратно в файл
with open("delta_reverse.txt", "w") as file:
    file.writelines(swapped_lines)  # Записываем все строки в файл

print("Координаты успешно изменены!")
