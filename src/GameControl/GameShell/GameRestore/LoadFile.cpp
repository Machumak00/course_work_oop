#include "LoadFile.h"
#include "LoadException.h"
#include "WrongInformationException.h"
#include "Field.h"
#include "Snapshot.h"

LoadFile::LoadFile(){
    file = new std::ifstream("Saves/SaveGame1");
    if (!file->is_open())
        throw LoadException("Не удалось открыть файл для загрузки!");
}

LoadFile::~LoadFile() {
    if (file != nullptr && file->is_open()) {
        file->close();
        if (file->is_open())
            throw LoadException("Не удалось закрыть файл после загрузки!");
    }
    if (file != nullptr) {
        delete file;
        file = nullptr;
    }
}

Snapshot LoadFile::load_file() {
    Snapshot snapshot;
    std::string info;
    std::vector<int> info1, info2;
    Field *field = Field::get_field();

    std::getline(*file,info); //информация об игроке
    info1 = from_str_to_int(info);

    if (info1.size() != 4)
        throw WrongInformationException();



    if (std::find_if(info1.begin(), info1.end(), [](int x){return x < 0;}) != info1.end()) //если есть отрицательный элемент
        throw WrongInformationException();

    snapshot.get_memento()->set_player_position(std::make_pair(info1[0], info1[1]));
    snapshot.get_memento()->set_player_health(info1[2]);
    snapshot.get_memento()->set_player_scorepoint(info1[3]);

    for (int i = 0; i < 3; ++i) { //для каждого типа элементов
        std::getline(*file,info); //считываем информацию x-координат элементов
        info1 = from_str_to_int(info);
        std::getline(*file,info); //считываем информацию y-координат элементов
        info2 = from_str_to_int(info);

        if (info1.size() != info2.size())
            throw WrongInformationException();
        if (std::find_if(info1.begin(), info1.end(), [&field](int x){return (x < 0 || x > Field::get_field()->get_size());}) != info1.end())
            throw WrongInformationException();
        if (std::find_if(info2.begin(), info2.end(), [&field](int x){return (x < 0 || x > Field::get_field()->get_size());}) != info2.end())
            throw WrongInformationException();

        for (int j = 0; j < info1.size(); ++j) {
            std::pair<int, int> elem(info1[j], info2[j]);
            if (i == 0)
                snapshot.get_memento()->set_bomb_element(elem);
            else if (i == 1)
                snapshot.get_memento()->set_scorepoint_elements(elem);
            else if (i == 2)
                snapshot.get_memento()->set_health_elements(elem);
        }
    }

    for(int i = 0; i < 3; ++i) { //для каждого типа врагов
        std::getline(*file,info);//считываем информацию x-координат врагов
        info1 =  from_str_to_int(info);
        std::getline(*file,info);//считываем информацию y-координат врагов
        info2 = from_str_to_int(info);

        if(std::find_if(info1.begin(), info1.end(), [&field](int x){return (x < 0 || x > Field::get_field()->get_size());}) != info1.end())
            throw WrongInformationException();
        if(std::find_if(info2.begin(), info2.end(), [&field](int x){return (x < 0 || x > Field::get_field()->get_size());}) != info2.end())
            throw WrongInformationException();


        for(int j = 0; j < info1.size(); ++j) {
            std::pair<int, int> elem (info1[j], info2[j]);
            if (i == 0)
                snapshot.get_memento()->set_damage_enemies(elem);
            else if (i == 1)
                snapshot.get_memento()->set_scorepoint_enemies(elem);
            else if (i == 2)
                snapshot.get_memento()->set_teleport_enemies(elem);
        }
    }
    return snapshot;
}

std::vector<int> LoadFile::from_str_to_int(const std::string& str, const std::string& delim) {
    std::vector<int> tokens;
    size_t prev = 0;
    size_t pos;
    do {
        pos = str.find(delim, prev);
        if (pos == std::string::npos)
            pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty())
            try {
                tokens.push_back(stoi(token));
            }
            catch(std::invalid_argument exception) {
                throw WrongInformationException();
            }
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}