#ifndef SOCIOCLUB_H
#define SOCIOCLUB_H
#include <iostream>

class SocioClub
{
    private:
        int NumeroSocio, AnioIngreso;
        std::string NombreSocio,Domicilio;

    public:
        SocioClub();
        friend std::istream &operator >>(std::istream &,SocioClub &);
        friend std::ostream &operator <<(std::ostream &,SocioClub &);
        bool operator<(SocioClub&);
        bool operator>(SocioClub&);
        bool operator!=(SocioClub&);
        bool operator==(SocioClub&);
        void setNombre(std::string);
        void setDomicilio(std::string);

};

#endif // SOCIOCLUB_H
