/*
ServerOne Interface 


Seperates Libraries for modularity
*/


# include <string>


#ifndef IServer_hpp
#define IServer_hpp

using namespace std;

// Server Class
class Server
{
    private:
        int SERVERPORT = 8080;

    public:

        // Basic Server Functions more later
        virtual void StartServer(){}
        // virtual void Serve(){}; // Serves Webpages 
        virtual int GenLog(string Data){return 1;}; // Generates Logs 
        virtual void Response(){};

        // Used to set Values as SERVERPORT is private
        int Get(){return SERVERPORT;};
        int Set(int Port){SERVERPORT = Port; return 0;}

};


#endif



