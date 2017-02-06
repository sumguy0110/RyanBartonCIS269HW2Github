#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class Polynomial
{
private:
    vector<T> polyOne;
    vector<T> polyTwo;

public:
    Polynomial(vector<T> &pOne, vector<T> &pTwo)
    {
        polyOne = pOne;
        polyTwo = pTwo;
    }

    void AddPolynomial()
    {
        cout << "Polynomial Addition Result: \n";
        vector<T> tempAddPoly(3);

        for (int i = 0; i < tempAddPoly.size(); i++)
        {
            tempAddPoly[i] = polyOne[i] + polyTwo[i];
            if (i == 0)
            {
                cout << "(" << tempAddPoly[i] << "x^2 + ";
            }
            if (i == 1)
            {
                cout << tempAddPoly[i] << "x + ";
            }
            if (i == 2)
            {
                cout << tempAddPoly[i] << ") \n";
            }
        }

    }

    void MultplyPolynomial()
    {
        vector<T> tempMultiPoly;

        for (int i = 0; i < polyOne.size(); i++)
        {
            for (int j = 0; j < polyTwo.size(); j++)
            {
                tempMultiPoly.push_back(polyOne[i] * polyTwo[j]);
            }
        }
        tempMultiPoly[1] = tempMultiPoly[1] + tempMultiPoly[3];
        tempMultiPoly[2] = tempMultiPoly[2] + tempMultiPoly[4] + tempMultiPoly[6];
        tempMultiPoly[3] = tempMultiPoly[5] + tempMultiPoly[7];
        tempMultiPoly[4] = tempMultiPoly[8];

        tempMultiPoly.resize(5);

        cout << "\nPolynomial Multiplication Result: \n";
        for (int i = 0; i < tempMultiPoly.size(); i++)
        {
            if (i == 0)
            {
                cout << "(" << tempMultiPoly[i] << "x^4 + ";
            }
            if (i == 1)
            {
                cout << tempMultiPoly[i] << "x^3 + ";
            }
            if (i == 2)
            {
                cout << tempMultiPoly[i] << "x^2 + ";
            }
            if (i == 3)
            {
                cout << tempMultiPoly[i] << "x + ";
            }
            if (i == 4)
            {
                cout << tempMultiPoly[i] << ") \n";
            }
        }
    }
};

int main()
{
    vector<int> testPolyOne;
    testPolyOne.push_back(-2);
    testPolyOne.push_back(9);
    testPolyOne.push_back(-16);

    vector<int> testPolyTwo;
    testPolyTwo.push_back(3);
    testPolyTwo.push_back(-3);
    testPolyTwo.push_back(3);


    Polynomial<int> testAddPoly(testPolyOne, testPolyTwo);
    testAddPoly.AddPolynomial();

    Polynomial<int> testMultiPoly(testPolyOne, testPolyTwo);
    testMultiPoly.MultplyPolynomial();

    return 0;
}
