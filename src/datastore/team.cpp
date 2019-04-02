#include "team.hpp"

/* Static variables */
int Team::nextId = 0;

/**
 * Constructs a team given a name and league. The ID of this team
 * will be set to @a nextId, then @a nextId is incremented after.
 * The stadium ID is set to -1 to indicate that the team is not
 * in a stadium yet.
 *
 * @param name Team name
 * @param leag Team's league
 */
Team::Team(const std::string& name, League leag)
    : league(leag), m_id(nextId), m_name(name)
{
    nextId++;
}

int Team::getId() const
{
    return m_id;
}

int Team::getStadiumId() const
{
    return m_stadiumId;
}

std::string Team::getName() const
{
    return m_name;
}

/**
 * Sets the team name only if the given string is not empty.
 * @param name Team name
 */
void Team::setName(const std::string& name)
{
    if(!name.empty()) { m_name = name; }
}

/**
 * Sets the stadium ID only of the given ID is non-negative.
 * @param id Team ID
 */
void Team::setStadiumId(int id)
{
    if(id >= 0) { m_id = id; }
}
