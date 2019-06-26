// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

// It is based on peter1591's hearthstone-ai repository.
// References: https://github.com/peter1591/hearthstone-ai

#ifndef ROSETTASTONE_TORCH_MCTS_IPOLICY_HPP
#define ROSETTASTONE_TORCH_MCTS_IPOLICY_HPP

#include <Rosetta/Actions/ActionType.hpp>

#include <vector>

namespace RosettaTorch::MCTS
{
//!
//! \brief IPolicy class.
//!
class IPolicy
{
 public:
    virtual ~IPolicy() = default;

    virtual int SelectChoice(RosettaStone::ActionType actionType,
                             const std::vector<int>& choices) = 0;
};
}  // namespace RosettaTorch::MCTS

#endif  // ROSETTASTONE_TORCH_MCTS_IPOLICY_HPP