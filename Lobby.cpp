#include "Lobby.h"

Lobby::Lobby(){
	///listener.setBlocking(false);
	///if (listener.listen(53000) != sf::Socket::Done){
	///	cout << "Listener not bound to port." << endl;
	///}
	///else{
	///	
	///	socketSelector.add(listener);
	///}
	
	mainWindow = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Digimon Tactics Lobby", sf::Style::Close);
}
Lobby::~Lobby(){

}
void Lobby::addConnection(){
}
void Lobby::removeConnection(){
}
void Lobby::updateConnection(){
		cout << "Listener not blocking" << endl;
	
	// Make the selector wait for data on any socket
	///if (socketSelector.wait()){
	///	cout << "SocketSelector waiting" << endl; if (socketSelector.isReady(listener)){}
		/*if (socketSelector.isReady(listener)){
			cout << "Listener is ready" << endl;
			//Make a new socket
			sf::TcpSocket* client = new sf::TcpSocket;
			client->setBlocking(false);
			if (listener.accept(*client) == sf::Socket::Done){
				cout << "ACCEPT!" << endl;
				//Add client to client list
				clients.push_back(client);
				//Add socket to the Socket list
				socketSelector.add(*client);
				
			}
			else{
				//Remove socket upon no connection
				delete client;
			}
		}
		else{
			// The listener socket is not ready, test all other sockets (the clients)
			for (std::list<sf::TcpSocket*>::iterator it = clients.begin(); it != clients.end(); ++it){
				sf::TcpSocket& client = **it;
				if (socketSelector.isReady(client))
				{
					// The client has sent some data, we can receive it
					sf::Packet packet;
					if (client.receive(packet) == sf::Socket::Done)
					{
						//receive some data
					}
				}
			}
		}*/
///	}
}

void Lobby::run(){
	sf::TcpListener listener;
	listener.setBlocking(false);
	std::list<sf::TcpSocket*> clients;
	sf::SocketSelector socketSelector;
	listener.listen(53000);
	socketSelector.add(listener);
	while (mainWindow->isOpen()){
		while (mainWindow->pollEvent(event)){
			if (event.type == sf::Event::Closed)
				mainWindow->close();
		}
		//updateConnection();
		if (socketSelector.wait()){
			if (socketSelector.isReady(listener)){
			}
		}
		mainWindow->clear();
		draw();
		mainWindow->display();
	}
}
void Lobby::draw(){

}