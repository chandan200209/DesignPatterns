#include "MusicPlayerApplication.hpp"
using namespace std;
int main()
{
    try
    {
        auto application = MusicPlayerApplication::getInstance();
        // populate library
        application->createSongInLibrary("Kesariya", "Arijit Singh", "/music/kesariya.mp3");
        application->createSongInLibrary("Chhaiyya Chhaiyya", "Sukhwinder Singh", "/music/chhaiyya_chhaiyya.mp3");
        application->createSongInLibrary("Tum Hi Ho", "Arijit Singh", "/music/tum_hi_ho.mp3");
        application->createSongInLibrary("Jai Ho", "A.R. Rahman", "/music/jai_ho.mp3");
        application->createSongInLibrary("Brown Rang", "Honey Singh", "/music/brown_rang.mp3");

        // create playlist and add songs
        application->createPlaylist("Bollywood Vibes");
        application->addSongToPlaylist("Bollywood Vibes", "Kesariya");
        application->addSongToPlaylist("Bollywood Vibes", "Chhaiyya Chhaiyya");
        application->addSongToPlaylist("Bollywood Vibes", "Tum Hi Ho");
        application->addSongToPlaylist("Bollywood Vibes", "Jai Ho");

        // connect device
        application->connectAudioDevice(DeviceType::HEADPHONES);

        // play/pause a single song
        application->playSingleSong("Brown Rang");
        application->pauseCurrentSong("Brown Rang");
        application->playSingleSong("Brown Rang"); // resume

        cout << "\n---Sequential Playback---" << endl;
        application->selectPlaylistStrategy(PlayStrategyType::SEQUENTIAL);
        application->loadPlaylist("Bollywood Vibes");
        application->playAllTracksInPlaylist();

        cout << "\n---Random Playback---" << endl;
        application->selectPlaylistStrategy(PlayStrategyType::RANDOM);
        application->loadPlaylist("Bollywood Vibes");
        application->playAllTracksInPlaylist();

        cout << "\n---Custom Queue Playback---" << endl;
        application->selectPlaylistStrategy(PlayStrategyType::CUSTOM_QUEUE);
        application->loadPlaylist("Bollywood Vibes");
        application->queueSongNext("Kesariya");
        application->queueSongNext("Tum Hi Ho");
        application->playAllTracksInPlaylist();
        application->playPreviousTrackInPlaylist();

        cout << "\n---Play Previous in Sequential---" << endl;
        application->selectPlaylistStrategy(PlayStrategyType::SEQUENTIAL);
        application->loadPlaylist("Bollywood Vibes");
        application->playAllTracksInPlaylist();
        application->playPreviousTrackInPlaylist();
        application->playPreviousTrackInPlaylist();
    }
    catch (const exception &error)
    {
        cerr << "Error : " << error.what() << endl;
    }
    return 0;
}