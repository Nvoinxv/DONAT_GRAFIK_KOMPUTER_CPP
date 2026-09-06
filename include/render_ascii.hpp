#ifndef RENDER_ASCII
#define RENDER_ASCII

#include <vector>
#include "membuat_geometrsi_donat.hpp"
#include "vektor_operasi.hpp"
#include <cmath>
#include <algorithm>

class render_ascii_objek {
    private:
    float skala;
    vector_3d a;
    vector_3d b;

    std::vector<std::vector<char>>& layar;
    vector_3d titik;

    Donat_Geometris();
    
    float delta_x;
    float delta_y;
    
    float turunan_x;
    float turunan_y;

    int panjang;
    int tinggi;

    public:
    render_ascii_objek();

    float projeksi_ortografi(vector_3d a, float skala);

    std::vector<float> digital_differential_analyzer(
    vector_3d a,
    vector_3d b);
    
    void gambar_titik (
        std::vector<std::vector<char>>& layar,
        vector_3d titik,
        int panjang,
        int tinggi
    );

    void gambar_garis(
        std::vector<std::vector<char>>& layar,
        vector_3d a,
        vector_3d b,
        int panjang,
        int lebar
    );

    void layar(
        Donat_Geometris& objek,
        const int panjang = 80,
        const int tinggi = 40,
        std::vector<std::vector<char>> layar
    )
};

#endif