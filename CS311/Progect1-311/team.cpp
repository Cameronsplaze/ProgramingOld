    #include "team.h"

    Team::Team()
    {
        teamName_ = "";
        teamWins_ = 0;
    }
    Team::Team(string newName, int newWins)
    {
        teamName_ = newName;
        teamWins_ = newWins;
    }




    void Team::setName(string newName)
    {
        teamName_ = newName;
    }
    void Team::setWins (int newWins)
    {
        teamWins_ = newWins;
    }
    string Team::getName()
    {
        return teamName_;
    }
    int Team::getWins()
    {
        return teamWins_;
    }

    string Team::getTeamName() const
    {
        return teamName_;
    }
    int Team::getTeamWins() const
    {
        return teamWins_;
    }

    string Team::toString()
    {
        return "x";
    }


    Team & Team::operator++(int addSome)
    {
        return *this;
    }
    Team & Team::operator--(subSome)
    {
        return *this;
    }
    Team & Team::operator++()
    {
        return *this;
    }
    Team & Team::operator--()
    {
        return *this;
    }

    ostream & operator<< (ostream & lhs, const Team & rhs)
    {
        return lhs;
    }
    bool operator==(const Team & a, const Team & b)
    {
        return true;
    }
    bool operator!=(const Team & a, const Team & b)
    {
        return !(a==b);
    }
    Team & Team::operator=(Team&&) = default;
