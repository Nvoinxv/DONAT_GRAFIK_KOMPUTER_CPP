#include "matrix_rotasi.hpp"

operasi_rotasi_matrix::operasi_rotasi_matrix() : 
	theta(0.0f), hasil_perhitungan(0.0f) {
		// kosong
	}

matrix_3d operasi_rotasi_matrix::rotasi_matrix_x(float theta) {
	hasil_perhitungan = {
		{1.0f, 0.0f, 0.0f},
		{0.0f, std::cos(theta), -(std::sin(theta))},
		{0.0f, std::sin(theta), std::cos(theta)} 
	};

	return hasil_perhitungan;
}

matrix_3d operasi_rotasi_matrix::rotasi_matrix_y(float theta) {
	hasil_perhitungan = {
		{std::cos(theta), 0.0f, std::sin(theta)},
		{0.0f, 1.0f, 0.0f},
		{-(std::sin(theta), 0.0f, std::cos(theta)}
	        };
	
	return hasil_perhitungan;
}


matrix_3d operasi_rotasi_matrix::rotasi_matrix_z(float theta) {
        hasil_perhitungan = { 
	{std::cos(theta), -(std::sin(theta), 0.0f},
	{std::sin(theta), std::cos(theta), 0.0f},
	{0.0f, 0.0f, 1.0f}
	};

	return hasil_perhitungan;
}

