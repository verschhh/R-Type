/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Sound.hpp
*/

#ifndef _SOUND_HPP_
    #define _SOUND_HPP_

    #include <SFML/Audio.hpp>

class Sound {
    /**
     * @brief Sound class
     * 
     * This class is used to handle the sounds
     * 
     * @param music : the music
     * @param buffer : the buffer
     * @param sound : the sound
     * 
     * @return nothing
     */
    public:

    Sound() = default;

    bool loadFromFileMusic(std::string file) { return music.openFromFile(file); };
    bool loadFromFileSound(std::string file) { return buffer.loadFromFile(file); };

    void playMusic() { music.play(); };
    void musicLoop(bool loop) {music.setLoop(loop); };
    void setBuffer() {sound.setBuffer(buffer); };
    void playSound() { sound.play(); };
    void setVolumeSound(int volume) { sound.setVolume(volume); };
    void setVolumeMusic(int volume) { music.setVolume(volume); };
    void modifyVolumeSound(int volume) { sound.getVolume() + volume; };
    void modifyVolumeMusic(int volume) { music.getVolume() + volume; };

    private:

    sf::Music music;
    sf::SoundBuffer buffer;
    sf::Sound sound;
};

#endif