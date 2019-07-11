// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef ROSETTASTONE_HERO_POWER_HPP
#define ROSETTASTONE_HERO_POWER_HPP

#include <Rosetta/Models/Entity.hpp>

namespace RosettaStone
{
//!
//! \brief HeroPower class.
//!
//! This class inherits from Entity structure.
//!
class HeroPower : public Entity
{
 public:
    //! Default constructor.
    HeroPower() = default;

    //! Constructs hero power with given \p _owner, \p _card and \p tags.
    //! \param _owner The owner of the card.
    //! \param _card The card.
    //! \param tags The game tags.
    HeroPower(Player& _owner, Card* _card, std::map<GameTag, int> tags);

    //! Default destructor.
    ~HeroPower() = default;

    //! Default copy constructor.
    HeroPower(const HeroPower& power) = default;

    //! Default move constructor.
    HeroPower(HeroPower&& power) = default;

    //! Default copy assignment operator.
    HeroPower& operator=(const HeroPower& power) = default;

    //! Default move assignment operator.
    HeroPower& operator=(HeroPower&& power) = default;
};
}  // namespace RosettaStone

#endif  // ROSETTASTONE_HERO_POWER_HPP
