// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Rosetta/Cards/CardDefs.hpp>
#include <Rosetta/Loaders/InternalCardLoader.hpp>

namespace RosettaStone
{
void InternalCardLoader::Load(std::vector<Card*>& cards)
{
    for (auto& card : cards)
    {
        const auto cardDef =
            CardDefs::GetInstance().FindCardDefByCardID(card->id);

        card->power = cardDef.power;
        card->playRequirements = cardDef.playReqs;
        card->chooseCardIDs = cardDef.chooseCardIDs;
        card->entourages = cardDef.entourages;
        card->gameTags[GameTag::QUEST_PROGRESS_TOTAL] =
            cardDef.questProgressTotal;
        card->gameTags[GameTag::HERO_POWER] = cardDef.heroPowerDbfID;

        // NOTE: Load some game tag data
        // Scheme series
        // Rafaam's Scheme (DAL_007)
        // Dr. Boom's Scheme (DAL_008)
        // Hagatha's Scheme (DAL_009)
        // Togwaggle's Scheme (DAL_010)
        // Lazul's Scheme (DAL_011)
        if (card->dbfID == 51371 || card->dbfID == 51372 ||
            card->dbfID == 51373 || card->dbfID == 51375 ||
            card->dbfID == 51376)
        {
            card->gameTags[GameTag::TAG_SCRIPT_DATA_NUM_1] = 1;
        }

        // Crystal Stag (DAL_799)
        if (card->dbfID == 53179)
        {
            card->gameTags[GameTag::PLAYER_TAG_THRESHOLD_TAG_ID] = 958;
            card->gameTags[GameTag::PLAYER_TAG_THRESHOLD_VALUE] = 5;
        }
    }
}
}  // namespace RosettaStone
