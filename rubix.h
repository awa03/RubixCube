#ifndef RUBIX_H
#define RUBIX_H

#include <vector>
#include <string>

namespace Rubix {

enum Color {red, blue, green, orange, yellow, white};

class Rubix {
public:
    Rubix();

    // Declare public member functions here
    bool isSolved();
    void printCube();
    void twistTop();
    void twistMiddle();
    void twistBottom();
    void twistCenter();
    void twistRightFront();
    void twistLeftFront();

    bool operator==(Rubix& RHS);

private:
    // Member variables for storing cube data
    std::vector<std::vector<Color> > rubixTop;
    std::vector<std::vector<Color> > rubixBottom;
    std::vector<std::vector<Color> > rubixRight;
    std::vector<std::vector<Color> > rubixLeft;
    std::vector<std::vector<Color> > rubixFront;
    std::vector<std::vector<Color> > rubixBack;

    // Declare private member functions here
    void initializeCube();
    void printSide(const std::vector<std::vector < Color > >& side);
    std::string getColorName(Color color);
};

bool operator!=(Rubix& LHS, Rubix& RHS);

} // End of namespace Rubix

#endif
