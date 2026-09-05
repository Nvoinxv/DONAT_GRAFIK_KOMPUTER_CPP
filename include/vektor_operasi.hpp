#ifndef VEKTOR_HPP
#define VEKTOR_HPP

#include <iostream>
#include <vector>
#include <cmath>

struct vektor_3d {
	float x,
	float y,
	float z
};

class operasi_vektor() {
	private:
	float hasil_operasi;
        float skalar;

	public:
	operasi_vektor();

	vektor_3d operasi_penjumlahan(vektor_3d u, 
			vektor_3d v);

	vektor_3d operasi_pengurangan(vektor_3d u,
			vektor_3d v);

	vektor_3d operasi_skalar(vektor_3d u,
	    float skalar);
};

#endif


