import tkinter as tk
from tkinter import messagebox

import ctypes

# Подключение функций из библиотеки.
lib = ctypes.CDLL("./libapp.dll")

_fill_prime = lib.fill_prime

_fill_prime.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)

_fill_prime.restype = ctypes.c_int

_calc_even = lib.calc_even

_calc_even.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)

_calc_even.restype = ctypes.c_int

_add_num_after_even = lib.add_num_after_even

_add_num_after_even.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.c_int)

_add_num_after_even.restype = ctypes.c_int

# Заполнение массива простыми числами
def fill_prime(arr: list[int], size: int):
    arr = (ctypes.c_int * size)(*arr)
    
    _fill_prime(arr, size)
    
    return list(arr)

# Подсчет четных чисел в массиве
def calc_even(arr: list[int], size: int):
    
    arr = (ctypes.c_int * size)(*arr)
    
    return _calc_even(arr, size)

# Формирование массива с числами num после четных
def add_num_after_even(new_arr: list[int], arr: list[int], size: int, num: int)-> tuple[list[int], int]:
    
    arr = (ctypes.c_int * size)(*arr)
    
    new_size = size + calc_even(arr, size)
    
    new_arr = (ctypes.c_int * new_size)()
    
    new_len = ctypes.c_int()
    
    _add_num_after_even(new_arr, new_len, arr, size, num)
    
    return (list(new_arr), new_len.value)

# Чтение массива
def input_array(size, elements):
    arr = []
    try:
        size = int(size)
        if size <= 0:
            raise ValueError
    except ValueError:
        messagebox.showerror("Ошибка", "Некорректный ввод размера массива")
        return None

    for element in elements:
        try:
            el = int(element)
            arr.append(el)
        except ValueError:
            messagebox.showerror("Ошибка", "Некорректный ввод элемента массива")
            return None

    return arr

# Логика обработки приложения
def process():
    
    size = size_entry.get()

    arr = []
    
    arr_primes = fill_prime(arr, int(size))
    prime_output.set(f"Массив простых чисел: {arr_primes}")

    # Запрашиваем второй массив и число
    sec_elements = sec_elements_entry.get().split()
    sec_arr = input_array(len(sec_elements), sec_elements)
    if sec_arr is None:
        return

    num = num_entry.get()
    try:
        num = int(num)
    except ValueError:
        messagebox.showerror("Ошибка", "Некорректный ввод числа")
        return
    new_arr = []
    tuple_new_arr = add_num_after_even(new_arr, sec_arr, len(sec_arr), num)
    result_output.set(f"Массив с добавленными числами: {tuple_new_arr[0]} размера {tuple_new_arr[1]}")

    
# Графический интерфейс
root = tk.Tk()
root.title("Обработка массивов")

# Поля для ввода
size_label = tk.Label(root, text="Размер для первого массива:")
size_label.pack()
size_entry = tk.Entry(root)
size_entry.pack()

sec_elements_label = tk.Label(root, text="Элементы второго массива (через пробел):")
sec_elements_label.pack()
sec_elements_entry = tk.Entry(root)
sec_elements_entry.pack()

num_label = tk.Label(root, text="Введите число для добавления:")
num_label.pack()
num_entry = tk.Entry(root)
num_entry.pack()

# Кнопка для обработки массивов
process_button = tk.Button(root, text="Обработать массивы", command=process)
process_button.pack()

# Поля для вывода результатов
prime_output = tk.StringVar()
result_output = tk.StringVar()
tk.Label(root, textvariable=prime_output).pack()
tk.Label(root, textvariable=result_output).pack()

# Запуск цикла приложения
root.mainloop()