#include "src/system/CrossHair.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "src/structs.hpp"
#include <SFML/Audio.hpp>
#include "src/system/AudioManager.hpp"
#include "src/system/Cursor.hpp"
#include "src/math.hpp"
#include "src/system/Player.hpp"
#include "src/system/BulletManager.hpp"
#include <cmath>

int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    //sf::Vector2f WindowSize(1920,1080);
    sf::Vector2f WindowSize(desktop.width,desktop.height);
    sf::RenderWindow window(sf::VideoMode(WindowSize.x, WindowSize.y), "Game",sf::Style::None);

    sf::Vector2f MousePos,playerPos(WindowSize.x/2,WindowSize.y/2);
    float ReladingTime=0.5f;

    AudioManager audioManager;
    BulletManager bulletManager(WindowSize);
    audioManager.addAudio("shoot","../resource/audio/shoot.wav",15.0f);
    audioManager.addAudio("reload","../resource/audio/reload.mp3",15.0f);
    // AudioPlayer shoot("../resource/audio/shoot.wav",15.0f);
    // AudioPlayer reload("../resource/audio/reload.mp3",15.0f);
    float rotationAngle=0;

    Timer crosshair_execute(sf::seconds(0.15f));
    Timer crosshair_reload(sf::seconds(ReladingTime));
    CrossHair crossHair(MousePos,crosshair_execute,crosshair_reload);
    Cursor cursor(MousePos);
    Player player(playerPos,crosshair_execute,rotationAngle);

    //bool Ceased=false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if(event.type==sf::Event::MouseEntered){
                window.setMouseCursorVisible(false);
            }
            if(event.type==sf::Event::MouseLeft){
                window.setMouseCursorVisible(true);
            }
            if(event.type==sf::Event::MouseButtonPressed){
                if(event.mouseButton.button==sf::Mouse::Right){
                    if(!crossHair.isreloading()){
                        crossHair.setReloading(true);
                        audioManager.playAudio("reload");
                        crosshair_reload.restart();
                    }
                }
            }
            // if(event.type==sf::Event::MouseButtonPressed){
            //     if(event.mouseButton.button==sf::Mouse::Left){
            //         crossHair.setColor(sf::Color::Red);
            //         shoot_sound.play();
            //         crosshair_execute.restart();
            //     }
            // }
            if(event.type==sf::Event::KeyPressed){
                if(event.key.code==sf::Keyboard::Escape){
                    window.close();
                }
                if(event.key.code==sf::Keyboard::R){
                    if(!crossHair.isreloading()){
                        crossHair.setReloading(true);
                        audioManager.playAudio("reload");
                        crosshair_reload.restart();
                    }
                }
                // if(event.key.code==sf::Keyboard::C){
                //     Ceased=!Ceased;
                // }
            }
        }
        //if(Ceased)continue;
        float rt_angle_sin,rt_angle_cos;
        rotationAngle=angleBetween(MousePos,playerPos,rt_angle_cos,rt_angle_sin);
        if(crossHair.isreloading()&&crosshair_reload.isDone()){
            crossHair.reload();
            crossHair.setReloading(false);
        }
        if(crosshair_execute.isDone()){
            crossHair.setColor(sf::Color::White);
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(!crossHair.isreloading()&&crosshair_execute.isDone()){
                if(crossHair.shoot()){
                    crossHair.setColor(sf::Color::Red);
                    audioManager.playAudio("shoot");
                    crosshair_execute.restart();
                    bulletManager.createBullet(
                        sf::Vector2f(playerPos.x-100*rt_angle_cos,playerPos.y-100*rt_angle_sin)
                        ,{-rt_angle_cos,-rt_angle_sin},rotationAngle);
                }
            }
        }
        window.clear(sf::Color::Black);
        MousePos = sf::Vector2f(sf::Mouse::getPosition(window));
        window.draw(player);
        window.draw(crossHair);
        bulletManager.moveBullet();
        window.draw(bulletManager);
        //window.draw(cursor);
        window.display();
    }
}
