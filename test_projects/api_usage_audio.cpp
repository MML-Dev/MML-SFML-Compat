
// Including all files to make sure we don't delete some by mistake

#include <SFML/Audio.hpp>
#include <SFML/Audio/AlResource.hpp>
#include <SFML/Audio/Export.hpp>
#include <SFML/Audio/InputSoundFile.hpp>
#include <SFML/Audio/Listener.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/OutputSoundFile.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/SoundBufferRecorder.hpp>
#include <SFML/Audio/SoundFileFactory.hpp>
#include <SFML/Audio/SoundFileReader.hpp>
#include <SFML/Audio/SoundFileWriter.hpp>
#include <SFML/Audio/SoundRecorder.hpp>
#include <SFML/Audio/SoundSource.hpp>
#include <SFML/Audio/SoundStream.hpp>

// Some globals for testing with multiple apis
sf::FileInputStream inputStreamFile;
sf::MemoryInputStream inputStreamMem;
char data[1] = {0};
sf::Int16 samples[1] = {0};

void test_input_sound_file()
{
    sf::InputSoundFile file;
    bool ret = file.openFromFile("/beep/boop/");
    ret = file.openFromMemory(data, std::size_t(1));
    ret = file.openFromStream(inputStreamFile);
    ret = file.openFromStream(inputStreamMem);
    sf::Uint64 sampleCount = file.getSampleCount();
    unsigned int channelCount = file.getChannelCount();
    unsigned int sampleRate = file.getSampleRate();
    sf::Time duration = file.getDuration();
    sf::Time offset = file.getTimeOffset();
    sf::Uint64 sampleOffset = file.getSampleOffset();
    file.seek(sf::Uint64(12));
    file.seek(sf::seconds(12));
    sf::Int16 samples[1] = {0};
    sf::Uint64 read = file.read(samples, sf::Uint64(1));
}

void test_listener()
{
    sf::Listener::setGlobalVolume(1.f);
    float vol = sf::Listener::getGlobalVolume();
    sf::Listener::setPosition(1.f, 1.f, 1.f);
    sf::Listener::setPosition({1.f, 1.f, 1.f});
    sf::Vector3f pos = sf::Listener::getPosition();
    sf::Listener::setDirection(1.f, 1.f, 1.f);
    sf::Listener::setDirection({1.f, 1.f, 1.f});
    sf::Vector3f dir = sf::Listener::getDirection();
    sf::Listener::setUpVector(1.f, 1.f, 1.f);
    sf::Listener::setUpVector({1.f, 1.f, 1.f});
    sf::Vector3f up = sf::Listener::getUpVector();
}

void test_music()
{
    sf::Music music;
    bool ret = music.openFromFile("/beep/boop/");
    ret = music.openFromMemory(data, std::size_t(1));
    ret = music.openFromStream(inputStreamFile);
    ret = music.openFromStream(inputStreamMem);
    sf::Time duration = music.getDuration();
    sf::Music::TimeSpan loop = music.getLoopPoints();
    music.setLoopPoints(loop);
}

void test_output_sound_file()
{
    sf::OutputSoundFile file;
    bool ret = file.openFromFile("/beep/boop/", 12u, 12u);
    file.write(samples, sf::Uint64(1));
}

void test_sound()
{
    sf::Sound sound;
    sf::SoundBuffer buf;
    sf::Sound sound2(buf);
    sf::Sound sound3(sound2);
    sound.play();
    sound.pause();
    sound.stop();
    sound.setBuffer(buf);
    sound.setLoop(true);
    sound.setPlayingOffset(sf::seconds(1.f));
    const sf::SoundBuffer* pBuf = sound.getBuffer();
    bool loop = sound.getLoop();
    sf::Time offset = sound.getPlayingOffset();
    sf::Sound::Status status = sound.getStatus();
    sound = sound2;
    sound.resetBuffer(); // comment says this is for internal use but is in public API?
}

void test_sound_buffer()
{
    sf::SoundBuffer buffer;
    sf::SoundBuffer buffer2(buffer);
    bool ret = buffer.loadFromFile("beep/boop");
    ret = buffer.loadFromMemory(data, std::size_t(1));
    ret = buffer.loadFromStream(inputStreamFile);
    ret = buffer.loadFromStream(inputStreamMem);
    ret = buffer.loadFromSamples(samples, sf::Uint64(12), 12u, 12u);
    buffer.saveToFile("beep/boop");
    const sf::Int16* s = buffer.getSamples();
    sf::Uint64 count = buffer.getSampleCount();
    unsigned int rate = buffer.getSampleRate();
    unsigned int channels = buffer.getChannelCount();
    sf::Time duration = buffer.getDuration();
    buffer = buffer2;
}
