#include "matrix_rotasi.hpp"

operasi_rotasi_matrix::operasi_rotasi_matrix() : 
	theta(0.0f), hasil_perhitungan{} {
		// kosong
	}

matrix_3d operasi_rotasi_matrix::rotasi_matrix_x(float theta) {
	hasil_perhitungan.data[0][0] = 1.0f;
	hasil_perhitungan.data[0][1] = 0.0f;
	hasil_perhitungan.data[0][2] = 0.0f;

	hasil_perhitungan.data[1][0] = 0.0f;
	hasil_perhitungan.data[1][1] = std::cos(theta);
	hasil_perhitungan.data[1][2] = -(std::sin(theta));

	hasil_perhitungan.data[2][0] = 0.0f;
	hasil_perhitungan.data[2][1] = std::sin(theta);
	hasil_perhitungan.data[2][2] = std::cos(theta);

	return hasil_perhitungan;
}

matrix_3d operasi_rotasi_matrix::rotasi_matrix_y(float theta) {
	hasil_perhitungan.data[0][0] = std::cos(theta);
	hasil_perhitungan.data[0][1] = 0.0f;
	hasil_perhitungan.data[0][2] = std::sin(theta);

	hasil_perhitungan.data[1][0] = 0.0f;
	hasil_perhitungan.data[1][1] = 1.0f;
	hasil_perhitungan.data[1][2] = 0.0f;

	hasil_perhitungan.data[2][0] = -(std::sin(theta));
	hasil_perhitungan.data[2][1] = 0.0f;
	hasil_perhitungan.data[2][2] = std::cos(theta);

	return hasil_perhitungan;
}

matrix_3d operasi_rotasi_matrix::rotasi_matrix_z(float theta) {
	hasil_perhitungan.data[0][0] = std::cos(theta);
	hasil_perhitungan.data[0][1] = -(std::sin(theta));
	hasil_perhitungan.data[0][2] = 0.0f;

	hasil_perhitungan.data[1][0] = std::sin(theta);
	hasil_perhitungan.data[1][1] = std::cos(theta);
	hasil_perhitungan.data[1][2] = 0.0f;

	hasil_perhitungan.data[2][0] = 0.0f;
	hasil_perhitungan.data[2][1] = 0.0f;
	hasil_perhitungan.data[2][2] = 1.0f;

	return hasil_perhitungan;
}