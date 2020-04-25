#include <iostream>
#include <stdexcept>

#include "GameManager.h"
#include "UIManager.h"

namespace {

void createSingletones()
{
    GameManager::instance().initialize();
    UIManager::instance();
}

void removeSingletones()
{
    GameManager::removeInstance();
    UIManager::removeInstance();
}

}

int main(int argc, char** argv)
{
    try {
        createSingletones();
        GameManager::ptr_t gameMgr = GameManager::getInstance();
        if (!gameMgr->setup(argc, argv))
            return 0;

        do {
            gameMgr->readInput();
        } while (true);
        removeSingletones();

    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        removeSingletones();
    } catch (...) {
        removeSingletones();
        std::exit(0);
    }

    return 0;
}
