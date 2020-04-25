#pragma once

#include <boost/enable_shared_from_this.hpp>
#include "ConfigurationManager.h"
#include "GameTable.h"
#include "UIManager.h"
class Counter;

class GameManager: public Singleton<GameManager>,
    public std::enable_shared_from_this<GameManager>
{
    SINGLETON(GameManager);

public:
    typedef std::shared_ptr<GameManager> ptr_t;


    static void staticHandler(int)
    {
        instance().handleTimer();
    }

public:
    GameManager();
    ~GameManager();
    void initialize();
    bool setup(int argc, char** argv);

private:
    GameManager(const GameManager& other) = delete;
    GameManager(GameManager&& other) = delete;

    GameManager& operator=(const GameManager& other) = delete;
    GameManager& operator=(GameManager&& other) = delete;

public:
    void readInput();

private:
    void printInfo() const;
    void printVersion() const;
    void printUsage() const;

    bool parseCommandLine(int argc, char** argv);
    void setupTimer();
    void handleTimer();

private:
    void initLevel();
    void drawscore();

    void finish(int);

private:
    UIManager::ptr_t m_uiMgr;
    ConfigurationManager::ptr_t m_confMgr;
    GameTable::ptr_t m_gameTable;

    friend class Counter;
    Counter* m_counter;

};

