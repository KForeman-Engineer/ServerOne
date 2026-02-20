


/*
ServerOne Version 0.1

Features:
    - Start up localNetwork Server [X]
    - Can view json logs with curl [X]
    - Can serve HTML [X]
*/


# include "crow.h"

// Contain Server Logic for Above Functionality
class Server
{
    public:
        void StartServer()
        {
            crow::SimpleApp ServerApp;

            // Start Server with port
            RouteRequest(ServerApp);
        };


        void RouteRequest(crow::SimpleApp App)
        {
            CROW_ROUTE(App, "/")([]()
            {
                auto page = crow::mustache::load_text("index.html");
                return page;
            });
            App.port(8080).multithreaded().run();
        };
};








// Main Entry point
int main()
{
    Server ServerOne;
    ServerOne.StartServer();
    return 0;
};