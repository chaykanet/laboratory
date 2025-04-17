
#include "input.h"

void readDataFile(const string& filename, matrix3d& data) {
    const int SIZE = 5; // Фиксированный размер данных 5x5x5
    ifstream file(filename);
    string line;
    int z = -1;

    // Инициализация вектора 5x5x5
    data.resize(SIZE);
    for (auto& z_layer : data) {
        z_layer.resize(SIZE);
        for (auto& y_layer : z_layer) {
            y_layer.resize(SIZE, 0.0);
        }
    }

    while (getline(file, line)) {
        if (line.empty()) continue;

        // Поиск секции с z
        size_t pos = line.find("z=");
        if (pos != string::npos) {
            z = stoi(line.substr(pos + 2));

            if (z < 0 || z >= SIZE) {
                cerr << "Invalid z value: " << z << endl;
                exit(1);
            }

            // Пропуск строки с заголовками x
            getline(file, line);

            // Чтение данных для текущего z
            for (int y = 0; y < SIZE; ++y) {
                // Пропуск пустых строк
                do {
                    getline(file, line);
                } while (line.empty());

                stringstream ss(line);
                int current_y;
                ss >> current_y;

                if (current_y != y) {
                    cerr << "Unexpected y value: " << current_y << endl;
                    exit(1);
                }

                for (int x = 0; x < SIZE; ++x) {
                    if (!(ss >> data[z][y][x])) {
                        cerr << "Error reading data at z=" << z
                             << ", y=" << y << ", x=" << x << endl;
                        exit(1);
                    }
                }
            }
        }
    }
}
