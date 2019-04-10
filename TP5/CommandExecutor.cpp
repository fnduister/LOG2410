#include "CommandExecutor.h"

CommandExecutor & CommandExecutor::getInstance(void)
{
	static CommandExecutor m_instance;
	return m_instance;
}

void CommandExecutor::addCommand(const std::shared_ptr<AbsCommand>& c)
{
	// Ajouter la commande a la liste des commandes
	// A COMPLETER...
	m_commandList.push_back(c);
}

void CommandExecutor::executeAllCommands(AbsAudioFile& f)
{
	// Executer toutes les commandes dans la liste de commandes
	// A COMPLETER...
	for (std::shared_ptr<AbsCommand> command : m_commandList) {
		command->execute(f);
	}
}

void CommandExecutor::clearAllCommands(void)
{
	// Vider la liste des commandes
	// A COMPLETER...
	m_commandList.clear();
}
