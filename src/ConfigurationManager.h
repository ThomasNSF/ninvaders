#pragma once

#include "common.h"

/**
 * @class ConfigurationManager
 * @file  ConfigurationManager.h
 * @brief this class is designed to keep game specific configurations
 * @author Levon ghukasyan
 */

class ConfigurationManager: public Singleton<ConfigurationManager>
{
    SINGLETON(ConfigurationManager);

public:
    static const int DEFAULT_MAX_LIVES = 3;

    typedef std::shared_ptr<ConfigurationManager> ptr_t;

    void reset()
    {
        m_weite      = 0;
        m_score      = 0;
        m_live       = m_maxLives;
        m_level      = 0;
        m_skillLevel = 1;
    }

    inline const int& getWeite() const
    {
        return m_weite;
    }

    void updateWeite()
    {
        m_weite = (m_numships +(m_skillLevel * 10) - (m_level * 5) + 5) / 10;
        if (m_weite < 0) {
            m_weite = 0;
        }
    }

    ///@brief skill level set/get
    ///{
public:
    inline const int& getSkillLevel() const
    {
        return m_skillLevel;
    }

    void setSkillLevel(int level)
    {
        m_skillLevel = level;
    }
    ///}

    ///@brief ship number set/get
    ///{
public:
    inline const int& getNumShip() const
    {
        return m_numships;
    }

    void setNumShip(int num)
    {
        m_numships = num;
    }

    ///@brief level set/get
    ///{
public:
    inline const int& getLevel() const
    {
        return m_level;
    }

    void setLevel(int level)
    {
        m_level = level;
    }
    ///}

    ///@brief score set/get
    ///{
public:
    inline const int& getScore() const
    {
        return m_score;
    }

    void setScore(int score)
    {
        m_score = score;
    }
    ///}

    ///@brief live set/get
    ///{
public:
    inline const int& getLive() const
    {
        return m_live;
    }

    inline void setLive(int live)
    {
        m_live = live;
    }

    inline void resetLive()
    {
        m_live = m_maxLives;
    }
    ///}

    ///@brief mode set/get
    ///{
public:
    inline const Mode& getMode() const
    {
        return m_mode;
    }

    inline void setMode(Mode mode)
    {
        m_mode = mode;
    }
    ///}
    
public:
    /**
     * @brief Default constructor
     */
    ConfigurationManager():
        m_numships(0),
        m_weite(0),
        m_level(0),
        m_skillLevel(0),
        m_score(0),
        m_live(DEFAULT_MAX_LIVES),
        m_maxLives(DEFAULT_MAX_LIVES),
        m_mode(Mode::PAUSE)
    {}

    ~ConfigurationManager();
private:
    /**
     * @brief Copy constructor
     */
    ConfigurationManager (const ConfigurationManager&) = delete;

    /**
     * @brief Copy assignment operator
     */
    ConfigurationManager& operator=(const ConfigurationManager&) = delete;

    /**
     * @brief Destructor
     */


private:
    int  m_numships;
    int  m_weite;
    int  m_level;
    int  m_skillLevel;
    int  m_score;
    int  m_live;
    int  m_maxLives;
    Mode m_mode;
};
