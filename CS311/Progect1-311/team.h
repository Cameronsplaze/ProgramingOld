#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include <iostream>
#include <string>
using std::string;

using namespace std; // <--Remove later

class Team
{
public:
    Team();
    Team(string newName, int newWins);

    void setName(string newName);
    void setWins (int newWins);

    string getName();
    int getWins();

    string getName() const;
    int getWins() const;

    string toString();
    string toString() const;



    Team & operator++(int a);
    Team & operator--(int a);

    Team & operator++();
    Team & operator--();


        //copied from timesec.h
        ~Team() = default;
        Team(const Team &) = default;
        Team(Team && ) = default;
        Team & operator=(const Team &) = default;
        Team & operator=(Team &&) = default;
        //end copy


    //Team & operator= (Team &&);
private:
    string teamName_;
    int teamWins_;
};
ostream & operator<<(ostream & out, const Team & t);
bool operator==(const Team & a, const Team & b);
bool operator!=(const Team & a, const Team & b);



#endif // TEAM_H_INCLUDED
