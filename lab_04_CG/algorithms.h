#ifndef ALGORITHMS_H
#define ALGORITHMS_H

enum class alg { Alg_CANON, Alg_PARAM, Alg_BRES, Alg_MID, Alg_STD };

enum class figure { Circle, Ellipse };

class Algorithms
{
public:
    Algorithms();

    void MidpointСircle(double xCenter, double yCenter, double radius);

    void CanonicalСircle(double xCenter, double yCenter, double radius);

    void BresenhamСircle(double xCenter, double yCenter, double radius);
    
    void ParametricСircle(double xCenter, double yCenter, double radius);

        
    void MidpointEllipse(double xCenter, double yCenter, double a, double b);

    void CanonicalEllipse(double xCenter, double yCenter, double a, double b);
    
    void BresenhamEllipse(double xCenter, double yCenter, double a, double b);
        
    void ParametricEllipse(double xCenter, double yCenter, double a, double b);

    void StdEllipse(double xCenter, double yCenter, double a, double b);
    
};

#endif // ALGORITHMS_H
