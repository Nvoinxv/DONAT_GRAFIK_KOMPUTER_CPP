#ifndef OPERASI_MATRIX_HPP
#define OPERASI_MATRIX_HPP

#include <cmath>

struct matrix_3d {
	float data[3][3];
};

class operasi_rotasi_matrix {
	private:
       float theta;
	float hasil_perhitungan;

        public:
	operasi_rotasi_matrix();

	matrix_3d rotasi_matrix_x(float theta);
	matrix_3d rotasi_matrix_y(float theta);
	matrix_3d rotasi_matrix_z(float theta);

};

#endif
