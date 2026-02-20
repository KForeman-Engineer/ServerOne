# include "IServer.hpp"
# include "ServerCrow.cpp"
# include <iostream>






int main()
{
    ServerCrow Server;
    


    std::cout << "Server Started on Port 8080! view Log";
    Server.StartServer();
}