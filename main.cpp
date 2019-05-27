#include <iostream>
#include "ZFraction.h"
#include <ostream>

using namespace std;


ostream& operator<<( ostream& flux, ZFraction& a )
{
    a.afficher(flux, a);
    return flux;
}

int main()
{
    ZFraction a(8, 10);
    ZFraction b(2);
	double g;
	cin >> g;
    ZFraction c(g, 3), d, e, f;
    c = a + b;
    d = a - b;
    e = a * b;
    f = a / b;
    cout << a << " + " << b << " = " << c << endl;
    cout << a << " - " << b << " = " << d << endl;
    cout << a << " x " << b << " = " << e << endl;
    cout << a << " : " << b << " = " << f << endl;
    if (a > b)
    {
        cout << a << " est plus grand que " << b << "." << endl;
    }
    else if (a == b)
    {
        cout << a << " est egal a " << b << "." << endl;
    }
    else
    {
        cout << a << "est plus petit que " << b << "." << endl;
    }
    ZFraction def(-4, -4), gerard(-5, 1), g(5, -10);
    cout << def << ", " << gerard << ", " << g << endl;

    return 0;
}
