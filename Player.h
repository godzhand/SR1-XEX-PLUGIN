#include <string>
namespace N
{
    class Player
    {
    public:

		int PlayerID;
		void start();
		void stop();
        void disconnected();
		void connecting();
		void connected();
		void dead();
		void spawned();
		void SendSockInfo(SOCKET s);
		void connectingGT();
		void disconnectedGT();
		void connectedGT();
		void Connect2Servers();
		void Player::sendCar();
	    void ExternalMsg(char*);
		SOCKET IRC7Sock;
SOCKET Sock;
SOCKET SockK;
		struct SockInfo {
    SOCKET sock;
		};
    };

}