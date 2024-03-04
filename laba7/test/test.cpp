#include "../googletest/googletest/include/gtest/gtest.h"
#include "../include/factory.hpp"
#include "../include/fight.hpp"
#include "bits/stdc++.h"

//_________________________________________________________________________________________________________________________
TEST(NPCFactoryTest, CreateNPC) {
    NPCFactory factory;
    bool test = true;
    try {
        std::shared_ptr<NPC> bull = factory.createNPC(NPC_type::bull, 1, 2);
        std::shared_ptr<NPC> dragon = factory.createNPC(NPC_type::dragon, 3, 4);
        std::shared_ptr<NPC> frog = factory.createNPC(NPC_type::frog, 5, 6);
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCFactoryTest, Save) {
    NPCFactory factory;
    set_t s;
    bool test = true;
    try {
        s.insert(factory.createNPC(NPC_type::bull, 1, 2));
        s.insert(factory.createNPC(NPC_type::dragon, 3, 4));
        s.insert(factory.createNPC(NPC_type::frog, 5, 6));
        factory.save(s, "test.txt");
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCFactoryTest, Load) {
    NPCFactory factory;
    set_t s;
    bool test = true;
    try {
        s = factory.load("test.txt");
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

TEST(NPCTest, OutputOperator) {
    std::shared_ptr<NPC> npc = std::make_shared<Bull>(1, 2);
    std::stringstream expected_output;
    expected_output << "bull_9 {x : 1, y : 2}";

    std::stringstream actual_output;
    actual_output << *npc.get();

    EXPECT_EQ(expected_output.str(), actual_output.str());
}

//_________________________________________________________________________________________________________________________
TEST(NPCTest, Getters) {
    NPCFactory factory;
    std::shared_ptr<NPC> bull = factory.createNPC(NPC_type::bull, 1, 2);
    std::shared_ptr<NPC> dragon = factory.createNPC(NPC_type::dragon, 3, 4);
    std::shared_ptr<NPC> frog = factory.createNPC(NPC_type::frog, 5, 6);

    EXPECT_EQ(bull->get_type(), "Bull");
    EXPECT_EQ(dragon->get_type(), "Dragon");
    EXPECT_EQ(frog->get_type(), "Frog");

    EXPECT_TRUE(bull->alive());
    EXPECT_TRUE(dragon->alive());
    EXPECT_TRUE(frog->alive());

    EXPECT_EQ(bull->get_x(), 1);
    EXPECT_EQ(dragon->get_x(), 3);
    EXPECT_EQ(frog->get_x(), 5);
    EXPECT_EQ(bull->get_y(), 2);
    EXPECT_EQ(dragon->get_y(), 4);
    EXPECT_EQ(frog->get_y(), 6);
}

TEST(NPCTest, Near) {
    NPCFactory factory;
    std::shared_ptr<NPC> bull = factory.createNPC(NPC_type::bull, 1, 1);
    std::shared_ptr<NPC> dragon = factory.createNPC(NPC_type::dragon, 50, 1);
    std::shared_ptr<NPC> frog = factory.createNPC(NPC_type::frog, 100, 1);

    EXPECT_FALSE(bull->near(dragon, 10));
    EXPECT_TRUE(bull->near(dragon, 60));
    EXPECT_FALSE(bull->near(frog, 90));
    EXPECT_TRUE(bull->near(frog, 110));
}

TEST(NPCTest, Attach) {
    NPCFactory factory;
    std::shared_ptr<NPC> bull = factory.createNPC(NPC_type::bull, 1, 1);
    std::shared_ptr<Observer> console_observer, file_observer;
    console_observer = std::make_shared<ConsoleObserver>();
    file_observer = std::make_shared<FileObserver>();
    bool test = true;
    try {
        bull->attach(console_observer);
        bull->attach(file_observer);
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

//_________________________________________________________________________________________________________________________
TEST(bullTest, ConstructorAndGetters) {
    Bull bull(1, 2);
    EXPECT_EQ(bull.get_x(), 1);
    EXPECT_EQ(bull.get_y(), 2);
    EXPECT_TRUE(bull.alive());
    EXPECT_EQ(bull.get_type(), "Bull");
}

TEST(bullTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> bull = factory.createNPC(NPC_type::bull, 1, 2);
    std::shared_ptr<NPC> frog = factory.createNPC(NPC_type::frog, 5, 6);

    EXPECT_FALSE(bull->accept(bull));
    EXPECT_FALSE(bull->accept(frog));
    EXPECT_TRUE(bull->alive());
}

//_________________________________________________________________________________________________________________________
TEST(dragonTest, ConstructorAndGetters) {
    Dragon dragon(1, 2);
    EXPECT_EQ(dragon.get_x(), 1);
    EXPECT_EQ(dragon.get_y(), 2);
    EXPECT_TRUE(dragon.alive());
    EXPECT_EQ(dragon.get_type(), "Dragon");
}

TEST(dragonTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> dragon = factory.createNPC(NPC_type::dragon, 3, 4);
    std::shared_ptr<NPC> frog = factory.createNPC(NPC_type::frog, 5, 6);

    EXPECT_FALSE(dragon->accept(dragon));
    EXPECT_FALSE(dragon->accept(frog));
    EXPECT_TRUE(dragon->alive());
}

//_________________________________________________________________________________________________________________________
TEST(frogTest, ConstructorAndGetters) {
    Frog frog(1, 2);
    EXPECT_EQ(frog.get_x(), 1);
    EXPECT_EQ(frog.get_y(), 2);
    EXPECT_TRUE(frog.alive());
    EXPECT_EQ(frog.get_type(), "Frog");
}

TEST(frogTest, Visitors) {
    NPCFactory factory;
    std::shared_ptr<NPC> bull = factory.createNPC(NPC_type::bull, 1, 2);
    std::shared_ptr<NPC> frog = factory.createNPC(NPC_type::frog, 5, 6);

    EXPECT_FALSE(frog->accept(bull));
    EXPECT_TRUE(frog->alive());
    remove("battle_stats.txt");
    remove("test.txt");
}

//_________________________________________________________________________________________________________________________
TEST(FightManagerTest, GetReturnsSingletonInstance) {
    FightManager& instance1 = FightManager::get();
    FightManager& instance2 = FightManager::get();

    EXPECT_EQ(&instance1, &instance2);
}

TEST(FightManagerTest, AddEventAddsEventToQueue) {
    FightManager& manager = FightManager::get();
    FightEvent event;

    bool test = true;
    try {
        manager.add_event(std::move(event));
    } catch (...) {
        test = false;
    }
    EXPECT_TRUE(test);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
