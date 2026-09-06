#include "render_ascii.hpp"

render_ascii_objek::render_ascii_objek() :
skala(10.0f), a(), b(), layar(), titik(),
panjang(0), tinggi(0), delta_x(0.0f),
delta_y(0.0f),
turunan_y(0.0f), turunan_x(0.0f),
Donat_Geometris()
{
    // kosong
}

float render_ascii_objek::projeksi_ortografi(
    vector_3d a, float skala = 10.0f
) {
    float layar_x = 2.0f * (a.x - 0.5f * a.z) * skala;
    float layar_y = (a.y - 0.25f * a.z) * skala;

    return {layar_x, layar_y};
}

std::vector<float> render_ascii::digital_differential_analyzer(
    vector_3d a, vector_3d b
) {
    delta_x = a.x - b.x;
    delta_y = a.y - b.y;

    float jumlah_langkah = std::max(
        std::abs(delta_x, delta_y)
    );

    turunan_x = delta_x / jumlah_langkah;
    turunan_y = delta_y / jumlah_langkah;

    for (int i = 0; i < a.x; i++) {
        a.x[i + 1] = a.x[i] + turunan_x;
        b.x[i + 1] = b.x[i] + turunan_x;
    }

    for (int j = 0; j < a.y; j++) {
        a.y[j+1] = a.y[i] + turunan_y;
        b.y[j + 1] = b.y[i] + turunan_y;
    }
   
    float pixel = std::round(
        a.x, a.y, b.x, b.y
    );

    return pixel;
}

void render_ascii::gambar_titik (
    std::vector<std::vector<char>>& layar,
    vector_3d titik,
    int panjang,
    int tinggi
) {
    int x = panjang / 2 + static_cast<int>(titik.x);
    int y = tinggi / 2 + static_cast<int>(titik.y);

    if (x >= 0 && x < panjang && y >= 0 && y < lebar) {
        layar[y][x] = '*';
    }

    return layar;
}

void render_ascii::gambar_garis (
    std::vector<std::vector<char>>& layar,
    vector_3d a,
    vector_3d b,
    int panjang, 
    int tinggi
) {
    std::vector<float> titik_garis = digital_differential_analyzer(
        a, b
    );

    for (auto& titik : titik_garis) {
        gambar_titik(
            layar,
            titik,
            panjang,
            tinggi
        );
    }
}

void layar()