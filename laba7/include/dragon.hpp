#pragma once
#include "bull.hpp"
#include "npc.hpp"
#include "frog.hpp"

class Dragon : public NPC {
public:
    Dragon(int x, int y);
    std::string get_type() override;
    int get_damage_range() const override;

    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<Bull> accepter) override;
    bool fight(std::shared_ptr<Dragon> accepter) override;
    bool fight(std::shared_ptr<Frog> accepter) override;

    void move(int max_x, int max_y) override;
};

// Dragon::Dragon(int x, int y) : NPC(NPC_type::Dragon, x, y, "Dragon_" + std::to_string(id++)) {}

// std::string Dragon::get_type() {
//     return "Dragon";
// }

// int Dragon::get_damage_range() const {
//     return 10;
// }

// bool Dragon::accept(std::shared_ptr<NPC> visitor) {
//     if (visitor->fight(std::shared_ptr<Dragon>(this, [](Dragon *) {}))) {
//         return true;
//     }
//     return false;
// }

// bool Dragon::fight(std::shared_ptr<Bull> accepter) {
//     return false;
// }

// bool Dragon::fight(std::shared_ptr<Dragon> accepter) {
//     return false;
// }

// bool Dragon::fight(std::shared_ptr<Frog> accepter) {
//     if (this->get_energy() > accepter->get_energy()) {
//         accepter->must_die();
//         notify_killed(accepter);
//         return true;
//     }
//     return false;
// }

// void Dragon::move(int max_x, int max_y) {
//     std::lock_guard<std::mutex> lck(_mutex);
//     std::srand(std::time(0));
//     int shift_x = std::rand() % 20 - 10,
//         shift_y = std::rand() % 20 - 10;

//     if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
//         _x += shift_x;
//     if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
//         _y += shift_y;
// }
