#ifndef COMMAND_H
#define COMMAND_H

typedef struct command_st command_t;

struct command_st
{
	void (*execute)(command_t* command_obj);
};

static inline void Command_Execute(command_t *command)
{
	if (command && command->execute)
		command->execute(command);
}
#endif