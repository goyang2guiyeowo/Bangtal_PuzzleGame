#include <iostream>
#include <bangtal>
using namespace std;
using namespace bangtal;

int main()
{
    //배경 생성
    auto scene = Scene::create("퍼즐 맞추기", "C:/Users/SAMSUNG/Desktop/배경.jpg");

    //퍼즐 생성
    auto p4x = 70, p4y = 400;
    auto p8x = 241, p8y = 400;
    auto p5x = 412, p5y = 400;
    auto p7x = 70, p7y = 229;
    auto p1x = 241, p1y = 229;
    auto p6x = 412, p6y = 229;
    auto p2x = 70, p2y = 58;
    auto p3x = 241, p3y = 58;
    auto p9x = 412, p9y = 58;

    auto puz4 = Object::create("C:/Users/SAMSUNG/Desktop/4.jpg", scene, p4x, p4y);
    auto puz8 = Object::create("C:/Users/SAMSUNG/Desktop/8.jpg", scene, p8x, p8y);
    auto puz5 = Object::create("C:/Users/SAMSUNG/Desktop/5.jpg", scene, p5x, p5y);
    auto puz7 = Object::create("C:/Users/SAMSUNG/Desktop/7.jpg", scene, p7x, p7y);
    auto puz1 = Object::create("C:/Users/SAMSUNG/Desktop/1.jpg", scene, p1x, p1y);
    auto puz6 = Object::create("C:/Users/SAMSUNG/Desktop/6.jpg", scene, p6x, p6y);
    auto puz2 = Object::create("C:/Users/SAMSUNG/Desktop/2.jpg", scene, p2x, p2y);
    auto puz3 = Object::create("C:/Users/SAMSUNG/Desktop/3.jpg", scene, p3x, p3y);

    //재시작 버튼 생성
    auto restart = Object::create("C:/Users/SAMSUNG/Desktop/restart.png", scene, 700, 530);

    //퍼즐1 옮기기
    puz1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
        if (action == MouseAction::MOUSE_DRAG_RIGHT) {
            p1x += 171;
            puz1->locate(scene, p1x, p1y);
        }
        if (action == MouseAction::MOUSE_DRAG_LEFT) {
            p1x -= 171;
            puz1->locate(scene, p1x, p1y);
        }
        if (action == MouseAction::MOUSE_DRAG_UP) {
            p1y += 171;
            puz1->locate(scene, p1x, p1y);
        }
        if (action == MouseAction::MOUSE_DRAG_DOWN) {
            p1y -= 171;
            puz1->locate(scene, p1x, p1y);
        }

        return true;
        });

    //퍼즐2 옮기기
    puz2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
        if (action == MouseAction::MOUSE_DRAG_RIGHT) {
            p2x += 171;
            puz2->locate(scene, p2x, p2y);
        }
        if (action == MouseAction::MOUSE_DRAG_LEFT) {
            p2x -= 171;
            puz2->locate(scene, p2x, p2y);
        }
        if (action == MouseAction::MOUSE_DRAG_UP) {
            p2y += 171;
            puz2->locate(scene, p2x, p2y);
        }
        if (action == MouseAction::MOUSE_DRAG_DOWN) {
            p2y -= 171;
            puz2->locate(scene, p2x, p2y);
        }

        return true;
        });

    //퍼즐3 옮기기
    puz3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
        if (action == MouseAction::MOUSE_DRAG_RIGHT) {
            p3x += 171;
            puz3->locate(scene, p3x, p3y);
        }
        if (action == MouseAction::MOUSE_DRAG_LEFT) {
            p3x -= 171;
            puz3->locate(scene, p3x, p3y);
        }
        if (action == MouseAction::MOUSE_DRAG_UP) {
            p3y += 171;
            puz3->locate(scene, p3x, p3y);
        }
        if (action == MouseAction::MOUSE_DRAG_DOWN) {
            p3y -= 171;
            puz3->locate(scene, p3x, p3y);
        }

        return true;
        });

    //퍼즐4 옮기기
    puz4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
        if (action == MouseAction::MOUSE_DRAG_RIGHT) {
            p4x += 171;
            puz4->locate(scene, p4x, p4y);
        }
        if (action == MouseAction::MOUSE_DRAG_LEFT) {
            p4x -= 171;
            puz4->locate(scene, p4x, p4y);
        }
        if (action == MouseAction::MOUSE_DRAG_UP) {
            p4y += 171;
            puz4->locate(scene, p4x, p4y);
        }
        if (action == MouseAction::MOUSE_DRAG_DOWN) {
            p4y -= 171;
            puz4->locate(scene, p4x, p4y);
        }

        return true;
        });

    //퍼즐5 옮기기
    puz5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
        if (action == MouseAction::MOUSE_DRAG_RIGHT) {
            p5x += 171;
            puz5->locate(scene, p5x, p5y);
        }
        if (action == MouseAction::MOUSE_DRAG_LEFT) {
            p5x -= 171;
            puz5->locate(scene, p5x, p5y);
        }
        if (action == MouseAction::MOUSE_DRAG_UP) {
            p5y += 171;
            puz5->locate(scene, p5x, p5y);
        }
        if (action == MouseAction::MOUSE_DRAG_DOWN) {
            p5y -= 171;
            puz5->locate(scene, p5x, p5y);
        }

        return true;
        });

    //퍼즐6 옮기기
    puz6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
        if (action == MouseAction::MOUSE_DRAG_RIGHT) {
            p6x += 171;
            puz6->locate(scene, p6x, p6y);
        }
        if (action == MouseAction::MOUSE_DRAG_LEFT) {
            p6x -= 171;
            puz6->locate(scene, p6x, p6y);
        }
        if (action == MouseAction::MOUSE_DRAG_UP) {
            p6y += 171;
            puz6->locate(scene, p6x, p6y);
        }
        if (action == MouseAction::MOUSE_DRAG_DOWN) {
            p6y -= 171;
            puz6->locate(scene, p6x, p6y);
        }

        return true;
        });

    //퍼즐7 옮기기
    puz7->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
        if (action == MouseAction::MOUSE_DRAG_RIGHT) {
            p7x += 171;
            puz7->locate(scene, p7x, p7y);
        }
        if (action == MouseAction::MOUSE_DRAG_LEFT) {
            p7x -= 171;
            puz7->locate(scene, p7x, p7y);
        }
        if (action == MouseAction::MOUSE_DRAG_UP) {
            p7y += 171;
            puz7->locate(scene, p7x, p7y);
        }
        if (action == MouseAction::MOUSE_DRAG_DOWN) {
            p7y -= 171;
            puz7->locate(scene, p7x, p7y);
        }

        return true;
        });

    //퍼즐8 옮기기
    puz8->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
        if (action == MouseAction::MOUSE_DRAG_RIGHT) {
            p8x += 171;
            puz8->locate(scene, p8x, p8y);
        }
        if (action == MouseAction::MOUSE_DRAG_LEFT) {
            p8x -= 171;
            puz8->locate(scene, p8x, p8y);
        }
        if (action == MouseAction::MOUSE_DRAG_UP) {
            p8y += 171;
            puz8->locate(scene, p8x, p8y);
        }
        if (action == MouseAction::MOUSE_DRAG_DOWN) {
            p8y -= 171;
            puz8->locate(scene, p8x, p8y);
        }

        return true;
        });

    //퍼즐을 풀면 종료
    if ((p1x == 70) && (p1y == 400) && (p2x == 241) && (p2y == 400) && (p3x == 412) && (p3y == 400) && (p4x == 70) && (p4y == 229) && (p5x == 241) && (p5y == 229) && (p6x == 412) && (p6y == 229) && (p7x == 70) && (p7y == 58) && (p8x == 241) && (p8y == 58)) {
        endGame();
        return true;
    };

    startGame(scene);
}