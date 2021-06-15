#pragma once

#include "MovePlayerUpCommand.h"
#include "MovePlayerLeftCommand.h"
#include "MovePlayerDownCommand.h"
#include "MovePlayerRightCommand.h"
#include "EndLevelCommand.h"
#include "StartLevelCommand.h"
#include "LoadLevelCommand.h"
#include "SaveLevelCommand.h"

class GameSettings;
class GameCommands {
public:
    GameCommands();
    ~GameCommands();
    enum GameCommandName {
        StartLevel,
        LoadLevel,
        SaveLevel,
        EndLevel,
        MovePlayerUp,
        MovePlayerLeft,
        MovePlayerDown,
        MovePlayerRight
    };
    void execute(GameCommandName name);
    bool game_over() const;
private:
    MovePlayerUpCommand* move_player_up_command;
    MovePlayerLeftCommand* move_player_left_command;
    MovePlayerDownCommand* move_player_down_command;
    MovePlayerRightCommand* move_player_right_command;
    EndLevelCommand* end_game_command;
    StartLevelCommand* start_game_command;
    LoadLevelCommand* load_game_command;
    SaveLevelCommand* save_game_command;
    bool is_game_over = false;
};
