#include "../include/dragon.hpp"

Dragon::Dragon(int x, int y) : NPC(NPC_type::dragon, x, y, "dragon_" + std::to_string(id++)) {}

std::string Dragon::get_type() {
    return "Dragon";
}

int Dragon::get_damage_range() const {
    return 30;
}

bool Dragon::accept(std::shared_ptr<NPC> visitor) {
    if (visitor->fight(std::shared_ptr<Dragon>(this, [](Dragon *) {}))) {
        return true;
    }
    return false;
}

bool Dragon::fight(std::shared_ptr<Bull> accepter) {
    if (this->get_energy() > accepter->get_energy()) {
        notify_killed(accepter);
        accepter->must_die();
        return true;
    }
    return false;
}

bool Dragon::fight(std::shared_ptr<Dragon> accepter) {
    return false;
}

bool Dragon::fight(std::shared_ptr<Frog> accepter) {
    return false;
}

void Dragon::move(int max_x, int max_y) {
    std::lock_guard<std::shared_mutex> lck(_mutex);
    double angle = static_cast<double>(std::rand() % 100) / 100 * 2 * M_PI,
           dist = static_cast<double>(std::rand() % 100) / 100 * 50;

    int shift_x = static_cast<int>(dist * std::cos(angle)),
        shift_y = static_cast<int>(dist * std::sin(angle));

    if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
        _x += shift_x;
    if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
        _y += shift_y;
}
