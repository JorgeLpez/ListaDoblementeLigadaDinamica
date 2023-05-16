#include "SocioClub.h"

SocioClub::SocioClub()
{
    //ctor
}

std::istream & operator >>(std::istream &O, SocioClub &X)
{
    std::cout<<"\nNumero de socio: ";
    O>>X.NumeroSocio;
    std::cout<<"Nombre de socio: ";
    O>>X.NombreSocio;
    std::cout<<"Domicilio: ";
    O>>X.Domicilio;
    std::cout<<"Año de ingreso: ";
    O>>X.AnioIngreso;

    return O;
}

std::ostream &operator <<(std::ostream &O, SocioClub &X)
{
    O<<"\nNumero de socio: "<<X.NumeroSocio<<std::endl;
    O<<"Nombre de socio: "<<X.NombreSocio<<std::endl;
    O<<"Domicilio: "<<X.Domicilio<<std::endl;
    O<<"Año de ingreso: "<<X.AnioIngreso<<std::endl;

    return O;
}

bool SocioClub::operator<(SocioClub& c)
{
    if(c.NumeroSocio<NumeroSocio ){
        return true;
    }
    return false;
}

bool SocioClub::operator>(SocioClub& c)
{
    if(c.NumeroSocio>NumeroSocio){
        return true;
    }
    return false;
}

bool SocioClub::operator!=(SocioClub& c)
{
    return NombreSocio != c.NombreSocio && Domicilio != c.Domicilio;
}

bool SocioClub::operator==(SocioClub& c)
{
    return NumeroSocio == c.NumeroSocio;
}

void SocioClub::setNombre(std::string N)
{
    NombreSocio = N;
}

void SocioClub::setDomicilio(std::string D)
{
    Domicilio = D;
}
