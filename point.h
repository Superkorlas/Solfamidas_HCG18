
#ifndef _POINT_
#define _POINT_

class point {

	public:

		int x;
		int y;

		point( int i = 0, int j = 0 ) : x(i), y(j) {}

		point( point p ) : x(p.x), y(p.y);
};

#endif