#ifndef MEMBUAT_GEOMETRIS_DONAT
#define MEMBUAT_GEOMETRIS_DONAT

#include <vector>
#include <cmath>
#include "vektor_operasi.hpp"
#include "matrix_rotasi.hpp"

class Donat_Geometris {
    private:
    float R;
    float r;

    float PI;

    int segment_u;
    int segment_v;

    float sudut;

    operasi_rotasi_matrix rotasi_matrix;

    std::vector<vektor_3d> vertices;

    float perhitungan_sudut(float sudut);

    vektor_3d torus_vertex(
        float R,
        float r,
        float u,
        float v
    );

    int indeks_vertex(
        int u,
        int v
    );

    public:
    Donat_Geometris();

    void penggabungan_torus(
        float R,
        float r,
        int segment_u,
        int segment_v
    );

    vektor_3d operasi_aljabar_linear_ke_geometris(
        matrix_3d m,
        vektor_3d v
    );

    void rotasi(float sudut);

    const std::vector<vektor_3d>& mendapatkan_vertices() const {
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