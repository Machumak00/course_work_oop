#include "SaveFile.h"
#include "SaveException.h"
#include "Snapshot.h"

SaveFile::SaveFile() {
    file = new std::ofstream("Saves/SaveGame1");
    if (!file->is_open())
        throw SaveException("Не удалось открыть файл для сохранения!");
}

SaveFile::~SaveFile() {
    if (file != nullptr && file->is_open()) {
        file->close();
        if (file->is_open())
            throw SaveException("Не удалось закрыть файл сохранения!");
    }
    if (file != nullptr) {
        delete file;
        file = nullptr;
    }
}

void SaveFile::save_file(Snapshot snapshot) {
    std::pair<int, int> player_position = snapshot.get_memento()->get_player_position();
    int player_health = snapshot.get_memento()->get_player_health();
    int player_scorepoint = snapshot.get_memento()->get_player_scorepoint();

    *file << std::to_string(player_position.first) << ' ' << std::to_string(player_position.second) << ' '
          << std::to_string(player_health) << ' ' << std::to_string(player_scorepoint) << std::endl;

    for (int i = 0; i < snapshot.get_memento()->get_bomb_elements().size(); i++)
        *file << std::to_string(snapshot.get_memento()->get_bomb_elements()[i].first) << ' ';
    *file << std::endl;
    for (int i = 0; i < snapshot.get_memento()->get_bomb_elements().size(); i++)
        *file << std::to_string(snapshot.get_memento()->get_bomb_elements()[i].second) << ' ';
    *file << std::endl;

    for (int i = 0; i < snapshot.get_memento()->get_scorepoint_elements().size(); i++)
        *file << std::to_string(snapshot.get_memento()->get_scorepoint_elements()[i].first) << ' ';
    *file << std::endl;
    for (int i = 0; i < snapshot.get_memento()->get_scorepoint_elements().size(); i++)
        *file << std::to_string(snapshot.get_memento()->get_scorepoint_elements()[i].second) << ' ';
    *file << std::endl;

    for (int i = 0; i < snapshot.get_memento()->get_health_elements().size(); i++)
        *file << std::to_string(snapshot.get_memento()->get_health_elements()[i].first) << ' ';
    *file << std::endl;
    for (int i = 0; i < snapshot.get_memento()->get_health_elements().size(); i++)
        *file << std::to_string(snapshot.get_memento()->get_health_elements()[i].second) << ' ';
    *file << std::endl;

    for (int i = 0; i < snapshot.get_memento()->get_damage_enemies().size(); i++)
        *file << std::to_string(snapshot.get_memento()->get_damage_enemies()[i].first) << ' ';
    *file << std::endl;
    for (int i = 0; i < snapshot.get_memento()->get_damage_enemies().size(); i++)
        *file << std::to_string(snapshot.get_memento()->get_damage_enemies()[i].second) << ' ';
    *file << std::endl;

    for (int i = 0; i < snapshot.get_memento()->get_scorepoint_enemies().size(); i++)
        *file << std::to_string(snapshot.get_memento()->get_scorepoint_enemies()[i].first) << ' ';
    *file << std::endl;
    for (int i = 0; i < snapshot.get_memento()->get_scorepoint_enemies().size(); i++)
        *file << std::to_string(snapshot.get_memento()->get_scorepoint_enemies()[i].second) << ' ';
    *file << std::endl;

    for (int i = 0; i < snapshot.get_memento()->get_teleport_enemies().size(); i++)
        *file << std::to_string(snapshot.get_memento()->get_teleport_enemies()[i].first) << ' ';
    *file << std::endl;
    for (int i = 0; i < snapshot.get_memento()->get_teleport_enemies().size(); i++)
        *file << std::to_string(snapshot.get_memento()->get_teleport_enemies()[i].second) << ' ';
    *file << std::endl;
}