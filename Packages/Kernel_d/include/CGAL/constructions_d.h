#ifndef CGAL_CONSTRUCTIONS_D_H
#define CGAL_CONSTRUCTIONS_D_H

CGAL_BEGIN_NAMESPACE

/*{\Moptions outfile=constructions_d.man}*/

/*{\Mtext \setopdims{4cm}{2cm}\computewidths
\headerline{Constructions}}*/

template <class R>
Point_d<R> lift_to_paraboloid(const Point_d<R>& p)
/*{\Mfunc returns $p = (x_0,\ldots,x_{d-1})$ lifted to the paraboloid 
of revolution . }*/
{ typename R::Lift_to_paraboloid_d lift; 
  return lift(p); }

template <class R>
Point_d<R> project_along_d_axis(const Point_d<R>& p)
/*{\Mfunc returns |p| projected along the $d$-axis onto the hyperspace
spanned by the first $d-1$ standard base vectors.}*/
{ typename R::Project_along_d_axis_d proj; 
  return proj(p); }

template <class R>
Point_d<R> midpoint(const Point_d<R>& p, const Point_d<R>& q)
/*{\Mfunc returns the midpoint of |p| and |q|. }*/
{ typename R::Midpoint_d mp; return mp(p,q); }

template <class R, class Forward_iterator>
Point_d<R> center_of_circle(Forward_iterator start, Forward_iterator end)
{ typename R::Center_of_circleHd center; 
  return center(start,end); }

template <class R> typename R::FT
squared_distance(const Point_d<R>& p, const Point_d<R>& q)
/*{\Mfunc returns the squared distance between |p| and $q$. }*/
{ typename R::Squared_distance_d dist; return dist(p,q); }

template <class ForwardIterator, class OutputIterator>
OutputIterator linear_base(
  ForwardIterator first, ForwardIterator last, OutputIterator result)
/*{\Mfunc computes a basis of the linear space spanned by the vectors 
in |set [first,last)| and returns it via an iterator range starting
in |result|. The returned iterator marks the end of the output.
\precond value type of |ForwardIterator| is |Vector_d<R>|.}*/
{ typedef typename std::iterator_traits<ForwardIterator>::
    value_type value_type;
  typedef typename value_type::R R;
  typename R::Linear_base_d base; 
  return base(first,last,result); 
}


CGAL_END_NAMESPACE
#endif // CGAL_CONSTRUCTIONS_D_H

