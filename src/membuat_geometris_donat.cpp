#include "membuat_geometris_donat.hpp"

Donat_Geometris::Donat_Geometris()
    : R(10.0f),
      r(3.0f),
      rotasi_matrix(),
      PI(3.141592653589793f),
      vertices(),
      segment_u(30),
      segment_v(15),
      sudut(0.0f)
{
    // Kosong
}


float Donat_Geometris::perhitungan_sudut(float sudut) {
    return sudut * PI / 180.0f;
}


vektor_3d Donat_Geometris::torus_vertex(
    float R,
    float r,
    float u,
    float v
) {
    vektor_3d vertex;

    vertex.x =
        (R + r * std::cos(v)) *
        std::cos(u);

    vertex.y =
        (R + r * std::cos(v)) *
        std::sin(u);

    vertex.z =
        r * std::sin(v);

    return vertex;
}


int Donat_Geometris::indeks_vertex(
    int u,
    int v
) {
    u = u % segment_u;
    v = v % segment_v;

    return u * segment_v + v;
}


void Donat_Geometris::penggabungan_torus(
    float R,
    float r,
    int segment_u,
    int segment_v
) {
    this->R = R;
    this->r = r;

    this->segment_u = segment_u;
    this->segment_v = segment_v;

    vertices.clear();

    for (int i = 0; i < segment_u; i++) {
        float u =
            2.0f * PI * i / segment_u;

        for (int j = 0; j < segment_v; j++) {
            float v =
                2.0f * PI * j / segment_v;

            vektor_3d vertex =
                torus_vertex(
                    R,
                    r,
                    u,
                    v
                );

            vertices.push_back(vertex);
        }
    }
}


vektor_3d Donat_Geometris::operasi_aljabar_linear_ke_geometris(
    matrix_3d m,
    vektor_3d v
) {
    return {
        m.data[0][0] * v.x +
        m.data[0][1] * v.y +
        m.data[0][2] * v.z,

        m.data[1][0] * v.x +
        m.data[1][1] * v.y +
        m.data[1][2] * v.z,

        m.data[2][0] * v.x +
        m.data[2][1] * v.y +
        m.data[2][2] * v.z
    };
}


void Donat_Geometris::rotasi(float sudut) {
    float sudut_radian =
        perhitungan_sudut(sudut);

    matrix_3d R =
        rotasi_matrix.rotasi_matrix_y(
            sudut_radian
        );

    for (auto& vertex : vertices) {
        vertex =
            operasi_aljabar_linear_ke_geometris(
                R,
                vertex
            );
    }
}