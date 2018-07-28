#ifndef UNIT_TEST_TEST_TASKS_H
#define UNIT_TEST_TEST_TASKS_H

#include <Enums/TaskEnums.h>
#include <Managers/Player.h>
#include <Tasks/MetaData.h>
#include <Tasks/Tasks.h>

#include <functional>

using namespace Hearthstonepp;

class TestTask : public ITask
{
public:
	TestTask(TaskID id, std::function<MetaData(Player &, Player &)> &&impl);
	
	TaskID GetTaskID() const override;

private:
	TaskID m_id;
	std::function<MetaData(Player &, Player &)> m_impl;

	MetaData Impl(Player &player1, Player &player2) const override;
};


#endif  // UNITTEST_TEST_TASKS_H