#include "skinny_yee.h"
#include "../em-fields/tile.h"

#include "../tools/iter/allocator.h"

  // real initializer constructor
  ffe::SkinnyYeeLattice::SkinnyYeeLattice(int Nx, int Ny, int Nz) : 
    Nx(Nx), Ny(Ny), Nz(Nz),

    ex(Nx, Ny, Nz),
    ey(Nx, Ny, Nz),
    ez(Nx, Ny, Nz),

    bx(Nx, Ny, Nz),
    by(Nx, Ny, Nz),
    bz(Nx, Ny, Nz)
    { 
    DEV_REGISTER
      
    }


ffe::SkinnyYeeLattice& 
  ffe::SkinnyYeeLattice::operator +=(const ffe::SkinnyYeeLattice& rhs)
{
  ex += rhs.ex;
  ey += rhs.ey;
  ez += rhs.ez;
  bx += rhs.bx;
  by += rhs.by;
  bz += rhs.bz;

  return *this;
}

ffe::SkinnyYeeLattice& 
  ffe::SkinnyYeeLattice::operator -=(const ffe::SkinnyYeeLattice& rhs) 
{
  ex -= rhs.ex;
  ey -= rhs.ey;
  ez -= rhs.ez;
  bx -= rhs.bx;
  by -= rhs.by;
  bz -= rhs.bz;

  return *this;
}

ffe::SkinnyYeeLattice& 
  ffe::SkinnyYeeLattice::operator *=(double rhs) 
{
  ex *= static_cast<real_short>(rhs);
  ey *= static_cast<real_short>(rhs);
  ez *= static_cast<real_short>(rhs);
  bx *= static_cast<real_short>(rhs);
  by *= static_cast<real_short>(rhs);
  bz *= static_cast<real_short>(rhs);

  return *this;
}

ffe::SkinnyYeeLattice& 
  ffe::SkinnyYeeLattice::operator /=(double rhs) 
{
  ex /= static_cast<real_short>(rhs);
  ey /= static_cast<real_short>(rhs);
  ez /= static_cast<real_short>(rhs);
  bx /= static_cast<real_short>(rhs);
  by /= static_cast<real_short>(rhs);
  bz /= static_cast<real_short>(rhs);

  return *this;
}


/// copy yee grid to skinny yee
void ffe::SkinnyYeeLattice::set_yee(const fields::YeeLattice& yee)
{
  ex = yee.ex;
  ey = yee.ey;
  ez = yee.ez;
  bx = yee.bx;
  by = yee.by;
  bz = yee.bz;
}

ffe::SkinnyYeeLattice 
  ffe::operator +(ffe::SkinnyYeeLattice lhs, const ffe::SkinnyYeeLattice& rhs)
{
  lhs += rhs;
  return lhs;
}

ffe::SkinnyYeeLattice 
  ffe::operator -(ffe::SkinnyYeeLattice lhs, const ffe::SkinnyYeeLattice& rhs)
{
  lhs -= rhs;
  return lhs;
}

ffe::SkinnyYeeLattice 
  ffe::operator *(ffe::SkinnyYeeLattice lhs, double rhs)
{
  lhs *= rhs;
  return lhs;
}

ffe::SkinnyYeeLattice 
  ffe::operator /(ffe::SkinnyYeeLattice lhs, double rhs)
{
  lhs *= rhs;
  return lhs;
}

