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
		SOCKET Sock;
	    void ExternalMsg(char*);
		struct SockInfo {
    SOCKET sock;
		};
    };

}