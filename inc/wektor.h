#ifndef WEKTOR_H
#define WEKTOR_H

#include<iostream>
#include<math.h>

//#include"LZespolona.hh"

#define BLAD_PRZYROWNANIA 0.0000001




template<class TYP,int ROZMIAR>
class Wektor{
protected:
    static int ileStworzono;
    static int ileIstnieje;
    TYP tab[ROZMIAR];

public:

    Wektor();
    //Wektor(TYP x,TYP y,TYP z);                 //nie ma sensu
    Wektor(TYP *tab);

    Wektor(const Wektor<TYP,ROZMIAR> & tmp){*this = tmp;ileIstnieje++;ileStworzono++;}
    ~Wektor(){ileIstnieje--;}



    const Wektor<TYP,ROZMIAR> & operator += (const Wektor<TYP,ROZMIAR> &W2);
    const Wektor<TYP,ROZMIAR> & operator -= (const Wektor<TYP,ROZMIAR> &W2);
    const Wektor<TYP,ROZMIAR> & operator *= (double l1);


    //REZYGNACJA Z: const Wektor & operator + (const Wektor &W2) const; , ETC.
    //ZE ZNAKIEM & PROGRAM WYRZUCAŁ SEGMENTATION FAULT

    Wektor<TYP,ROZMIAR> operator + (const Wektor<TYP,ROZMIAR> &W2) const;
    Wektor<TYP,ROZMIAR> operator - (const Wektor<TYP,ROZMIAR> &W2) const;
    TYP operator * (const Wektor<TYP,ROZMIAR> &W2) const;
    Wektor<TYP,ROZMIAR> operator *(TYP li) const;

    bool operator == (const Wektor<TYP,ROZMIAR> &W2) const;
    bool operator != (const Wektor<TYP,ROZMIAR> & W2) const;

    double dlugosc() const;


    const TYP & operator[] (int index) const;
    TYP & operator[] (int index);



};

template<class TYP,int ROZMIAR>
std::ostream &operator << (std::ostream &strm, const Wektor<TYP,ROZMIAR> &W);

template<class TYP,int ROZMIAR>
std::istream &operator >>(std::istream &strm, Wektor<TYP,ROZMIAR> &W);


template<class TYP,int ROZMIAR>
Wektor<TYP,ROZMIAR> operator *(double l1,const Wektor<TYP,ROZMIAR> &W2);





#endif // WEKTOR_H
