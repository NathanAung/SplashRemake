#include <Siv3D.hpp>
#include "DungeonMap.h"

void Main() {
    Window::Resize(640, 640);
    Texture mapTex(U"map.png");

    P2World world;
    DungeonMap dungeon;

    Array<P2Body> colliders = dungeon.CreateColliders(world);
    Array<DungeonMap::Gimmick> gimmicks = dungeon.CreateGimmicks();
    dungeon.LinkGimmicks(gimmicks);

    P2Body player = world.createCircle(P2Dynamic, Vec2{ 200, -500 }, 10);
    const double step = 1.0 / 200.0;
    double accTime = 0.0;

    while (System::Update()) {
        for (accTime += Scene::DeltaTime(); step <= accTime; accTime -= step)
            world.update(step);

        dungeon.Draw(mapTex);
        dungeon.DrawColliders(colliders);
        dungeon.UpdateGimmicks(gimmicks, colliders, player);

        player.draw(Palette::Yellow);
    }
}
