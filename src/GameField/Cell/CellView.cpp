#include "CellView.h"
#include "Cell.h"

CellView::CellView() {
    bomb_texture.loadFromFile("Sprites/Element/BombSprite.png");
    health_texture.loadFromFile("Sprites/Element/HealthSprite.png");
    scorepoint_texture.loadFromFile("Sprites/Element/ScorePointSprite.png");
    entry_cell_texture.loadFromFile("Sprites/Cell/EntryCell.png");
    exit_cell_texture.loadFromFile("Sprites/Cell/ExitCell.png");
    passage_cell_texture.loadFromFile("Sprites/Cell/PassageCell.png");
    wall_cell_texture.loadFromFile("Sprites/Cell/WallCell.png");
    player_texture.loadFromFile("Sprites/PlayerSprite.png");
    enemy_scorepoint_texture.loadFromFile("Sprites/Enemy/EnemyScorepointSprite.png");
    enemy_damage_texture.loadFromFile("Sprites/Enemy/EnemyDamageSprite.png");
    enemy_teleport_texture.loadFromFile("Sprites/Enemy/EnemyTeleportSprite.png");
    cell = nullptr;
}

void CellView::set_cell(Cell* new_cell) {
    cell = new_cell;
}

void CellView::choose_image() {
    if (cell->is_player_on_cell())
        cell_image.setTexture(player_texture);
    else if (cell->is_enemy_damage_on_cell())
        cell_image.setTexture(enemy_damage_texture);
    else if (cell->is_enemy_scorepoint_on_cell())
        cell_image.setTexture(enemy_scorepoint_texture);
    else if (cell->is_enemy_teleport_on_cell())
        cell_image.setTexture(enemy_teleport_texture);
    else if (cell->get_object() != nullptr) {
        if (cell->get_object()->get_type() == GameObject::Bomb)
            cell_image.setTexture(bomb_texture);
        else if (cell->get_object()->get_type() == GameObject::Health)
            cell_image.setTexture(health_texture);
        else if (cell->get_object()->get_type() == GameObject::ScorePoint)
            cell_image.setTexture(scorepoint_texture);
    }
    else if (cell->get_type() == Cell::Passage)
        cell_image.setTexture(passage_cell_texture);
    else if (cell->get_type() == Cell::Entry)
        cell_image.setTexture(entry_cell_texture);
    else if (cell->get_type() == Cell::Exit)
        cell_image.setTexture(exit_cell_texture);
    else if (cell->get_type() == Cell::Wall)
        cell_image.setTexture(wall_cell_texture);
    cell_image.setPosition(cell->get_position().first*Cell::get_size(),cell->get_position().second*Cell::get_size());
}

sf::Sprite CellView::get_cell_view() const {
    return cell_image;
}
