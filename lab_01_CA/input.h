#ifndef INPUT_H
#define INPUT_H

#include <string>

#include "interp.h"

InterpError_t readData(const std::string& filename, std::vector<Point>& data, int mode);

#endif // INPUT_H
