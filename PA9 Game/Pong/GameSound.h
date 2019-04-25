#pragma once
#include "SFML/Audio.hpp""

using sf::Music;
using sf::Sound;
using sf::SoundBuffer;


class GameSound
{
public:
	GameSound();
	~GameSound();

	bool loadSong();
	void startSong(); //start at beggining
	void playSong(); //play from pause
	void pauseSong();
	bool isOver();

	bool loadJump();
	void jumpPlay();

	bool loadDeath();
	void deathPlay();

	bool loadCoin();
	void coinPlay();


private:
	sf::Music song;
	sf::SoundBuffer jump;
	sf::SoundBuffer death;
	sf::SoundBuffer coin;
	
};
