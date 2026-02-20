

// Include Iserver for interface
# include "IServer.hpp"
# include "crow.h"
# include <iostream>
# include <string>
# include <fstream>


using namespace std;
//using namespace crow;



// Override Server Functions
class ServerCrow:Server
{

    private:
        void Route(crow::SimpleApp& App)
        {
            GenLog("[INFO] --> Sucessfully Created a Route to index.html");

            CROW_ROUTE(App, "/")([]()
            {
                auto page = crow::mustache::load_text("index.html");
                return page;
            });
        }

    public:

        // Server Entry Point
        void StartServer() override
        {
            crow::SimpleApp ServerApp;
            GenLog("[INFO] -- > Sucessfully Started Server!");
            Route(ServerApp);
            ServerApp.port(8080).multithreaded().run();

            
        }

        int GenLog(string Data) override
        {
            ofstream FileStream;


            FileStream.open("Log.txt", ios::app);


            // check if File is open
            if (!FileStream.is_open())
            {
                return 1;
            }
            else
            {
                FileStream  << Data << endl;
                FileStream.close();
                return 0;
            }
        };



};