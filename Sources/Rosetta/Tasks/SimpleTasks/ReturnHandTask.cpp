// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#include <Rosetta/Actions/Generic.hpp>
#include <Rosetta/Tasks/SimpleTasks/IncludeTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/ReturnHandTask.hpp>
#include <Rosetta/Zones/FieldZone.hpp>

namespace RosettaStone::SimpleTasks
{
ReturnHandTask::ReturnHandTask(EntityType entityType) : ITask(entityType)
{
    // Do nothing
}

TaskStatus ReturnHandTask::Impl(Player* player)
{
    auto entities =
        IncludeTask::GetEntities(m_entityType, player, m_source, m_target);

    for (auto& entity : entities)
    {
        entity->player->GetFieldZone()->Remove(entity);
        entity->Reset();
        Generic::AddCardToHand(entity->player, entity);
    }

    return TaskStatus::COMPLETE;
}

ITask* ReturnHandTask::CloneImpl()
{
    return new ReturnHandTask(m_entityType);
}
}  // namespace RosettaStone::SimpleTasks
