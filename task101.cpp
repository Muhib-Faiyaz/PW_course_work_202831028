#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode({ 800, 400 }), "Task 101", sf::Style::Default);

    CircleShape circle(100.0f);
    circle.setFillColor(sf::Color::Green);
    circle.setOrigin({ circle.getRadius() , circle.getRadius() });
    int window_x_axis = window.getSize().x;
    int window_y_axis = window.getSize().y;
    circle.setPosition({ window_x_axis / 2.0f, window_y_axis / 2.0f });


    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {

            if (event->is< sf::Event::Closed>()) window.close();

        }
        window.clear();
        window.draw(circle);
        window.display();
    }
}