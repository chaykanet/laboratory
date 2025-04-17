#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

using matrix3d = vector<vector<vector<double>>>;
void readDataFile(const string& filename, matrix3d& data);

#endif // INPUT_H
