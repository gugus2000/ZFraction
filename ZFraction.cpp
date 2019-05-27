#include "ZFraction.h"
#include <iostream>
#include <ostream>

using namespace std;

int pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ZFraction::ZFraction(int numerateur, int denominateur) : m_numerateur(numerateur), m_denominateur(denominateur)
{
    convertirFractionSoloA();
}
bool ZFraction::estEgal(ZFraction& b)
{
    convertirFraction(b);
    return (m_numerateur == b.m_numerateur && m_denominateur == b.m_denominateur);
}
bool ZFraction::estPlusPetitQue(ZFraction& b)
{
    convertirFraction(b);
    return ((m_numerateur / m_denominateur) < (b.m_numerateur / b.m_denominateur));
}
void ZFraction::convertirFractionSoloA()
{
    int pgcda;
    pgcda = pgcd(m_numerateur, m_denominateur);
    m_numerateur = m_numerateur / pgcda;
    m_denominateur = m_denominateur / pgcda;
}
void ZFraction::convertirFraction(ZFraction& b)
{
    int pgcdm;
    int pgcdbm;
    pgcdm = pgcd(m_numerateur, m_denominateur);
    pgcdbm = pgcd(b.m_numerateur, b.m_denominateur);
    m_numerateur = m_numerateur / pgcdm;
    m_denominateur = m_denominateur / pgcdm;
    b.m_numerateur = b.m_numerateur / pgcdbm;
    b.m_denominateur = b.m_denominateur / pgcdbm;
    if (m_numerateur < 0 && m_denominateur < 0)
    {
        m_numerateur = 0 - m_numerateur;
        m_denominateur = 0 - m_denominateur;
    }
    if (b.m_numerateur < 0 && b.m_denominateur < 0)
    {
        b.m_numerateur = 0 - b.m_numerateur;
        b.m_denominateur = 0 - b.m_denominateur;
    }
    if (m_denominateur < 0)
    {
        m_numerateur = m_numerateur * -1;
        m_denominateur = 0 - m_denominateur;
    }
     if (b.m_denominateur < 0)
    {
        b.m_numerateur = b.m_numerateur * -1;
        b.m_denominateur = 0 - b.m_denominateur;
    }
}
void ZFraction::mettreDenominateurCommun(ZFraction& a)
{
    while(m_denominateur != a.m_denominateur)
    {
        int copie;
        copie = m_denominateur * a.m_denominateur;
        m_numerateur = m_numerateur * a.m_denominateur;
        a.m_numerateur = a.m_numerateur * m_denominateur;
        a.m_denominateur = a.m_denominateur * m_denominateur;
        m_denominateur = copie;
    }
}
void ZFraction::afficher(ostream &flux, ZFraction& a)
{
    convertirFraction(a);
    if ((m_denominateur == 1) || (m_denominateur == 0 && m_numerateur == 0))
    {
        flux << m_numerateur;
    }
    else
    {
        flux << m_numerateur << "/" << m_denominateur;
    }
}
int ZFraction::numerateur(ZFraction& a)
{
    return m_numerateur;
}
int ZFraction::denominateur(ZFraction& a)
{
    return m_denominateur;
}
double ZFraction::nombreReel(ZFraction& a)
{
    double nombreReel(m_numerateur/m_denominateur);
    return nombreReel;
}
ZFraction& ZFraction::operator+=(ZFraction& a)
{
    convertirFraction(a);
    mettreDenominateurCommun(a);
    m_numerateur += a.m_numerateur;
    convertirFraction(a);
    return *this;
}
ZFraction& ZFraction::operator-=(ZFraction& a)
{
    convertirFraction(a);
    mettreDenominateurCommun(a);
    m_numerateur -= a.m_numerateur;
    convertirFraction(a);
    return *this;
}
ZFraction& ZFraction::operator*=(ZFraction& a)
{
    convertirFraction(a);
    m_denominateur *= a.m_denominateur;
    m_numerateur *= a.m_numerateur;
    convertirFraction(a);
    return *this;
}
ZFraction& ZFraction::operator/=(ZFraction& a)
{
    convertirFraction(a);
    m_denominateur *= a.m_numerateur;
    m_numerateur *= a.m_denominateur;
    convertirFraction(a);
    return *this;
}
void ZFraction::operateurMoinsUnaire(ZFraction& a)
{
    convertirFraction(a);
    m_numerateur = m_numerateur * -1;
}
bool operator==(ZFraction& a, ZFraction& b)
{
    return a.estEgal(b);
}
bool operator!=(ZFraction& a, ZFraction& b)
{
    return !(a.estEgal(b));
}
bool operator<(ZFraction& a, ZFraction& b)
{
    return a.estPlusPetitQue(b);
}
bool operator<=(ZFraction& a, ZFraction& b)
{
    return ((a < b) || (a == b));
}
bool operator>(ZFraction& a, ZFraction& b)
{
    return !(a <= b);
}
bool operator>=(ZFraction& a, ZFraction& b)
{
    return !(a < b);
}
ZFraction operator+(ZFraction& a, ZFraction& b)
{
    ZFraction copie(a);
    copie += b;
    return copie;
}
ZFraction operator-(ZFraction& a, ZFraction& b)
{
    ZFraction copie(a);
    copie -= b;
    return copie;
}
ZFraction operator*(ZFraction& a, ZFraction& b)
{
    ZFraction copie(a);
    copie *= b;
    return copie;
}
ZFraction operator/(ZFraction& a, ZFraction& b)
{
    ZFraction copie(a);
    copie /= b;
    return copie;
}
ZFraction operator!-(ZFraction& a)
{
    ZFraction operateurMoinsUnaire(a);
    return a;
}
