# Функция для чтения координат из файла
def read_coordinates(filename):
    coordinates = []
    with open(filename, "r") as file:
        for line in file:
            x, y = map(float, line.strip().split())  # Читаем x и y
            coordinates.append((x, y))
    return coordinates

# Чтение координат из двух файлов
coords1 = read_coordinates("data_reverse.txt")
coords2 = read_coordinates("gotxy.txt")

# Проверка, что количество строк в файлах совпадает
if len(coords1) != len(coords2):
    print("Ошибка: количество строк в файлах не совпадает!")
    exit(1)

# Вычисление разности ординат и запись в третий файл
with open("delta_xy.txt", "w") as output_file:
    for (x1, y1), (x2, y2) in zip(coords1, coords2):
        if x1 != x2:  # Проверка, что абсциссы совпадают
            print(f"Ошибка: абсциссы не совпадают: {x1} != {x2}")
            exit(1)
        diff_y = y2 - y1  # Разность ординат
        output_file.write(f"{x1} {diff_y}\n")  # Запись результата

print("Разность ординат записана в файл output.txt")
