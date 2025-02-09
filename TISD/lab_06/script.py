import sys
import random
import string
from datetime import datetime, timedelta

def generate_random_name(length=5):
    """Генерирует случайное имя заданной длины."""
    letters = string.ascii_letters
    return ''.join(random.choice(letters) for _ in range(length))

def generate_random_date(start_date, end_date):
    """Генерирует уникальную случайную дату между двумя заданными датами."""
    return start_date + timedelta(days=random.randint(0, (end_date - start_date).days))

def generate_unique_dates(num_dates, start_date, end_date):
    """Генерирует уникальные случайные даты между двумя заданными датами."""
    unique_dates = set()
    while len(unique_dates) < num_dates:
        random_date = generate_random_date(start_date, end_date).strftime('%d %m %Y')
        unique_dates.add(random_date)
    return list(unique_dates)

def generate_nodes(num_nodes):
    """Генерирует список узлов с случайными именами и уникальными датами обновления."""
    nodes = []
    start_date = datetime(2020, 1, 1)
    end_date = datetime(2024, 1, 1)

    unique_dates = generate_unique_dates(num_nodes, start_date, end_date)

    for i in range(num_nodes):
        name = generate_random_name()
        update_date = unique_dates[i]
        nodes.append((name, update_date))

    return nodes

def write_nodes_to_file(nodes, filename):
    """Записывает узлы в текстовый файл."""
    with open(filename, 'w') as file:
        for name, date in nodes:
            file.write(f'{name}\n{date}\n')

# Пример использования
if __name__ == "__main__":
    num_nodes = 1000  # количество узлов для генерации
    generated_nodes = generate_nodes(num_nodes)
    
    with open(sys.argv[1], "w") as f: 
        for name, date in generated_nodes:
            f.write(f"{name}\n{date}\n")