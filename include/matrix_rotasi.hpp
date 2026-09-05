#ifndef OPERASI_MATRIX_HPP
#define OPERASI_MATRIX_HPP

#include <cmath>

struct matrix_3d {
	data[3][3]
};

class operasi_rotasi_matrix {
	private:
        double theta;

        public:
	operasi_rotasi_matrix();

	matrix_3d rotasi_matrix_x(double theta);
	matrix_3d rotasi_matrix_y(double theta);
	matrix_3d rotasi_matrix_z(double theta);

};

#endif
