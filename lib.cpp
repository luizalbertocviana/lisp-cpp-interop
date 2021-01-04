template <typename Number = double>
class Point {
private:
  Number x_;
  Number y_;
public:
  const Number& x;
  const Number& y;
  
  Point(Number x, Number y) : x_{x}, y_{y}, x{x_}, y{y_}
  {}
  
};

struct CPoint {
  Point<>* point;
};

extern "C" CPoint* CPoint_new(double x, double y) {
  CPoint* cpoint_ptr = new CPoint();

  cpoint_ptr->point = new Point<>(x, y);

  return cpoint_ptr;
}

extern "C" void CPoint_delete(CPoint* cpoint_ptr) {
  delete cpoint_ptr->point;

  delete cpoint_ptr;
}

extern "C" double CPoint_x(CPoint* cpoint_ptr) {
  return cpoint_ptr->point->x;
}

extern "C" double CPoint_y(CPoint* cpoint_ptr) {
  return cpoint_ptr->point->y;
}
