#pragma once


using namespace std;
struct PEER{
	
};
struct ReadyPlayer{
	PEER* player;
};
class Lobby{
private:
	const int SCREEN_WIDTH = 1200;
	const int SCREEN_HEIGHT = 800;
	sf::RenderWindow* mainWindow;

	sf::TcpListener listener;

	std::list<sf::TcpSocket*> clients;
	sf::SocketSelector socketSelector;

	vector<PEER*> peer;
	void registerPeer();

	sf::Event event;
public:
	Lobby();
	~Lobby();

	void addConnection();
	void removeConnection();

	void updateConnection();

	void run();

	void draw();

};