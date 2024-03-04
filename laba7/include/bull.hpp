#pragma once
#include "dragon.hpp"
#include "npc.hpp"
#include "frog.hpp"

class Bull : public NPC {
public:
    Bull(int x, int y);
    std::string get_type() override;
    int get_damage_range() const override;

    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<Bull> accepter) override;
    bool fight(std::shared_ptr<Dragon> accepter) override;
    bool fight(std::shared_ptr<Frog> accepter) override;

    void move(int max_x, int max_y) override;
};

// Bull::Bull(int x, int y) : NPC(NPC_type::Bull, x, y, "Bull_" + std::to_string(id++)) {}

// std::string Bull::get_type() {
//     return "Bull";
// }

// int Bull::get_damage_range() const {
//     return 10;
// }

// bool Bull::accept(std::shared_ptr<NPC> visitor) {
//     if (visitor->fight(std::shared_ptr<Bull>(this, [](Bull *) {}))) {
//         return true;
//     }
//     return false;
// }

// bool Bull::fight(std::shared_ptr<Bull> accepter) {
//     return false;
// }

// bool Bull::fight(std::shared_ptr<Dragon> accepter) {
//     if (this->get_energy() > accepter->get_energy()) {
//         accepter->must_die();
//         notify_killed(accepter);
//         return true;
//     }
//     return false;
// }

// bool Bull::fight(std::shared_ptr<Frog> accepter) {
//     return false;
// }

// void Bull::move(int max_x, int max_y) {
//     std::lock_guard<std::mutex> lck(_mutex);
//     std::srand(std::time(0));
//     int shift_x = std::rand() % 60 - 30,
//         shift_y = std::rand() % 60 - 30;

//     if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
//         _x += shift_x;
//     if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
//         _y += shift_y;
// }
