#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

// call by value:  a, b, c
// call by reference: r1, r2
int quad(double a, double b, double c, double &r1, double &r2);

// call by value:  x
// call by reference: d[], f
void cubic(double d[], double x, double &f); // I know in the work doc it said the variable had to be a[] but I alredy have an a value in quad so I changed it to d[]

// all of inputs are call by reference
void initialize_matrix(double A[5][5], double &min, double &ave, int &npos);

// again all are call by reference because arrays are always call by reference: s1[], s2[]
int string_comp(char s1[], char s2[], int &E);


int main()
{
    // Q1 and Q2
    double a, b, c, r1, r2;
    a = b = c = r1 = r2 = 0.0;

    cout << "\nInput your three values for a b and c:";
    cin >> a;
    cin >> b;
    cin >> c;

    if (quad(a, b, c, r1, r2) == 0)
    {
        cout << "\nYour roots are " << r1 << " and " << r2;
    }
    else
    {
        cout << "\nThe values you have input are invalid and the roots are imaginary";
    }

    // Q3
    double d[4], x, f;

    cout << "\nInput 4 coefficients d[0] d[1] d[2] d[3]: \n";
    for (int i = 0; i < 4; i++)
        cin >> d[i];
    cout << "Input x: ";
    cin >> x;

    cubic(d, x, f);
    cout << "\nf = " << f;

    // Q4
    double A[5][5], min, ave;
    int npos;

    initialize_matrix(A, min, ave, npos);

    cout << "\nMatrix A[i][j] = sin(i) + cos(j):";
    for (int i = 0; i < 5; i++)
    {
        cout << "\n";
        for (int j = 0; j < 5; j++)
            cout << A[i][j] << " ";
    }
    cout << "\nMin element : " << min;
    cout << "\nAverage     : " << ave;
    cout << "\nPositive cnt: " << npos;

    // Q5
    char s1[100], s2[100];
    int E = 0;

    cout << "\nInput string 1: ";
    cin >> s1;
    cout << "Input string 2: ";
    cin >> s2;

    string_comp(s1, s2, E);
    if (E == 1)
        cout << "\nStrings are equal.";
    else
        cout << "\nStrings are NOT equal.";

    cout << "\nEnd of Line...";
    return 0;
}

int quad(double a, double b, double c, double &r1, double &r2)
{
    double discriminant = b * b - 4 * a * c;
    if (a == 0)
        return 1;
    if (discriminant >= 0)
    {
        r1 = (-b + sqrt(discriminant)) / (2 * a);
        r2 = (-b - sqrt(discriminant)) / (2 * a);
        return 0;
    }
    else
    {
        return 1;
    }
}

void cubic(double d[], double x, double &f)
{
    f = 0.0;
    for (int i = 0; i <= 3; i++)
    {
        f += d[i] * pow(x, i);
    }
}

void initialize_matrix(double A[5][5], double &min, double &ave, int &npos)
{
    double sum = 0.0;
    npos = 0;
    min = sin(0) + cos(0);  // initialize to first element

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            A[i][j] = sin(i) + cos(j);
            sum += A[i][j];
            if (A[i][j] < min)
                min = A[i][j];
            if (A[i][j] > 0)
                npos++;
        }
    }
    ave = sum / 25.0;
}

int string_comp(char s1[], char s2[], int &E)
{
    int i = 0;
    
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            E = 0;
            return 0;
        }
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        E = 1;
    else
        E = 0;
    return 0;
}
