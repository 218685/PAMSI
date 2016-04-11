#ifndef IASSOCIATIVE_HH
#define IASSOCIATIVE_HH

#include <iostream>
using namespace std;

/*!
 * \file IAssociative.hh
 *
 *  Plik zawiera interfejs obiektu,
 *  który można poddawać pomiarom czasu działania.
 */

/*!
 * \brief
 *
 */
template < typename Object >
class IAssociative
{
public:
  virtual Object operator[](string klucz) = 0;
};

#endif
