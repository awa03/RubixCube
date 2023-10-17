#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
namespace Rubix {

enum Color {red, blue, green, orange, yellow, white};

class Rubix{
public:

    Rubix() {
        // Initialize the cube with default values, e.g., all sides as red
        initializeCube();
    }

    bool isSolved(){
        // Get first color
        int firstColorTop = rubixTop[0][0];
        int firstColorBottom = rubixBottom[0][0];
        int firstColorRight = rubixRight[0][0];
        int firstColorLeft = rubixLeft[0][0];
        int firstColorFront = rubixFront[0][0];
        int firstColorBack = rubixBack[0][0];
    
        // Compare all to first color to see if solved
        for (int i = 0; i < 3; ++i) {
            for (int x = 0; x < 3; ++x) {
                if (rubixTop[i][x] != firstColorTop ||
                    rubixBottom[i][x] != firstColorBottom ||
                    rubixRight[i][x] != firstColorRight ||
                    rubixLeft[i][x] != firstColorLeft ||
                    rubixFront[i][x] != firstColorFront ||
                    rubixBack[i][x] != firstColorBack) {
                    return false; // if not equal to same color
                }
            }
        }
        return true; // if all are equal

    } // EO isSolved

    void printCube() {
            cout << "Top Side:" << endl;
            printSide(rubixTop);
            cout << "Bottom Side:" << endl;
            printSide(rubixBottom);
            cout << "Right Side:" << endl;
            printSide(rubixRight);
            cout << "Left Side:" << endl;
            printSide(rubixLeft);
            cout << "Front Side:" << endl;
            printSide(rubixFront);
            cout << "Back Side:" << endl;
            printSide(rubixBack);
    }

    void twistTop(){
        /*
        Example Transformation
            b b b       g g g
            g g g  -->  g g g
            g g g       g g g
        */

        // Sides Transform
        vector<Color> temp = rubixBack[0]; 
        vector<Color> tempTwo = rubixLeft[0]; 
        rubixBack[0] = rubixRight[0];               // BackTop = RightTop
        rubixLeft[0] = temp;                        // LeftTop = BackTop
        rubixRight[0] = rubixFront[0];              // RightTop = FrontTop
        rubixFront[0] = tempTwo;                    // FrontTop = LeftTop

        vector<vector<Color> > newTop(3, vector<Color>(3));

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                newTop[i][j] = rubixTop[2 - j][i];
            }
        }
        rubixTop = newTop;

        /*
        Example Top Transformation
            g g g        g b b
            y g b   -->  g g b
            g b b        g y g
        */
    }
    void twistMiddle(){
        // Sides Transform
        vector<Color> temp = rubixBack[1]; 
        vector<Color> tempTwo = rubixLeft[1]; 
        rubixBack[1] = rubixRight[1];               // BackTop = RightTop
        rubixLeft[1] = temp;                        // LeftTop = BackTop
        rubixRight[1] = rubixFront[1];              // RightTop = FrontTop
        rubixFront[1] = tempTwo;                    // FrontTop = LeftTop
    }
    void twistBottom(){

        // Sides Transform
        vector<Color> tempOne = rubixBack[2]; 
        vector<Color> tempTwo = rubixLeft[2]; 
        rubixBack[2] = rubixRight[2];               // BackTop = RightTop
        rubixLeft[2] = tempOne;                     // LeftTop = BackTop
        rubixRight[2] = rubixFront[2];              // RightTop = FrontTop
        rubixFront[2] = tempTwo;                    // FrontTop = LeftTop


        // Store the bottom row for rotation
        vector<Color> temp = rubixBottom[0];

        // Rotate the sides
        rubixBottom[0] = rubixBottom[2];
        rubixBottom[2] = rubixBottom[2];
        rubixBottom[2] = rubixBottom[0];

        // Rotate the colors in the bottom row
        rubixBottom[0][0] = temp[2];
        rubixBottom[0][2] = temp[0];

        /*
        Example Bottom Transformation
            g g g        g b b
            y g b   -->  g g b
            g b b        g y g
        */
    }
    void twistCenter(){
        // rubixFront[0, 1, 2][1] = rubixTop[0, 1, 2][1]
        vector<vector<Color> > tempTop = rubixTop;
        for(int i=0; i < 3; i++){
            // TopMid = FrontMid
            rubixTop[i][1] = rubixFront[i][1];
            // FrontMid = BottomMid
            rubixFront[i][1] = rubixBottom[i][1];
            // BottomMid = BackMid
            rubixBottom[i][1] = rubixBack[i][1];
            // BackMid = TopMid
            rubixBack[i][1] = tempTop[i][1];
        }
    }
    void twistRightFront(){
        // rubixFront[0, 1, 2][1] = rubixTop[0, 1, 2][1]
        vector<vector<Color> > tempTop = rubixTop;
        for(int i=0; i < 3; i++){
            // TopMid = FrontMid
            rubixTop[i][0] = rubixFront[i][0];
            // FrontMid = BottomMid
            rubixFront[i][0] = rubixBottom[i][0];
            // BottomMid = BackMid
            rubixBottom[i][0] = rubixBack[i][0];
            // BackMid = TopMid
            rubixBack[i][0] = tempTop[i][0];
        }
    }
    void twistLeftFront(){
        // rubixFront[0, 1, 2][1] = rubixTop[0, 1, 2][1]
        vector<vector<Color> > tempTop = rubixTop;
        for(int i=0; i < 3; i++){
            // TopMid = FrontMid
            rubixTop[i][2] = rubixFront[i][2];
            // FrontMid = BottomMid
            rubixFront[i][2] = rubixBottom[i][2];
            // BottomMid = BackMid
            rubixBottom[i][2] = rubixBack[i][2];
            // BackMid = TopMid
            rubixBack[i][2] = tempTop[i][2];
        }
    }


    bool operator==(Rubix& RHS){
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (rubixTop[i][j] != RHS.rubixTop[i][j] ||
                    rubixBottom[i][j] != RHS.rubixBottom[i][j] ||
                    rubixRight[i][j] != RHS.rubixRight[i][j] ||
                    rubixLeft[i][j] != RHS.rubixLeft[i][j] ||
                    rubixFront[i][j] != RHS.rubixFront[i][j] ||
                    rubixBack[i][j] != RHS.rubixBack[i][j]) {
                    return false; // if not equal to same color
                }
            }
        } return true;
    }
    






private: 


    // Vector for each side of cube
    vector<vector<Color> > rubixTop;
    vector<vector<Color> > rubixBottom;
    vector<vector<Color> > rubixRight;
    vector<vector<Color> > rubixLeft;
    vector<vector<Color> > rubixFront;
    vector<vector<Color> > rubixBack;



    // Helper Function
    void initializeCube() {
            rubixTop = vector<vector<Color> >(3, vector<Color>(3, red));
            rubixBottom = vector<vector<Color> >(3, vector<Color>(3, blue));
            rubixRight = vector<vector<Color> >(3, vector<Color>(3, green));
            rubixLeft = vector<vector<Color> >(3, vector<Color>(3, orange));
            rubixFront = vector<vector<Color> >(3, vector<Color>(3, yellow));
            rubixBack = vector<vector<Color> >(3, vector<Color>(3, white));
    }

    void printSide(const vector<vector<Color> >& side) {
            for (const auto& row : side) {
                for (const auto& cell : row) {
                    cout << getColorName(cell) << "\t";
                }
                cout << endl;
            }
            cout << endl;
    }



    string getColorName(Color color) {
            switch (color) {
                case red:
                    return "Red";
                case blue:
                    return "Blue";
                case green:
                    return "Green";
                case orange:
                    return "Orange";
                case yellow:
                    return "Yellow";
                case white:
                    return "White";
                default:
                    return "Unknown";
            }
    }
}; // EO RUBIX CLASS
    bool operator!=(Rubix& LHS, Rubix& RHS){
            if(LHS == RHS){return false;}
            else return true;
    }
}; // EO Namespace



int main(){
     Rubix::Rubix cubeOne;
    Rubix::Rubix cubeTwo;

    cubeOne.twistBottom(); // You can start with an initial twist if you want
    int moves = 0;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(1, 6); // Random numbers from 1 to 6

    while (cubeOne != cubeTwo && moves < 1000000) {
        int randomOperation = distribution(generator);

        switch (randomOperation) {
            case 1:
                cubeOne.twistTop();
                break;
            case 2:
                cubeOne.twistMiddle();
                break;
            case 3:
                cubeOne.twistBottom();
                break;
            case 4:
                cubeOne.twistCenter();
                break;
            case 5:
                cubeOne.twistRightFront();
                break;
            case 6:
                cubeOne.twistLeftFront();
                break;
        }

        moves++;
    }

    if (cubeOne == cubeTwo) {
        cout << "CubeOne is now equal to CubeTwo after " << moves << " moves." << endl;
    } else {
        cout << "CubeOne is not equal to CubeTwo after " << moves << " moves." << endl;
    }
    cubeOne.printCube();
}