#ifndef CGAL_PAIR_D_H
#define CGAL_PAIR_D_H

#include <CGAL/basic.h>
#include <CGAL/Handle_for.h>

CGAL_BEGIN_NAMESPACE

template <class R> class Segment_d;
template <class R> class Ray_d;
template <class R> class Line_d;

template <class R> 
class Pair_d : public Ref_counted { 
  typedef Pair_d<R> Self;
  typedef typename R::Point_d Point_d;
  typedef typename R::Vector_d Vector_d;
  typedef typename R::Direction_d Direction_d;
  Point_d _p[2];

  friend class Line_d<R>; 
  friend class Ray_d<R>; 
  friend class Segment_d<R>; 
   
/* Any line object in $d$ - space is defined by two points |_p1| and |_p2|
respectively. There exists an orientation from _p1 to _p2. */

public: 
Pair_d(int d = 0) { _p[0]=_p[1]=Point_d(d); }

Pair_d(const Point_d& p, const Point_d& q) 
{ CGAL_assertion_msg((p.dimension() == q.dimension()), 
  "Pair_d::constructor: source and target must have the same dimension."); 
  _p[0]=p; _p[1]=q;
}

Pair_d(const Self& p) 
{ _p[0]=p._p[0]; _p[1]=p._p[1]; }
Self& operator=(const Self& p) 
{ _p[0]=p._p[0]; _p[1]=p._p[1]; return *this; }

bool  is_degenerate() const
{ return (_p[0] == _p[1]); }

Vector_d vector() const 
{ return (_p[1] - _p[0]); }

Direction_d direction() const 
{ return vector().direction(); }

void read(std::istream& is)
{ 
  switch( is.iword(CGAL::IO::mode) ) {
    case CGAL::IO::ASCII :
      is >> _p[0] >> _p[1]; break;
    case CGAL::IO::BINARY :
      CGAL::read(is, _p[0]); CGAL::read(is, _p[1]); break;
    default:
    CGAL_assertion_msg(0,"\nStream must be in ascii or binary mode\n"); 
  }
}

void print(std::ostream& os, char* _name) const
{ 
  switch( os.iword(CGAL::IO::mode) ) {
    case CGAL::IO::ASCII :
      os << _p[0] << " " <<  _p[1]; break;
    case CGAL::IO::BINARY :
      CGAL::write(os, _p[0]); CGAL::write(os, _p[1]); break;
    default :
      os << _name << "(" << _p[0] << ", " << _p[1] << ")"; break;
  }
}

}; // Pair_d<R>

CGAL_END_NAMESPACE
#endif //CGAL_PAIR_D_H

