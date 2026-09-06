#include "include/render_ascii.hpp"
#include "include/membuat_geometris_donat.hpp"
#include <chrono>
#include <thread>

int main() {
    render_ascii render;
    Donat_Geometris donat;

    while (true) {
        std::cout << "\033[2J\033[H"; 
        donat.rotasi(2);
        render.layar(donat);
        std::this_thread::sleep_for(std::chrono::miliseconds(5));
    }
}