# RubixCube
Working Rubix Cube In C++

## How This Was Accomplished
A rubix cube consists of 6 vectors (each side of the cube), containing 3 additional vectors (rows of cube) each
filled with enum colors. The transformation functions are:
- cube.twistTop();
- cube.twistMiddle();
- cube.twistBottom();
- cube.twistCenter();
- cube.twistRightFront();
- cube.twistLeftFront();

## What The Functions do
- Twist Top twists the top side of the cube 90 degrees counter clockwise.
- Twist middle twists the 2nd (1st index) row of the array 90 degrees counter clockwise.
- Twist bottom twists the bottom side of the cube 90 degrees counter clockwise.
- Twist Center twists the 2nd column ([i][1] indexing) 90 degrees towards the top of the cube (upwards).
- Twist Left Top twists the 1st column 90 degrees towards the top of the cube (upwards).
- Twist Right Top twists the 3st column 90 degrees towards the top of the cube (upwards).

****

## Temporary Code
Within the code currently the cube preforms the above operations randomly to a set amount of moves in order to test if the cube is solved.
I have ambitious aspirations with this project, and hope to further develop it to be a self solving cube. 

