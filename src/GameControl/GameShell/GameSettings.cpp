#include "GameSettings.h"
#include "PlayerObserver.h"
#include "SpawnElementObserver.h"
#include "MeetElementObserver.h"
#include "GameOverObserver.h"
#include "LevelStartObserver.h"
#include "LogPublisher.h"
#include "Player.h"
#include "Field.h"
#include "Cell.h"
#include "FieldIterator.h"
#include "GameState.h"
#include "SaveFile.h"
#include "LoadFile.h"
#include "Snapshot.h"
#include "SaveException.h"
#include "LoadException.h"
#include "WrongInformationException.h"

GameSettings::GameSettings() {
    observers[0] = new PlayerObserver;
    observers[1] = new SpawnElementObserver;
    observers[2] = new MeetElementObserver;
    observers[3] = new GameOverObserver;
    observers[4] = new LevelStartObserver;
    log_publisher = new LogPublisher;
    player = new Player;
    is_game_over = false;
    game_state = nullptr;
    snapshot = nullptr;
}

void GameSettings::start_level() {
    Field::get_field()->get_cell(0, 0).set_player_on_cell(player);
    attach_observers();
    log_publisher->Notify(LogPublisher:: LevelStart, "Начало нового уровня.");
    log_publisher->Detach(observers[4]);
    log_spawn_game_objects();
    log_publisher->Detach(observers[1]);
}

void GameSettings::end_level() {
    if (player->get_position() == std::pair<int, int>(14, 14)){
        if (player->get_score() >= 30) {
            log_publisher->Notify(LogPublisher::GameOverInfo, "Игрок собрал нужное количество очков и достиг выхода. Конец уровня.");
            is_game_over = true;
        }
        else {
            log_publisher->Notify(LogPublisher::GameOverInfo, "Игроку не удалось собрать нужное количество очков. Конец уровня.");
            is_game_over = true;
        }
    }
    if (player->is_player_died()){
        log_publisher->Notify(LogPublisher::GameOverInfo, "Игрок погиб. Конец уровня.");
        is_game_over = true;
    }
}

void GameSettings::attach_observers() {
    log_publisher->Attach(observers[0], LogPublisher::PlayerInfo);
    log_publisher->Attach(observers[1], LogPublisher::SpawnElementInfo);
    log_publisher->Attach(observers[2], LogPublisher::MeetElementInfo);
    log_publisher->Attach(observers[3], LogPublisher::GameOverInfo);
    log_publisher->Attach(observers[4], LogPublisher::LevelStart);
}

void GameSettings::update_player() {
    Cell* cell = &Field::get_field()->get_cell(player->get_position().first, player->get_position().second);
    cell->set_player_on_cell(player);
    if (cell->get_object() != nullptr) {
        std::stringstream st;
        st << *cell->get_object();
        log_publisher->Notify(LogPublisher::MeetElementInfo, st.str());
        *player = *player + *cell->get_object();
    }
    std::stringstream st;
    st << *player;
    log_publisher->Notify(LogPublisher::PlayerInfo, st.str());
    player->clear_use_element_string();
}

void GameSettings::log_spawn_game_objects() {
    FieldIterator field_it;
    for(field_it.entry(); !field_it.isEnd(); field_it.next()) {
        if (field_it.getElem()->get_object() != nullptr) {
            std::stringstream st;
            st << *field_it.getElem()->get_object();
            log_publisher->Notify(LogPublisher::SpawnElementInfo, st.str());
        }
    }
    if (field_it.getElem()->get_object() != nullptr) {
        std::stringstream st;
        st << *field_it.getElem()->get_object();
        log_publisher->Notify(LogPublisher::SpawnElementInfo, st.str());
    }
}

bool GameSettings::game_over() const {
    return is_game_over;
}

GameSettings* GameSettings::game_settings_ptr = nullptr;

GameSettings* GameSettings::get_instance() {
    if (game_settings_ptr == nullptr)
        game_settings_ptr = new GameSettings;
    return game_settings_ptr;
}

void GameSettings::delete_instance() {
    if (game_settings_ptr != nullptr) {
        delete game_settings_ptr;
        game_settings_ptr = nullptr;
    }
}

GameSettings::~GameSettings() {
    for (auto observer : observers)
        delete observer;
    delete player;
    delete log_publisher;
    Field::get_field()->delete_field();
}

void GameSettings::change_state(GameState* new_game_state) {
    if (game_state != nullptr)
        delete game_state;
    game_state = new_game_state;
}

void GameSettings::move_player() {
    game_state->actionPlayer();
}

void GameSettings::move_enemy() {
    game_state->actionEnemy();
}

sf::Keyboard::Key GameSettings::get_button() const {
    return button;
}

void GameSettings::set_button(sf::Keyboard::Key new_button) {
    button = new_button;
}

Player *GameSettings::get_player() const {
    return player;
}

void GameSettings::action_player_and_enemy() {
    Field* field = Field::get_field();
    if(field->get_cell(player->get_position().first, player->get_position().second).is_enemy_on_cell()){
        if(field->get_cell(player->get_position().first, player->get_position().second).is_enemy_damage_on_cell())
            *player - field->get_cell(player->get_position().first, player->get_position().second).get_enemy_damage();
        if(field->get_cell(player->get_position().first, player->get_position().second).is_enemy_scorepoint_on_cell())
            *player - field->get_cell(player->get_position().first, player->get_position().second).get_enemy_scorepoint();
        if(field->get_cell(player->get_position().first, player->get_position().second).is_enemy_teleport_on_cell())
            *player - field->get_cell(player->get_position().first, player->get_position().second).get_enemy_teleport();
    }
}

void GameSettings::clear_field() {
    Field::get_field()->delete_field();
    player->reset();
    is_game_over = false;
}

void GameSettings::load_level() {
    try{
        LoadFile file;
        *snapshot = file.load_file();
    }
    catch(std::bad_alloc &exc) {
        std::cout<<exc.what();
        exit(0);
    }
    catch(LoadException &exc) {
        std::cout << exc.get_error() << std::endl;
        return;
    }
    catch(WrongInformationException &exception) {
        std::cout << exception.get_error() << std::endl;
        return;
    }
    snapshot->restore();
    update_player();
}

void GameSettings::save_level() {
    create_snapshot();
    try {
        SaveFile file;
        file.save_file(*snapshot);
    }
    catch(std::bad_alloc &exception) {
        std::cout << exception.what() << std::endl;
        exit(0);
    }
    catch(SaveException &exception) {
        std::cout << exception.get_error() << std::endl;
    }
}

void GameSettings::create_snapshot() {
    std::vector<std::pair<int ,int>> bomb_elements;
    std::vector<std::pair<int ,int>> health_elements;
    std::vector<std::pair<int ,int>> scorepoint_elements;

    std::vector<std::pair<int ,int>> damage_enemies;
    std::vector<std::pair<int ,int>> teleport_enemies;
    std::vector<std::pair<int ,int>> scorepoint_enemies;

    for(int i = 0; i < Field::get_field()->get_size(); ++i)
        for(int j = 0; j < Field::get_field()->get_size(); ++j) {
            if (Field::get_field()->get_cell(i, j).get_object() != nullptr) {
                if (Field::get_field()->get_cell(i, j).get_object()->get_type() == GameObject::Bomb)
                    bomb_elements.push_back(std::pair<int, int>(i, j));
                else if (Field::get_field()->get_cell(i, j).get_object()->get_type() == GameObject::Health)
                    health_elements.push_back(std::pair<int, int>(i, j));
                else if (Field::get_field()->get_cell(i, j).get_object()->get_type() == GameObject::ScorePoint)
                    scorepoint_elements.push_back(std::pair<int, int>(i, j));
            }
            if (Field::get_field()->get_cell(i, j).is_enemy_damage_on_cell())
                damage_enemies.push_back(std::pair<int, int>(i, j));
            else if (Field::get_field()->get_cell(i, j).is_enemy_scorepoint_on_cell())
                scorepoint_enemies.push_back(std::pair<int, int>(i, j));
            else if (Field::get_field()->get_cell(i, j).is_enemy_teleport_on_cell())
                teleport_enemies.push_back(std::pair<int, int>(i, j));
            }

    snapshot = new Snapshot(
            bomb_elements, health_elements, scorepoint_elements,
            damage_enemies, teleport_enemies, scorepoint_enemies,
            player->get_position(), player->get_score(), player->get_health());
    Field::get_field()->get_cell(player->get_position().first, player->get_position().second).set_player_on_cell(player);
}
