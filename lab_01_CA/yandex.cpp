#include <iostream>
#include <string>
#include <vector>

#include <unordered_map>

int main() 
{
	int n = 0;

    std::cin >> n;

    std::vector<int> costs(n, 0);

    for (size_t i = 0; i < (size_t) n; ++i)
    {
        std::cin >> costs[i];
    }

    int X;

    std::cin >> X;

    int b1, b2, b3, b4;

    std::cin >> b1 >> b2 >> b3 >> b4;

    int k;

    std::cin >> k;

    std::vector<int>wanted(k, 0);

    for (size_t i = 0; i < (size_t) k; ++i)
        std::cin >> wanted[i];


    std::unordered_map<int, int> in_X;

    in_X[b1] = 0;
    in_X[b2] = 0;
    in_X[b3] = 0;
    in_X[b4] = 0;

    size_t calc = 0;
    for (size_t i = 0; i < k - calc; ++i)
    {    
        if (wanted[i] == b1)
        {   
            calc++;
            in_X[b1]++;
            wanted.erase(wanted.begin() + i);
            --i;
        }
        else if (wanted[i] == b2)
        {       
            calc++;
            in_X[b2]++;
            wanted.erase(wanted.begin() + i);
            --i;
        }
        else if (wanted[i] == b3)
        {   
            calc++;
            in_X[b3]++;
            wanted.erase(wanted.begin() + i);
            --i;
        }
        else if (wanted[i] == b4)
        {   
            calc++;
            in_X[b4]++;
            wanted.erase(wanted.begin() + i);
            --i;
        }
    }

    size_t sum = 0;    
    size_t calcX = 9999;
    
    
    size_t sumCombo = 0;
    size_t extra = 0;

    for (auto pair : in_X)
    {
        if (calcX > (size_t) pair.second)
            calcX = pair.second;
    }

    sumCombo = calcX * X;

    for (auto &pair : in_X)
    {
        pair.second -= calcX;
        
        extra += costs[pair.first - 1] * pair.second;
    }

    size_t sumCombs = 0;
    size_t extras = 0;
    for (size_t i = 1; i < 1000; ++i)
    {
        sumCombs = X * (i + calcX);
        extras = 0;
        for (auto &pair : in_X)
        {
            if (pair.second > 0)
            {   
                pair.second--;
                extras += costs[pair.first - 1] * pair.second; 
            }
        }

        if (sumCombs + extras < extra + sumCombo)
        {
            sumCombo = sumCombs;
            extra = extras;
        }
        else
            break;
    }

    sum += sumCombo;
    sum += extra;
    
    for (size_t i = 0; i < wanted.size(); ++i)
    {
        sum += costs[wanted[i] - 1];
    }

    std::cout << sum << std::endl;

	return 0;
}
