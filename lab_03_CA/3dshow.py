import matplotlib.pyplot as plt
import numpy as np

from mpl_toolkits.mplot3d import Axes3D

# Создаем данные для сетки
x = np.linspace(-5, 5, 100)  # Диапазон по X
y = np.linspace(-5, 5, 100)  # Диапазон по Y
X, Y = np.meshgrid(x, y)     # Сетка координат

# Задаем функцию плоскости
def f(x, y):
    return 1 + 2*x + 2*y     # z = 1 + 2x + 2y

Z = f(X, Y)

# Создаем 3D-график
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

# Рисуем поверхность
surf = ax.plot_surface(
    X, Y, Z,
    cmap='viridis',         # Цветовая схема
    edgecolor='none',       # Без граней между квадратами
    alpha=0.8,             # Прозрачность
    rstride=2,             # Шаг сетки по X
    cstride=2              # Шаг сетки по Y
)

# Настройки графика
ax.set_xlabel('X Axis')
ax.set_ylabel('Y Axis')
ax.set_zlabel('Z Axis')
ax.set_title('Плоскость z = 1 + 2x + 2y')

# Добавляем цветовую шкалу
fig.colorbar(surf, shrink=0.5, aspect=5)

# Угол обзора
ax.view_init(elev=20, azim=35)

plt.show()
