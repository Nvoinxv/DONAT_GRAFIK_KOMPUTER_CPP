#ifndef DONAT_GEOMETRIS
#define DONAT_GEOMETRIS

#include <cmath>
#include <vector>
#include "matrix_operasi.hpp"
#include "vektor_operasi.hpp"

struct vertex_donat_geometris {
	float u,
	float v
};

class Donat_Geometris {
	private:
	float R; // radius lingkaran besar
	float r; // radius tabung donat

	vertex_donat_geometris segment_u;
	vertex_donat_geometris segment_v;

	float sudut;

	operasi_rotasi_matrix rotasi_matrix;
	float PI = 3.141592653589793f;

	std::vector<vector_3d> vertices;

	public:
	Donat_Geometris();
	
	float perhitungan_sudut(float sudut);

	vertex_donat_geometris torus_x(
		float R,
		float r,
		vertex_donat_geometris segment_u,
		vertex_donat_geometris segment_v
	);

	vertex_donat_geometris torus_y (
		float R,
		float r
		vertex_donat_geometris segment_u,
		vertex_donat_geometris segment_v
	);

	vertex_donat_geometris torus_z (
		float R,
		float r
		vertex_donat_geometris segment_u,
		vertex_donat_geometris segment_v
	);
    
	void penggabungan_torus (
		float R,
		float r
		vertex_donat_geometris segment_u,
		vertex_donat_geometris segment_v
	);

	vector_3d operasi_aljabar_linear_ke_geometris(
		matrix_3d m, vektor_3d v
	);

    void rotasi(double sudut);
	
	const std::vector<vector_3d>& mendapatkan_vertices() const {
        return vertices;
    }

    int mendapatkan_segment_u() const {
        return segment_u;
    }

    int mendapatkan_segment_v() const {
        return segment_v;
    }
};

#endif
