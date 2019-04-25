#include "GameSound.h"



GameSound::GameSound()
{
	loadSong();
	loadCoin();
	loadDeath();
	loadJump();
}


GameSound::~GameSound()
{
}

bool GameSound::loadSong() //function in constructor
{
	if (!song.openFromFile("GameMusic.wav"))
	{
		return false;
	}
	return true;
}

void GameSound::startSong()
{
	song.play();
	song.setLoop(true);
}

void GameSound::playSong()
{
	song.play();
}

void GameSound::pauseSong()
{
	song.pause();
}

bool GameSound::isOver()
{
	if (song.getStatus() != sf::Music::Playing)
	{
		return true;
	}
	return false;
}

bool GameSound::loadJump()
{
	if (!jump.loadFromFile("smb_jump-super.wav"))
	{
		return false;
	}
	return true;
}

void GameSound::jumpPlay()
{
	sf::Sound sound;
	sound.setBuffer(jump);
	sound.setVolume(100);
	sound.play();

	while (sound.getStatus() == sf::Sound::Playing)
	{
	}
}

bool GameSound::loadDeath()
{
	if (!death.loadFromFile("smb_mariodie.wav"))
	{
		return false;
	}
	return true;
}

void GameSound::deathPlay()
{
	sf::Sound sound;
	sound.setBuffer(death);
	sound.setVolume(100);
	sound.play();

	while (sound.getStatus() == sf::Sound::Playing)
	{
	}
}

bool GameSound::loadCoin()
{
	if(!coin.loadFromFile("smb_coin.wav"))
	{
		return false;
	}
	return true;;
}

void GameSound::coinPlay()
{
	sf::Sound sound;
	sound.setBuffer(coin);
	sound.setVolume(100);
	sound.play();

	while (sound.getStatus() == sf::Sound::Playing)
	{
	}
}




