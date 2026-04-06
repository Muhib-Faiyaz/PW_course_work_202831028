#include <SFML/Graphics.hpp>
#include <cmath>  

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode({ 800, 400 }), "Task 103", sf::Style::Default);

    int window_x_axis = window.getSize().x;
    int window_y_axis = window.getSize().y;

    CircleShape circle1(50.0f);
    circle1.setFillColor(sf::Color::Green);
    circle1.setOrigin({ circle1.getRadius() , circle1.getRadius() });

    circle1.setPosition({ 0.f, window_y_axis / 2.0f });

    CircleShape circle2(35.0f);
    circle2.setFillColor(sf::Color::Blue);
    circle2.setOrigin({ circle2.getRadius() , circle2.getRadius() });
    circle2.setPosition({ window_x_axis / 2.0f,circle2.getRadius() });


    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {

            if (event->is< sf::Event::Closed>()) window.close();

        }
        circle1.move({ 0.1f,0.0f });
        if (circle1.getPosition().x + circle1.getRadius() >= window_x_axis) {
            circle1.setPosition({ 0.f, window_y_axis / 2.0f });
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            circle2.move({ .5f, 0.0f });

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            circle2.move({ -.5f, 0.0f });

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            circle2.move({ 0.0f,-0.5f });

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            circle2.move({ 0.0f, 0.5f });


        float dx = circle1.getPosition().x - circle2.getPosition().x;
        float dy = circle1.getPosition().y - circle2.getPosition().y;
        float distance = std::sqrt(pow(dx, 2) + pow(dy, 2));

        if (distance <= circle1.getRadius() + circle2.getRadius())
        {
            circle1.setFillColor(sf::Color::Black);
            window.clear(sf::Color::Red);
        }
        else {
            circle1.setFillColor(sf::Color::Green);
            window.clear(sf::Color::Black);
        }

        window.draw(circle1);
        window.draw(circle2);



        window.display();
    }
}