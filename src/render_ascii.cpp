#include "render_ascii.hpp"

render_ascii_objek::render_ascii_objek() :
skala(10.0f),
a(),
b(),
titik(),
delta_x(0.0f),
delta_y(0.0f),
turunan_y(0.0f),
turunan_x(0.0f),
panjang(0),
tinggi(0)
{
    // kosong
}


vektor_3d render_ascii_objek::projeksi_ortografi(
    vektor_3d a,
    float skala
) {
    float layar_x =
        2.0f *
        (a.x - 0.5f * a.z) *
        skala;

    float layar_y =
        (a.y - 0.25f * a.z) *
        skala;

    return {
        layar_x,
        layar_y,
        a.z
    };
}


std::vector<vektor_3d>
render_ascii_objek::digital_differential_analyzer(
    vektor_3d a,
    vektor_3d b
) {
    std::vector<vektor_3d> titik_garis;

    delta_x = b.x - a.x;
    delta_y = b.y - a.y;

    float jumlah_langkah =
        std::max(
            std::abs(delta_x),
            std::abs(delta_y)
        );

    if (jumlah_langkah == 0.0f) {
        titik_garis.push_back(a);
        return titik_garis;
    }

    turunan_x =
        delta_x / jumlah_langkah;

    turunan_y =
        delta_y / jumlah_langkah;

    float x = a.x;
    float y = a.y;

    for (
        int i = 0;
        i <= static_cast<int>(jumlah_langkah);
        i++
    ) {
        titik_garis.push_back({
            x,
            y,
            a.z + (b.z - a.z) *
            (i / jumlah_langkah)
        });

        x += turunan_x;
        y += turunan_y;
    }

    return titik_garis;
}


float render_ascii_objek::kedalaman_titik(
    vektor_3d titik
) {
    return titik.z;
}


char render_ascii_objek::karakter_kedalaman(
    float kedalaman
) {
    const char karakter[] =
        ".:-=+*#%@";

    float nilai =
        (kedalaman + 10.0f) / 20.0f;

    nilai =
        std::max(
            0.0f,
            std::min(
                1.0f,
                nilai
            )
        );

    int indeks =
        static_cast<int>(
            nilai * 8.0f
        );

    return karakter[indeks];
}


void render_ascii_objek::gambar_titik(
    std::vector<std::vector<char>>& layar,
    vektor_3d titik,
    int panjang,
    int tinggi
) {
    int x =
        panjang / 2 +
        static_cast<int>(titik.x);

    int y =
        tinggi / 2 -
        static_cast<int>(titik.y);

    if (
        x >= 0 &&
        x < panjang &&
        y >= 0 &&
        y < tinggi
    ) {
        layar[y][x] =
            karakter_kedalaman(
                kedalaman_titik(titik)
            );
    }
}


void render_ascii_objek::gambar_garis(
    std::vector<std::vector<char>>& layar,
    vektor_3d a,
    vektor_3d b,
    int panjang,
    int tinggi
) {
    std::vector<vektor_3d> titik_garis =
        digital_differential_analyzer(
            a,
            b
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


void render_ascii_objek::layar(
    Donat_Geometris& objek,
    const int panjang,
    const int tinggi
) {
    std::vector<std::vector<char>> layar(
        tinggi,
        std::vector<char>(
            panjang,
            ' '
        )
    );

    const auto& vertices =
        objek.mendapatkan_vertices();

    int segment_u =
        objek.mendapatkan_segment_u();

    int segment_v =
        objek.mendapatkan_segment_v();

    for (int i = 0; i < segment_u; i++) {

        for (int j = 0; j < segment_v; j++) {

            int titik_sekarang =
                i * segment_v + j;

            int titik_v =
                i * segment_v +
                ((j + 1) % segment_v);

            int titik_u =
                ((i + 1) % segment_u) *
                segment_v + j;

            vektor_3d a =
                projeksi_ortografi(
                    vertices[titik_sekarang],
                    skala
                );

            vektor_3d b =
                projeksi_ortografi(
                    vertices[titik_v],
                    skala
                );

            vektor_3d c =
                projeksi_ortografi(
                    vertices[titik_u],
                    skala
                );

            gambar_garis(
                layar,
                a,
                b,
                panjang,
                tinggi
            );

            gambar_garis(
                layar,
                a,
                c,
                panjang,
                tinggi
            );
        }
    }

    for (auto& baris : layar) {
        for (auto& karakter : baris) {
            std::cout << karakter;
        }

        std::cout << '\n';
    }
}