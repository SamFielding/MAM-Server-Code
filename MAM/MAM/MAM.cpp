// MAM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameServer.h"
#include "Collision.h"
#include "PlayerEntity.h"

int main()
{
//    GameServer server(4300, 4301);
//    std::thread tcp_thread(&GameServer::tcp_start, &server);
//    // std::thread udp_thread(&GameServer::udp_start, &server);
//    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Not strictly necessary, just helps with the output
    

         sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
         sf::CircleShape shape(100.f);
         shape.setFillColor(sf::Color::Green);
         Collision col;
         col.SetPos(sf::Vector2f(0.f,0.f));
         col.SetSize(sf::Vector2f(200.f, 200.f));
        // PlayerEntity player;
        // sf::RectangleShape playerSprite;
        // playerSprite.setPosition(200.f, 200.f);


        while (true)
        {

             sf::Vector2i mousePos = sf::Mouse::getPosition(window);
           
        //     //player.render(window);

             if (col.ContainsPoint(sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))))
             {
                 std::cout << "Point is within collision" << std::endl;
             }

             sf::Event event;
             while (window.pollEvent(event))
             {
                 if (event.type == sf::Event::Closed)
                     window.close();
             }

             window.clear();
             // window.draw(shape);
            // player.render(window);
            window.display();
        }

       // tcp_thread.join();
        // udp_thread.join();

        return 0;
    
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
