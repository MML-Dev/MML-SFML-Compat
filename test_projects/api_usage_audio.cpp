
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

void test_input_sound_file()
{
    sf::InputSoundFile file;
    bool ret = file.openFromFile("/beep/boop/");
    char data[1] = {0};
    ret = file.openFromMemory(data, std::size_t(1));
    sf::FileInputStream inputStreamFile;
    sf::MemoryInputStream inputStreamMem;
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
