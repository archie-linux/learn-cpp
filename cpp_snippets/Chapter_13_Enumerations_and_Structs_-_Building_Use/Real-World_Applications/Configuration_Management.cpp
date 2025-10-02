struct ServerConfig 
{
    std::string host = "localhost";
    int port = 8080;
    int maxConnections = 100;
    bool enableLogging = true;
    double timeoutSeconds = 30.0;
};
