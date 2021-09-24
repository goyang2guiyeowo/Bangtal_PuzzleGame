#define _CRT_SECURE_NO_WARNINGS
#include <bangtal>
using namespace bangtal;

ScenePtr scene;
ObjectPtr puz[9];
int blank;

int game_index(ObjectPtr p) {
    for (int i = 0; i < 9; i++)
        if (puz[i] == p) return i;
    return -1;
}

void move(int index) {
    auto piece = puz[index];
    puz[index] = puz[blank];
}

void init_game() {
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

    //배경 생성
    scene = Scene::create("퍼즐 맞추기", "배경.jpg");

    //퍼즐 생성
    char path[10];

    for (int i = 0; i < 9; i++) {
        sprintf(path, "%d.jpg", i + 1);
        puz[i] = Object::create(path, scene, 70 + 171 * (i % 3), 400 - 171 * (i / 3));

        puz[i]->setOnMouseCallback([&](auto p, auto x, auto y, auto action)->bool {
            int index = game_index(p);

            return true;
            });
    }

    blank = 9;
    
    //재시작 버튼 생성
    auto restart = Object::create("restart.png", scene, 700, 530);

    //종료 버튼 생성
    auto finish = Object::create("finish.png", scene, 630, 420);

    //게임 시작
    startGame(scene);
}

int main()
{
    init_game();

    return 0;
}