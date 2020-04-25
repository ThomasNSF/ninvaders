#pragma once

#include "Aliens.h"
#include "UFO.h"
#include "Player.h"

class GameTable: public Singleton<GameTable>
{
    SINGLETON(GameTable);
public:
    typedef std::shared_ptr<GameTable> ptr_t;

public:
    Player* getPlayer();
    Aliens* getAliens();
    UFO*    getUFO();

public:
    bool playerHitCheck(int x, int y);
    bool bunkersHitCheck(int x, int y);

    bool hitCheck(Player* player);
    void calculateScore(int type);

private:
    bool hitCheck();
    bool handleHit();
    void handleUFO();

public:
    /*
     * @brief Default constructor
     */
    GameTable();

    /*
     * @brief Destructor
     */
    ~GameTable();

private:
    /*
     * @brief Copy constructor
     */
    GameTable (const GameTable&) = delete;

    /*
     * @brief Copy assignment operator
     */
    GameTable& operator=(const GameTable&) = delete;


private:
    UFO*    m_ufo;
    Player* m_player;
    Aliens* m_aliens;

    UIManager::ptr_t    m_uiMgr;
    ConfigurationManager::ptr_t m_confMgr;
};
