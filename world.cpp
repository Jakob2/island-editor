#include "world.h"

World::Window World::view;
World::Editor World::editor;
std::vector<QString> World::names;

World::World(){
    World::view.width = 800;
    World::view.height = 600;
    World::view.eyeX = 1;
    World::view.eyeY = 1;
    World::view.eyeZ = 1;
    World::view.x = 0;
    World::view.z = 0;
    World::view.zoom = 1;

    World::editor.baseRange = {10,15,20};
    World::editor.range = World::editor.baseRange[0];
    World::editor.ground = 0;
    World::editor.text = "toggle ground option press k";
    World::editor.alterGround = false;
    World::editor.tile = {0,0};
    World::editor.name = 1;
}

