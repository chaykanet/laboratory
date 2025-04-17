#include "interp.h"

#include <QTableWidget>
#include <QHeaderView>

#define EPS 1e-7

std::vector<std::vector<double>>table_data = {};

Interp::Interp(InterpError_t err, double val)
{
    error = err;
    value = val;
}

typedef std::vector<Point> pairsCoor_t;

static void sortPointsbyX(pairsCoor_t& pairs)
{
    std::sort(pairs.begin(), pairs.end(),
              [](const Point& a, const Point& b)
              {return a.x < b.x;});
}

// добавить проверку на l r
static InterpError_t formVectorNodes(pairsCoor_t& nodes, pairsCoor_t& pairs, double xValue, int polyDegree, int mode)
{
    if (((int) pairs.size() < polyDegree + 1 && mode == 0) || ((int) pairs.size() < (polyDegree + 1) / 3 && mode == 1))
        return InterpError_t::ERR_RANGE_POLYNOM;

    auto ItNearest = std::min_element(pairs.begin(), pairs.end(),
                                    [xValue](const Point& a, const Point& b)
                                    {return std::abs(a.x - xValue) < std::abs(b.x - xValue);});

    int n = 0;

    for (auto rIt = ItNearest, lIt = ItNearest - 1; n < polyDegree + 1;)
    {
        if (rIt != pairs.end())
        {
            ++n;
            nodes.push_back(*rIt);
            if (mode == 1 && n < polyDegree + 1)
            {
                n += 2;
                nodes.push_back(*rIt);
                nodes.push_back(*rIt);
            }
            ++rIt;
        }

        if (n < polyDegree + 1 && lIt != pairs.begin() - 1)
        {
            ++n;
            nodes.push_back(*lIt);
            if (mode == 1 && n < polyDegree + 1)
            {
                n += 2;
                nodes.push_back(*lIt);
                nodes.push_back(*lIt);
            }
            --lIt;
        }
    }

    return InterpError_t::ERR_OK;
}

static InterpError_t calcCoefficients(std::vector<double>& coefficients, pairsCoor_t& nodes, int polyDegree)
{
    std::deque<double> yValues = {};
    std::vector<std::pair<int, Point>> calcNodes = {};

    for (auto node : nodes)
    {
        calcNodes.push_back({0, node});
        yValues.push_back(node.y);
    }

    for (size_t j = 0; j < (size_t) polyDegree + 1; ++j)
    {
        coefficients.push_back(yValues[0]);
        for (size_t i = 0; i < polyDegree - j; i++)
        {
            double yDiff = yValues[0] - yValues[1];
            double xDiff = calcNodes[i].second.x - calcNodes[i + j + 1].second.x;

            if (std::abs(xDiff) <= EPS && calcNodes[i].first == 0)
            {
                yValues.push_back(calcNodes[i].second.dy);
                ++calcNodes[i].first;
            }
            else if (std::abs(xDiff) <= EPS && calcNodes[i].first == 1)
            {
                yValues.push_back(calcNodes[i].second.ddy / 2);
                ++calcNodes[i].first;
            }
            else if (std::abs(xDiff) > EPS)
            {
                yValues.push_back(yDiff / xDiff);
            }
            else
                return InterpError_t::ERR_MISS_DERIVATIVE;

            yValues.pop_front();
        }
        yValues.pop_front();
    }
    return InterpError_t::ERR_OK;
}

static double appoximate(const std::vector<double>& coefficient, const pairsCoor_t& nodes, double xValue)
{
    double funcValue = 0;

    for (size_t i = 0; i < coefficient.size(); ++i)
    {
        double multy = 1;
        for (size_t j = 0; j < i; ++j)
            multy *= (xValue - nodes[j].x);

        funcValue += coefficient[i] * multy;
    }
    return funcValue;
}

Interp interpolate(std::vector<Point> sources, double xValue, int polyDegree, int mode)
{
    if (sources.size() < 2)
        return Interp(InterpError_t::ERR_SOURCE, 0);

    double funcValue = 1;

    pairsCoor_t nodes = {};
    std::vector<double> coefficient = {};

    InterpError_t rc = InterpError_t::ERR_OK;

    if (mode == 1)
        polyDegree = polyDegree * 3 - 1;

    if (rc == InterpError_t::ERR_OK)
        rc = formVectorNodes(nodes, sources, xValue, polyDegree, mode);

    if (rc == InterpError_t::ERR_OK)
        rc = calcCoefficients(coefficient, nodes, polyDegree);

    if (rc == InterpError_t::ERR_OK)
        funcValue = appoximate(coefficient, nodes, xValue);

    return Interp(rc, funcValue);
}
