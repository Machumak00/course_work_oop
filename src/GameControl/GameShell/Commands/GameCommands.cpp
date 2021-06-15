#include "GameCommands.h"

GameCommands::GameCommands() {
    move_player_up_command = new MovePlayerUpCommand;
    move_player_left_command = new MovePlayerLeftCommand;
    move_player_down_command = new MovePlayerDownCommand;
    move_player_right_command = new MovePlayerRightCommand;
    end_game_command = new EndLevelCommand;
    start_game_command = new StartLevelCommand;
    load_game_command = new LoadLevelCommand;
    save_game_command = new SaveLevelCommand;
}

GameCommands::~GameCommands() {
    delete move_player_up_command;
    delete move_player_left_command;
    delete move_player_down_command;
    delete move_player_right_command;
    delete end_game_command;
    delete start_game_command;
    delete load_game_command;
    delete save_game_command;
}

void GameCommands::execute(GameCommands::GameCommandName name) {
    if (name == StartLevel)
        start_game_command->execute();
    else if (name == LoadLevel)
        load_game_command->execute();
    else if (name == SaveLevel)
        save_game_command->execute();
    else if (name == MovePlayerUp)
        move_player_up_command->execute();
    else if (name == MovePlayerLeft)
        move_player_left_command->execute();
    else if (name == MovePlayerDown)
        move_player_down_command->execute();
    else if (name == MovePlayerRight)
        move_player_right_command->execute();
    else if (name == EndLevel) {
        end_game_command->execute();
        is_game_over = end_game_command->game_is_over();
    }
}

bool GameCommands::game_over() const {
    return is_game_over;
}
