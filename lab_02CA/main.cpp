#include "input.h"

#include "interpolate3d.h"

int main(int argc, char *argv[])
{
    if (argc < 1)
        return -1;

    matrix3d data;
    readDataFile(argv[1], data);

    double x, y, z;
    int nx, ny, nz;


    std::cout << data[1][2][3] << std::endl;

    std::cout << "Введите x, y ,z" << std::endl;
    std::cout << std::endl;
    std::cin >> x >> y >> z;

    std::cout << "Введите nx, ny, nz" << std::endl;
    std::cin >> nx >> ny >> nz;
    std::cout << std::endl;

    Point3d point = Point3d(x, y, z);
    double result = newton_4d(data, point, nx, ny, nz);

    std::cout << "Ньютон:" << std::endl;
    std::cout << "Ответ: ";
    std::cout << result << std::endl;

    std::cout << "Сплайн:" << std::endl;
    std::cout << "Ответ: ";
    result = spline_4d(data, point);
    std::cout << result << std::endl;

    return 0;
}
