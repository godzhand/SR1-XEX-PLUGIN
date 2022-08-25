#include <string>
namespace N
{
    class sp
    {
    public:
		void start();
		void stop();
		void connected();
		void dead();
	    void ExternalMsg(char*);
			SOCKET Sock;
    };

}