#pragma once
#include "bull.hpp"
#include "dragon.hpp"
#include "npc.hpp"

class Frog : public NPC {
public:
    Frog(int x, int y);
    std::string get_type() override;
    int get_damage_range() const override;

    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<Bull> accepter) override;
    bool fight(std::shared_ptr<Dragon> accepter) override;
    bool fight(std::shared_ptr<Frog> accepter) override;

    void move(int max_x, int max_y) override;
};

// Frog::Frog(int x, int y) : NPC(NPC_type::Frog, x, y, "Frog_" + std::to_string(id++)) {}

// std::string Frog::get_type() {
//     return "Frog";
// }

// int Frog::get_damage_range() const {
//     return 5;
// }

// bool Frog::accept(std::shared_ptr<NPC> visitor) {
//     if (visitor->fight(std::shared_ptr<Frog>(this, [](Frog *) {}))) {
//         return true;
//     }
//     return false;
// }

// bool Frog::fight(std::shared_ptr<Bull> accepter) {
//     return false;
// }

// bool Frog::fight(std::shared_ptr<Dragon> accepter) {
//     return false;
// }

// bool Frog::fight(std::shared_ptr<Frog> accepter) {
//     if (this->get_energy() > accepter->get_energy()) {
//         accepter->must_die();
//         notify_killed(accepter);
//         return true;
//     }
//     return false;
// }

// void Frog::move(int max_x, int max_y) {
//     std::lock_guard<std::mutex> lck(_mutex);
//     std::srand(std::time(0));
//     int shift_x = std::rand() % 10 - 5,
//         shift_y = std::rand() % 10 - 5;

//     if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
//         _x += shift_x;
//     if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
//         _y += shift_y;
// }
