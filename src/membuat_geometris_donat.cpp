#include "membuat_geometris_donat.hpp"

Donat_Geometris::Donat_Geometris()
    : R(0.0f),
      r(0.0f),
      rotasi_matrix(),
      PI(3.141592653589793f),
      vertices(),
      segment_u(0),
      segment_v(0),
      sudut(0.0f) {
    // Kosong
}


float Donat_Geometris::perhitungan_sudut(float sudut) {
    return sudut * PI / 180.0f;
}


vertex_donat_geometris Donat_Geometris::torus_x(
    float R,
    float r,
    int segment_u,
    int segment_v
) {
    vertex_donat_geometris vertex;

    for (int i = 0; i < segment_u; i++) {
        float u = 2.0f * PI * i / segment_u;

        for (int j = 0; j < segment_v; j++) {
            float v = 2.0f * PI * j / segment_v;

            vertex.x =
                (R + r * std::cos(v)) *
                std::cos(u);

            int titik_u = (i + 1) % segment_u;
            int titik_v = (j + 1) % segment_v;
        }
    }

    return vertex;
}


vertex_donat_geometris Donat_Geometris::torus_y(
    float R,
    float r,
    int segment_u,
    int segment_v
) {
    vertex_donat_geometris vertex;

    for (int i = 0; i < segment_u; i++) {
        float u = 2.0f * PI * i / segment_u;

        for (int j = 0; j < segment_v; j++) {
            float v = 2.0f * PI * j / segment_v;

            vertex.y =
                (R + r * std::cos(v)) *
                std::sin(u);

            int titik_u = (i + 1) % segment_u;
            int titik_v = (j + 1) % segment_v;
        }
    }

    return vertex;
}


vertex_donat_geometris Donat_Geometris::torus_z(
    float r,
    int segment_u,
    int segment_v
) {
    vertex_donat_geometris vertex;

    for (int i = 0; i < segment_u; i++) {
        for (int j = 0; j < segment_v; j++) {
            float v = 2.0f * PI * j / segment_v;

            vertex.z =
                r * std::sin(v);

            int titik_u = (i + 1) % segment_u;
            int titik_v = (j + 1) % segment_v;
        }
    }

    return vertex;
}


void Donat_Geometris::penggabungan_torus(
    float R,
    float r,
    int segment_u,
    int segment_v
) {
    vertex_donat_geometris bagian_x =
        torus_x(
            R,
            r,
            segment_u,
            segment_v
        );

    vertex_donat_geometris bagian_y =
        torus_y(
            R,
            r,
            segment_u,
            segment_v
        );

    vertex_donat_geometris bagian_z =
        torus_z(
            r,
            segment_u,
            segment_v
        );

    vertices.push_back({
        bagian_x.x,
        bagian_y.y,
        bagian_z.z
    });
}


vector_3d Donat_Geometris::operasi_aljabar_linear_ke_geometris(
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
        rotasi_matrix.rotasi_y(sudut_radian);

    for (auto& vertex : vertices) {
        vertex =
            operasi_aljabar_linear_ke_geometris(
                R,
                vertex
            );
    }
}