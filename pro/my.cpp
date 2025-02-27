#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
#define PI 3.14159265358979323846

// Class for Algebraic Calculations
class AlgebraCalculator {
public:
    void basicOperations() {
        double a, b;
        char op;
        cout << "Enter expression (a + b, a - b, a * b, a / b): ";
        cin >> a >> op >> b;
        switch(op) {
            case '+': cout << "Result: " << a + b << endl; break;
            case '-': cout << "Result: " << a - b << endl; break;
            case '*': cout << "Result: " << a * b << endl; break;
            case '/': 
                if (b != 0) cout << "Result: " << a / b << endl; 
                else cout << "Error: Division by zero!" << endl; 
                break;
            default: cout << "Invalid operator!" << endl;
        }
    }

    void solveLinearEquation() {
        double a, b;
        cout << "Enter coefficients a and b (ax + b = 0): ";
        cin >> a >> b;
        if (a != 0) cout << "Solution: x = " << -b / a << endl;
        else cout << "No solution (a = 0)." << endl;
    }

    void solveQuadraticEquation() {
        double a, b, c, d, root1, root2;
        cout << "Enter coefficients a, b, c (ax^2 + bx + c = 0): ";
        cin >> a >> b >> c;
        d = b * b - 4 * a * c;
        if (d > 0) {
            root1 = (-b + sqrt(d)) / (2 * a);
            root2 = (-b - sqrt(d)) / (2 * a);
            cout << "Roots: x1 = " << root1 << ", x2 = " << root2 << endl;
        } else if (d == 0) {
            root1 = -b / (2 * a);
            cout << "Single root: x = " << root1 << endl;
        } else {
            cout << "Complex roots!" << endl;
        }
    }
};

// Class for Trigonometric Calculations
class TrigonometryCalculator {
public:
    void displayMenu() {
        cout << "Trigonometry Calculator:\n";
        cout << "1. Sine (sin)\n";
        cout << "2. Cosine (cos)\n";
        cout << "3. Tangent (tan)\n";
        cout << "4. Back to Main Menu\n";
    }

    void calculate() {
        int choice;
        double input, result;
        do {
            displayMenu();
            cin >> choice;
            if (choice >= 1 && choice <= 3) {
                cout << "Enter angle in degrees (0 to 360): ";
                cin >> input;
                if (input >= 0 && input <= 360) {
                    if (choice == 1) result = sin(input * (PI / 180.0));
                    else if (choice == 2) result = cos(input * (PI / 180.0));
                    else if (choice == 3) {
                        if (input == 90 || input == 270) {
                            cout << "Result: Undefined (tan at 90°, 270°)" << endl;
                            continue;
                        }
                        result = tan(input * (PI / 180.0));
                    }
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Invalid input! Angle must be between 0 and 360." << endl;
                }
            } else if (choice != 4) {
                cout << "Invalid choice! Try again.\n";
            }
        } while (choice != 4);
    }
};

// Class for Right Triangle Calculations
class RightTriangle {
public:
    struct Triangle {
        double base, perpendicular, hypotenuse;
    };

    void calculateHypotenuse(Triangle* t) {
        t->hypotenuse = sqrt((t->base * t->base) + (t->perpendicular * t->perpendicular));
    }

    bool isRightAngledTriangle(const Triangle* t) {
        return (t->hypotenuse * t->hypotenuse) == (t->base * t->base) + (t->perpendicular * t->perpendicular);
    }

    double findLargestSide(const Triangle* t) {
        return max(t->base, max(t->perpendicular, t->hypotenuse));
    }

    void initializeTriangle(Triangle* t) {
        cout << "Enter base: ";
        cin >> t->base;
        cout << "Enter perpendicular: ";
        cin >> t->perpendicular;
        calculateHypotenuse(t);
    }

    void displayTriangle(const Triangle* t) {
        cout << "Triangle Data:\n";
        cout << "Base: " << t->base << "\n";
        cout << "Perpendicular: " << t->perpendicular << "\n";
        cout << "Hypotenuse: " << t->hypotenuse << "\n";
    }

    void saveTriangleToFile(const Triangle* t, const string& filename) {
        ofstream outFile(filename.c_str());
        if (!outFile) {
            cout << "Error opening file for writing.\n";
            return;
        }
        outFile << t->base << " " << t->perpendicular << " " << t->hypotenuse << endl;
        outFile.close();
        cout << "Triangle data saved successfully...\n";
    }

    void loadTrianglesFromFile(const string& filename) {
        ifstream inFile(filename.c_str());
        if (!inFile) {
            cout << "Error opening file for reading.\n";
            return;
        }
        cout << "Triangles in file:\n";
        double base, perp, hypotenuse;
        while (inFile >> base >> perp >> hypotenuse) {
            cout << "Base: " << base << ", Perpendicular: " << perp << ", Hypotenuse: " << hypotenuse << endl;
        }
        inFile.close();
    }
};

// Matrix Operations
class Matrix {
    private:
        int mat[10][10];
        int rows, cols;
    public:
        Matrix(int r, int c) : rows(r), cols(c) {}
        void input() {
            cout << "Enter elements:\n";
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    cin >> mat[i][j];
        }
        void display() const {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++)
                    cout << mat[i][j] << " ";
                cout << endl;
            }
        }
        Matrix add(const Matrix &other) {
            Matrix result(rows, cols);
            if (rows != other.rows || cols != other.cols) {
                cout << "Error: Matrix dimensions must match!\n";
                return result;
            }
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    result.mat[i][j] = mat[i][j] + other.mat[i][j];
            return result;
        }
    };

// Main Menu
int main() {
    AlgebraCalculator algebra;
    TrigonometryCalculator trig;
    RightTriangle rt;
    RightTriangle::Triangle t;
    
    char choice;
    const string filename = "triangle_data.txt";

    do {
        cout << "\nScientific Calculator:\n";
        cout << "1. Algebra Calculator\n";
        cout << "2. Trigonometry Calculator\n";
        cout << "3. Right Triangle Calculator\n";
        cout << "4. Matrix Operations\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int algChoice;
                do {
                    cout << "\nAlgebra Calculator:\n";
                    cout << "1. Basic Operations (+, -, *, /)\n";
                    cout << "2. Solve Linear Equation\n";
                    cout << "3. Solve Quadratic Equation\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Choose an option: ";
                    cin >> algChoice;
                    if (algChoice == 1) algebra.basicOperations();
                    else if (algChoice == 2) algebra.solveLinearEquation();
                    else if (algChoice == 3) algebra.solveQuadraticEquation();
                } while (algChoice != 4);
                break;
            }
            case '2':
                trig.calculate();
                break;
            case '3': {
                rt.initializeTriangle(&t);
                rt.displayTriangle(&t);
                cout << "Largest side: " << rt.findLargestSide(&t) << endl;
                if (rt.isRightAngledTriangle(&t))
                    cout << "The triangle is right-angled.\n";
                else
                    cout << "The triangle is not right-angled.\n";
                rt.saveTriangleToFile(&t, filename);
                rt.loadTrianglesFromFile(filename);
                break;
            }
            case '4': { // Matrix operations
                int r, c;
                cout << "Enter matrix size (rows cols): ";
                cin >> r >> c;
                Matrix A(r, c), B(r, c);
                cout << "Matrix A:\n"; A.input();
                cout << "Matrix B:\n"; B.input();
                Matrix sum = A.add(B);
                cout << "Sum:\n"; sum.display();
                break;
            }
            case '5':
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != '5');

    return 0;
}

// Compare this snippet from shopping.c%2B%2B: