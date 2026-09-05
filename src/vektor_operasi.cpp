#include "vektor_operasi.hpp"

operasi_vektor::operasi_vektor() :
	hasil_operasi(0.0f), skalar(0.0f) {
		// kosong
}

vektor_3d operasi_vektor::operasi_penjumlahan(vektor_3d u,
		vektor_3d v) {

	hasil_operasi = {
		u.x + v.x,
		u.y + v.y,
		u.z + v.z
	};

	return hasil_operasi;
}

vektor_3d operasi_vektor::operasi_pengurangan(vektor_3d u, 
		vektor_3d v) {
	
	hasil_operasi = {
		u.x + v.x,
		u.y + v.y,
		u.z + v.z
	};

	return hasil_operasi;
}


vektor_3d operasi_vektor::operasi_skalar(vektor_3d u,
		float skalar) {
	
	hasil_operasi {
		skalar * u.x,
		skalar * u.y,
		skalar * u.z
	};

	return hasil_operasi;
}


