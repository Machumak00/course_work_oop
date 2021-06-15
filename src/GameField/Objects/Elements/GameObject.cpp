#include "GameObject.h"

std::ostream& operator<<(std::ostream& output, const GameObject& game_object) {
    game_object.output_object(output);
    return output;
}
