#include <iostream>
#include <stdexcept>
using namespace std;

void checkValidParams(double a, double b, double h, int n) {
    if (a > b) {
        throw invalid_argument("Error: 'a' should be less than or equal to 'b'.");
    }
    if (h <= 0) {
        throw invalid_argument("Error: 'h' should be greater than 0.");
    }
    if (n <= 0) {
        throw invalid_argument("Error: 'n' should be a positive integer.");
    }
}

double calcY(double x, int n) {
    double y = 1;

    if (x >= 0) {
        double p = 1;
        n = n - 3;
        for (int i = 0; i <= n; i++) {
            y += p * (-x - i);
        }
    }
    else {
        for (int i = 1; i < n; i++) {
            double p = 0;
            for (int j = 1; j < n; j++) {
                if (x - i - j == 0) {
                    throw runtime_error("Can`t divide by zero");
                }
                else {
                    p += 1 / (x - i - j);
                }
            }
            y += p;
        }
    }

    return y;
}

void readData(double& a, double& b, double& h, int& n) {
    cout << "Enter a = ";
    cin >> a;

    cout << "Enter b = ";
    cin >> b;

    cout << "Enter h = ";
    cin >> h;

    cout << "Enter n = ";
    cin >> n;
}

int main() {
    double a, b, h;
    int n;

    try {
        readData(a, b, h, n);
        checkValidParams(a, b, h, n);

        double x = a;
        while (x <= b) {
            try {
                double y = calcY(x, n);
                cout << "x = " << x << ", y = " << y << endl;
            }
            catch (const runtime_error& e) {
                cerr << "Error for x = " << x << ": " << e.what() << endl;
            }
            x += h;
        }
    }
    catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }

    return 0;
}
