#pragma once
//#include "Character.h"
#include "CharCreation.h"
//#include <iostream>
//#include <string>
//#include <ostream>
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//
//void createCharacter()
//{
//	sf::RenderWindow window(sf::VideoMode(640, 480), "RPG Character Creation");
//	sf::Font font;
//	sf::Text text;
//	Character pc("", none);
//	std::string textS;
//	std::string info = "Press <Space> to roll stats.\npress key for class\n(F)ighter\n(R)ogue\n(W)izard\n Press <Esc> when finished.";
//	std::string namePrompt = "Please enter your character name: ";
//	std::string name = "";
//	if (!font.loadFromFile("Typographytimes.ttf"))
//	{
//	}
//	text.setFont(font);
//	text.setCharacterSize(18);
//	text.setColor(sf::Color::Black);
//	window.clear(sf::Color::White);
//
//
//	// run the program as long as the window is open
//	while (window.isOpen())
//	{
//		// check all the window's events that were triggered since the last iteration of the loop
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			window.setKeyRepeatEnabled(false);
//			window.pollEvent(event);
//			// "close requested" event: we close the window
//			if (event.type == sf::Event::Closed)
//			{
//				window.close();
//			}
//			if (name.compare("") == 0)
//			{
//				textS += namePrompt;
//				text.setString(textS);
//
//				window.clear(sf::Color::White);
//				window.draw(text);
//				window.display();
//			}
//			while (sf::Event::TextEntered && (pc.getName().compare("") == 0))
//			{
//				window.setKeyRepeatEnabled(false);
//				window.pollEvent(event);
//				if (event.type == sf::Event::TextEntered)
//				{
//					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && name.compare("") != 0)
//					{
//						//pc.setName(name);
//						textS = "";
//						textS += car(pc);
//						textS += att(pc.getAttributes());
//						for (int i = 0; i < pc.getInventory().size(); ++i)
//						{
//							textS += pc.getInventory().get(0).getName();
//						}
//						textS += info;
//						text.setString(textS);
//
//						window.clear(sf::Color::White);
//						window.draw(text);
//						window.display();
//						break;
//					}
//					if (event.text.unicode > 31)
//					{
//						name += (char)event.text.unicode;
//						textS = "";
//						textS += namePrompt;
//						textS += name;
//						text.setString(textS);
//
//						window.clear(sf::Color::White);
//						window.draw(text);
//						window.display();
//					}
//				}
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
//			{
//				//pc.setClass(fighter);
//				textS = "";
//				textS += car(pc);
//				textS += att(pc.getAttributes());
//				for (int i = 0; i < pc.getInventory().size(); ++i)
//				{
//					textS += pc.getInventory().get(0).getName();
//				}
//				textS += info;
//				textS += info;
//				text.setString(textS);
//
//				window.clear(sf::Color::White);
//				window.draw(text);
//				window.display();
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
//			{
//				//pc.setClass(rogue);
//				textS = "";
//				textS += car(pc);
//				textS += att(pc.getAttributes());
//				for (int i = 0; i < pc.getInventory().size(); ++i)
//				{
//					textS += pc.getInventory().get(0).getName();
//				}
//				textS += info;
//				textS += info;
//				text.setString(textS);
//
//				window.clear(sf::Color::White);
//				window.draw(text);
//				window.display();
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//			{
//				//pc.setClass(wizard);
//				textS = "";
//				textS += car(pc);
//				textS += att(pc.getAttributes());
//				for (int i = 0; i < pc.getInventory().size(); ++i)
//				{
//					textS += pc.getInventory().get(0).getName();
//				}
//				textS += info;
//				textS += info;
//				text.setString(textS);
//
//				window.clear(sf::Color::White);
//				window.draw(text);
//				window.display();
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//			{
//				//pc.rollStats();
//				textS = "";
//				textS += car(pc);
//				textS += att(pc.getAttributes());
//				for (int i = 0; i < pc.getInventory().size(); ++i)
//				{
//					textS += pc.getInventory().get(0).getName();
//				}
//				textS += info;
//				textS += info;
//				text.setString(textS);
//
//				window.clear(sf::Color::White);
//				window.draw(text);
//				window.display();
//			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
//			{
//				//pc.levelUp();
//
//				textS = "";
//				textS += car(pc);
//				textS += att(pc.getAttributes());
//				for (int i = 0; i < pc.getInventory().size(); ++i)
//				{
//					textS += pc.getInventory().get(0).getName();
//				}
//				textS += info;
//				textS += info;
//				text.setString(textS);
//
//				window.clear(sf::Color::White);
//				window.draw(text);
//				window.display();
//			}
//
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//		{
//			break;
//		}
//	}
//}