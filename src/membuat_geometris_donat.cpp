#include "membuat_geometris_donat.hpp"

Donat_Geometris::Donat_Geometris() : R(0.0f), r(0.0f),
rotasi_matrix(), PI(3.141592653589793f), vertices(),
segment_u(), segment_v() {
    // Kosong
}

vertex_donat_geometris Donat_Geometris::torus_x (
    float R,
    float r,
    vertex_donat_geometris segment_u,
    vertex_donat_geometris segment_v
) {
    for (int i = 0; i < segment_u; i++) {
        vertex_donat_geometris.u = 2.0f * PI * i / segment_u;

        for(int j = 0; j < segment_v; j++) {
            vertex_donat_geometris.v = 2.0f * PI * j / segment_v;
            float x = ((R + r * std::cos(vertex_donat_geometris.v)) * 
            std::cos(vertex_donat_geometris.u));
        };
    };

    return x;
}

vertex_donat_geometris Donat_Geometris::torus_y (
    float R,
    float r,
    vertex_donat_geometris segment_u,
    vertex_donat_geometris segment_v
) {
    for (int i = 0; i < segment_u; i++) {
        vertex_donat_geometris.u = 2.0f * PI * i / segment_u;

        for (int j = 0; j < segment_v; j++) {
            vertex_donat_geometris.v = 2.0f * PI * j / segment_v;

            float y = ((R + r * std::cos(vertex_donat_geometris.v)) *
                    std::sin(vertex_donat_geometris.u));
        };
    };

    return y;
}

vertex_donat_geometris Donat_Geometris::torus_z (
    float r,
    vertex_donat_geometris segment_u,
    vertex_donat_geometris segment_v
) {

    for (int j = 0; j < segment_v; j++) {
        vertex_donat_geometris.v = 2.0f * PI * j / segment_v;

        float z = (r * std::sin(vertex_donat_geometris.v));
    };


    return z;
}

void Donat_Geometris::penggabungan_torus(
    float R,
    float r,
    vertex_donat_geometris segment_u,
    vertex_donat_geometris segment_v
) {
    vertex_donat_geometris bagian_x = torus_x(
        R, r, segment_u, segment_v
    );

    vertex_donat_geometris bagian_y = torus_y(
        R, r, segment_u, segment_v
    );

    vertex_donat_geometris bagian_Z = torus_z(
        r, segment_u, segment_v
    );

    vertices.push_back({bagian_x, bagian_y, bagian_Z});

    return vertices;
}