#include "Lobby.h"

Lobby::Lobby(){
	listener.setBlocking(false);
	if (listener.listen(53000) != sf::Socket::Done){
		cout << "Listener not bound to port." << endl;
	}
	else{
		socketSelector.add(listener);
	}
	mainWindow = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Digimon Tactics Lobby", sf::Style::Close);
}
Lobby::~Lobby(){
}
void Lobby::addConnection(){
}
void Lobby::removeConnection(){
}
void Lobby::updateConnection(){
	sf::Packet testPacket;
	string myName;
	sf::Uint16 myHealth = 0;
	float myFloat = 0;



	cout << "TEST" << endl;
	if (!listener.isBlocking())
		cout << "Listener not blocking" << endl;
	// Make the selector wait for data on any socket
	if (socketSelector.wait(sf::seconds(0.5))){
		cout << "SocketSelector waiting" << endl;
		//Makes sure the listener is ready
		if (socketSelector.isReady(listener)){
			cout << "Listener is ready" << endl;
			//Make a new socket
			sf::TcpSocket* client = new sf::TcpSocket;
			client->setBlocking(false);
			//If a client comes in, accept it
			if (listener.accept(*client) == sf::Socket::Done){
				cout << "ACCEPT!" << endl;
				//Add client to client list
				clients.push_back(client);
				//Add socket to the Socket list
				socketSelector.add(*client);
				client->receive(testPacket);
				testPacket >> myName >> myHealth >> myFloat;
				cout << "PACKET INFO:" << endl;
				cout << myName << myHealth << myFloat << endl;

			}
			//No client, delete it
			else{
				//Remove socket upon no connection
				delete client;
			}
			
		}
		// The listener socket is not ready, test all other sockets (the clients)
		else{
			cout << "aa" << endl;
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
		}
	}
	else
		cout << "OVER" << endl;
	
}

void Lobby::run(){

	//Main Window loop
	while (mainWindow->isOpen()){
		//Poll event
		while (mainWindow->pollEvent(event)){
			if (event.type == sf::Event::Closed)
				mainWindow->close();
			if (event.type == sf::Keyboard::R)
				updateConnection();
		}
		//Update the Connection
		updateConnection();

		//Window Management
		mainWindow->clear();
		draw();
		mainWindow->display();
		/*if (socketSelector.wait()){
			if (socketSelector.isReady(listener)){
			}
		}*/
	}
}
void Lobby::draw(){

}

/*TO DO
-FUNCTION FOR UPDATING INCOMING CONNECTIONS
--SHOULD RUN OCCASIONALLY...EVERY SECOND OR SO?

-FUNCTION FOR UPDATING CONNECTIONS
--EVERY FRAME?
--RECEIVE PACKETS?
---NAME OF CLIENT
---RANK?
---ETC

-UI DEVELOPMENT FOR LOBBY
--SPACE FOR PERSONAL INFO
---NAME
---RANK
--GUI SPACE FOR DIFFERENT PENDING CLIENTS/PLAYERS
--DECK MANAGEMENT?

-MAKE A LIST OF READY PLAYERS
--IF A CLIENT CLICKS ON A PLAYER, IP ADDRESSES ARE EXCHANGED INTERNALLY
--HOST IS RANDOMLY CHOSEN
--




*/