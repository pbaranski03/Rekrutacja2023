#include "../include/AGHRacingTeam.h"
#include <algorithm>
#include <unordered_map>

AGHRacingTeam::AGHRacingTeam(std::vector<Member> MEMBER)
{
    int i;
    for (i = 0; i < MEMBER.size(); i++)
    {
        if (MEMBER[i].height >= 100 && MEMBER[i].height <= 250 && MEMBER[i].name.size() <= 20 && MEMBER[i].yearOfJoining >= 2000 && MEMBER[i].yearOfJoining <= 2023)
        {
            members.push_back(MEMBER[i]);
        }
    }
}
AGHRacingTeam::AGHRacingTeam(AGHRacingTeam& ORIGIN)
{
    members = ORIGIN.members;
}

void AGHRacingTeam::addMember(std::string name, int height, int yearOfJoining)
{
    if (height >= 100 && height <= 250 && name.size() <= 20 && yearOfJoining >= 2000 && yearOfJoining <= 2023)
    {
        Member newMember(name, height, yearOfJoining);
        members.push_back(newMember);
    }
}
bool compareHeights(Member A, Member B)
{
    return(A.height < B.height);
}

std::vector<std::string> AGHRacingTeam::getMembersSortedByHeightAsc()
{

    sort(members.begin(), members.end(), compareHeights);
    std::vector<std::string> namesOfMembers;
    int i;
    for (i = 0; i < members.size(); i++)
    {
        namesOfMembers.push_back(members[i].name);
    }
    return namesOfMembers;
}

int AGHRacingTeam::getNumberOfMembersWhoJoinedInLeapYear()
{
    int numberOfMembers = 0;
    int i;
    for (i = 0; i < members.size(); i++)
    {
        if ((members[i].yearOfJoining % 4 == 0 && members[i].yearOfJoining % 100 != 0) || members[i].yearOfJoining % 400 == 0)
        {
            numberOfMembers++;
        }
    }
    return numberOfMembers;
}

int AGHRacingTeam::getMaxNumberOfJoinedInTheSameYear()
{
    std::unordered_map <int, int> yearsAndFrequenciesMap;
    int maxCounter = 0;
    int i;
    for (i = 0; i < members.size(); i++)
    {
        yearsAndFrequenciesMap[members[i].yearOfJoining]++;
    }
    for (auto i : yearsAndFrequenciesMap)
    {
        if (maxCounter < i.second)
        {
            maxCounter = i.second;
        }
    }
    return maxCounter;
}

