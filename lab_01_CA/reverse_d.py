lines = []
with open("data.txt", "r") as file:
    lines = file.readlines()

new_lines = []
for line in lines:
    # Разделяем строку на значения
    x, y, dy, ddy = line.split()
    
    # Преобразуем строки в числа
    x = float(x)
    y = float(y)
    dy = float(dy)
    ddy = float(ddy)
    
    # Вычисляем новые значения
    dx_dy = 1 / dy
    d2x_dy2 = -ddy / (dy ** 3)
    
    # Формируем новую строку
    new_lines.append(f'{y} {x} {dx_dy:.4f} {d2x_dy2:.4f}\n')

# Записываем результат в новый файл
with open('data_reverse_d.txt', 'w') as file:
    file.writelines(new_lines)
