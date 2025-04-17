#include <fstream>
#include <iostream>

#include "input.h"

InterpError_t readData(const std::string& filename, std::vector<Point>& data, int mode)
{
    std::ifstream file(filename);

    if (!file.is_open())
        return InterpError_t::ERR_SOURCE;

    double x, y, dy = 0, ddy = 0;

    if (mode == 2)
        while (file >> x >> y)
            data.push_back({x, y, dy, ddy});
    else if (mode == 3)
        while (file >> x >> y >> dy)
            data.push_back({x, y, dy, ddy});
    else if (mode == 4)
        while (file >> x >> y >> dy >> ddy)
            data.push_back({x, y, dy, ddy});

    file.close();

    return InterpError_t::ERR_OK;
}
