#include "world.h"

World::Window World::view;
World::Editor World::editor;
World::Mouse World::mouse;
World::Height World::color;
std::vector<QString> World::names;

World::World(){
    World::view.width = 800;
    World::view.height = 600;
    World::view.eyeX = 8;
    World::view.eyeY = 8;
    World::view.eyeZ = 8;
    World::view.x = 0;
    World::view.z = 0;
    World::view.zoom = 1;

    //World::editor.baseRange = {10,15,20};
    World::editor.range = 10;
    World::editor.ground = 0;
    World::editor.textGround = "toggle ground mode press k";
    World::editor.textMountain = "toggle mountain mode l";
    World::editor.alterGround = false;
    World::editor.alterMountain = false;
    World::editor.tile = {0,0};
    World::editor.name = 1;
    World::editor.height = 0;

    World::color.one = {.1,0,0};
    World::color.two = {.2,0,0};
    World::color.three = {.3,0,0};
    World::color.four = {.4,0,0};
}

