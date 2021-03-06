
/*************************************************************************
                           Arc
                             -------------------
     debut		: 2019-01-16
 	copyright	: (C) 2018 par K. BOUZID et P-Y. GENEST
 	e-mail		: kenza.bouzid@insa-lyon.fr
 			  pierre-yves.genest@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Arc> (fichier Arc.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Arc.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Arc::Afficher ( const string s ) const
{
  if (s != "")
  {
    cout << s << endl ;
  }
  cout << referer << " (" << cardinalite << " hits)" << endl;
} // Fin de Afficher

//------------------------------------------------- Surcharge d'opérateurs
Arc & Arc::operator = ( const Arc & unArc )
// Algorithme :
//
{
  if (this != &unArc)
  {
      referer = unArc.referer;
      cardinalite= unArc.cardinalite;
  }
  return *this ;
} //----- Fin de operator =

bool Arc::operator < ( const Arc & unArc ) const
{
  if (cardinalite == unArc.cardinalite)
    {
      return compare_nocase (referer, unArc.referer);
    }
  return cardinalite > unArc.cardinalite ;
}//----- Fin de operator <

//-------------------------------------------- Constructeurs - destructeur
Arc::Arc ( const Arc & unArc )
// Algorithme :
//
{
  referer = unArc.referer;
  cardinalite = unArc.cardinalite;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Arc>" << endl;
#endif
} //----- Fin de Arc (constructeur de copie)


Arc::Arc ( string unReferer  , unsigned int card ): referer(unReferer) ,
cardinalite(card)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Arc>" << endl;
#endif
} //----- Fin de Arc


Arc::~Arc ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Arc>" << endl;
#endif
} //----- Fin de ~Arc

//----------------------------------------------------- Méthodes protégées
bool Arc::compare_nocase (const string & first, const string & second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if ( tolower(first[i]) < tolower(second[i] )) return true;
    else if ( tolower(first[i]) > tolower(second[i] )) return false;
    ++i;
  }

  if (first.length()<second.length()) return true;
  else return false;
}
