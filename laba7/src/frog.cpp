#include "../include/frog.hpp"

Frog::Frog(int x, int y) : NPC(NPC_type::frog, x, y, "frog_" + std::to_string(id++)) {}

std::string Frog::get_type() {
    return "Frog";
}

int Frog::get_damage_range() const {
    return 10;
}

bool Frog::accept(std::shared_ptr<NPC> visitor) {
    if (visitor->fight(std::shared_ptr<Frog>(this, [](Frog *) {}))) {
        return true;
    }
    return false;
}

bool Frog::fight(std::shared_ptr<Bull> accepter) {
    return false;
}

bool Frog::fight(std::shared_ptr<Dragon> accepter) {
    return false;
}

bool Frog::fight(std::shared_ptr<Frog> accepter) {
    return false;
}

void Frog::move(int max_x, int max_y) {
    std::lock_guard<std::shared_mutex> lck(_mutex);
    double angle = static_cast<double>(std::rand() % 100) / 100 * 2 * M_PI,
           dist = static_cast<double>(std::rand() % 100) / 100 * 1;

    int shift_x = static_cast<int>(dist * std::cos(angle)),
        shift_y = static_cast<int>(dist * std::sin(angle));

    if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
        _x += shift_x;
    if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
        _y += shift_y;
}
