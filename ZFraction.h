#ifndef DEF_ZFRACTION
#define DEF_ZFRACTION
#include <ostream>

int pgcd(int a, int b);

class ZFraction
{
public:
    ZFraction (int numerateur = 0, int denominateur = 1);
    void convertirFraction(ZFraction& b);
    void convertirFractionSoloA();
    void mettreDenominateurCommun(ZFraction& a);
    bool estEgal(ZFraction& b);
    void afficher(std::ostream &flux, ZFraction& a);
    bool estPlusPetitQue(ZFraction& b);
    int numerateur(ZFraction& a);
    int denominateur(ZFraction& a);
    double nombreReel(ZFraction& a);
    void operateurMoinsUnaire(ZFraction& a);
    ZFraction& operator+=(ZFraction& a);
    ZFraction& operator-=(ZFraction& a);
    ZFraction& operator*=(ZFraction& a);
    ZFraction& operator/=(ZFraction& a);
private:
    int m_numerateur;
    int m_denominateur;
};

bool operator==(ZFraction& a, ZFraction& b);
bool operator!=(ZFraction& a, ZFraction& b);
bool operator<(ZFraction& a, ZFraction& b);
bool operator<=(ZFraction& a, ZFraction& b);
bool operator>(ZFraction& a, ZFraction& b);
bool operator>=(ZFraction& a, ZFraction& b);
ZFraction operator+(ZFraction& a, ZFraction& b);
ZFraction operator-(ZFraction& a, ZFraction& b);
ZFraction operator*(ZFraction& a, ZFraction& b);
ZFraction operator/(ZFraction& a, ZFraction& b);
ZFraction operator-(ZFraction& a);

#endif // DEF_ZFRACTION
