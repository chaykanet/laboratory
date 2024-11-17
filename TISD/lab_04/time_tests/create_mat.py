import sys
import random

def generate_random_matrix(rows, cols, zero_percent):
    matrix = []
    total_elements = rows * cols
    zero_elements = int(total_elements * (zero_percent / 100))
    non_zero_elements = total_elements - zero_elements
    
    elements = [random.randint(1, 9) for _ in range(non_zero_elements)]
    elements += [0] * zero_elements
    random.shuffle(elements)
    
    for i in range(rows):
        matrix.append(elements[i * cols: (i + 1) * cols])
    
    return matrix

try:
    rows = int(sys.argv[2])
    cols = int(sys.argv[3])
    zero_percent = int(sys.argv[4])
    with open(sys.argv[1], 'w') as f:
        f.write(f"{rows} {cols}\n")
        matrix = generate_random_matrix(rows, cols, zero_percent)
        for row in matrix:
            f.write(' '.join(map(str, row)) + '\n')
except IndexError or FileNotFoundError or ValueError:
    exit(2)
    
exit(0)