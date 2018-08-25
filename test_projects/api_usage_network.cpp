
// Including all files to make sure we don't delete some by mistake

#include <SFML/Network.hpp>
#include <SFML/Network/Export.hpp>
#include <SFML/Network/Ftp.hpp>
#include <SFML/Network/Http.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/Socket.hpp>
#include <SFML/Network/SocketHandle.hpp>
#include <SFML/Network/SocketSelector.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/UdpSocket.hpp>

#include <iostream>

void test_ftp_hpp()
{
    sf::Ftp ftp;
    sf::Ftp::TransferMode mode = sf::Ftp::Binary;
    mode = sf::Ftp::Ascii;
    mode = sf::Ftp::Ebcdic;
    
    sf::Ftp::Response resp;
    sf::Ftp::Response::Status status;
    status = sf::Ftp::Response::RestartMarkerReply;
    status = sf::Ftp::Response::ServiceReadySoon;
    status = sf::Ftp::Response::DataConnectionAlreadyOpened;
    status = sf::Ftp::Response::OpeningDataConnection;
    status = sf::Ftp::Response::Ok;
    status = sf::Ftp::Response::PointlessCommand;
    status = sf::Ftp::Response::SystemStatus;
    status = sf::Ftp::Response::DirectoryStatus;
    status = sf::Ftp::Response::FileStatus;
    status = sf::Ftp::Response::HelpMessage;
    status = sf::Ftp::Response::SystemType;
    status = sf::Ftp::Response::ServiceReady;
    status = sf::Ftp::Response::ClosingConnection;
    status = sf::Ftp::Response::DataConnectionOpened;
    status = sf::Ftp::Response::ClosingDataConnection;
    status = sf::Ftp::Response::EnteringPassiveMode;
    status = sf::Ftp::Response::LoggedIn;
    status = sf::Ftp::Response::FileActionOk;
    status = sf::Ftp::Response::DirectoryOk;
    status = sf::Ftp::Response::NeedPassword;
    status = sf::Ftp::Response::NeedAccountToLogIn;
    status = sf::Ftp::Response::NeedInformation;
    status = sf::Ftp::Response::ServiceUnavailable;
    status = sf::Ftp::Response::DataConnectionUnavailable;
    status = sf::Ftp::Response::TransferAborted;
    status = sf::Ftp::Response::FileActionAborted;
    status = sf::Ftp::Response::LocalError;
    status = sf::Ftp::Response::InsufficientStorageSpace;
    status = sf::Ftp::Response::CommandUnknown;
    status = sf::Ftp::Response::ParametersUnknown;
    status = sf::Ftp::Response::CommandNotImplemented;
    status = sf::Ftp::Response::BadCommandSequence;
    status = sf::Ftp::Response::ParameterNotImplemented;
    status = sf::Ftp::Response::NotLoggedIn;
    status = sf::Ftp::Response::NeedAccountToStore;
    status = sf::Ftp::Response::FileUnavailable;
    status = sf::Ftp::Response::PageTypeUnknown;
    status = sf::Ftp::Response::NotEnoughMemory;
    status = sf::Ftp::Response::FilenameNotAllowed;
    status = sf::Ftp::Response::InvalidResponse;
    status = sf::Ftp::Response::ConnectionFailed;
    status = sf::Ftp::Response::ConnectionClosed;
    status = sf::Ftp::Response::InvalidFile;
    
    resp = sf::Ftp::Response(status, std::string());
    bool r = resp.isOk();
    status = resp.getStatus();
    std::string msg = resp.getMessage();
    
    sf::Ftp::DirectoryResponse dresp(resp);
    std::string dir = dresp.getDirectory();
    
    sf::Ftp::ListingResponse lresp(resp, std::string());
    std::vector<std::string> list = lresp.getListing();
    
    ftp.connect(sf::IpAddress(), (unsigned short)21, sf::Time::Zero);
    resp = ftp.disconnect();
    resp = ftp.login();
    resp = ftp.login(std::string(), std::string());
    resp = ftp.keepAlive();
    dresp = ftp.getWorkingDirectory();
    lresp = ftp.getDirectoryListing(std::string());
    resp = ftp.changeDirectory(std::string());
    resp = ftp.parentDirectory();
    resp = ftp.createDirectory(std::string());
    resp = ftp.deleteDirectory(std::string());
    resp = ftp.renameFile(std::string(), std::string());
    resp = ftp.deleteFile(std::string());
    resp = ftp.download(std::string(), std::string(), sf::Ftp::Binary);
    resp = ftp.upload(std::string(), std::string(), sf::Ftp::TransferMode::Binary, false);
    resp = ftp.sendCommand(std::string(), std::string());
}

void test_http_hpp()
{
    sf::Http::Request::Method meth;
    meth = sf::Http::Request::Get;
    meth = sf::Http::Request::Post;
    meth = sf::Http::Request::Head;
    meth = sf::Http::Request::Put;
    meth = sf::Http::Request::Delete;
    
    sf::Http::Request req(std::string(), meth, std::string());
    req.setField(std::string(), std::string());
    req.setMethod(meth);
    req.setUri(std::string());
    req.setHttpVersion(1u, 2u);
    req.setBody(std::string());
    
    sf::Http::Response resp;
    sf::Http::Response::Status status;
    status = sf::Http::Response::Ok;
    status = sf::Http::Response::Created;
    status = sf::Http::Response::Accepted;
    status = sf::Http::Response::NoContent;
    status = sf::Http::Response::ResetContent;
    status = sf::Http::Response::PartialContent;
    status = sf::Http::Response::MultipleChoices;
    status = sf::Http::Response::MovedPermanently;
    status = sf::Http::Response::MovedTemporarily;
    status = sf::Http::Response::NotModified;
    status = sf::Http::Response::BadRequest;
    status = sf::Http::Response::Unauthorized;
    status = sf::Http::Response::Forbidden;
    status = sf::Http::Response::NotFound;
    status = sf::Http::Response::RangeNotSatisfiable;
    status = sf::Http::Response::InternalServerError;
    status = sf::Http::Response::NotImplemented;
    status = sf::Http::Response::BadGateway;
    status = sf::Http::Response::ServiceNotAvailable;
    status = sf::Http::Response::GatewayTimeout;
    status = sf::Http::Response::VersionNotSupported;
    status = sf::Http::Response::InvalidResponse;
    status = sf::Http::Response::ConnectionFailed;
    
    std::string field = resp.getField(std::string());
    status = resp.getStatus();
    unsigned int major = resp.getMajorHttpVersion();
    unsigned int minor = resp.getMinorHttpVersion();
    std::string body = resp.getBody();
    
    sf::Http defaultHttp;
    sf::Http http(std::string(), 2u);
    http.setHost(std::string(), 2u);
    resp = http.sendRequest(req, sf::Time::Zero);
}

void test_ipaddress_hpp()
{
    sf::IpAddress addr;
    sf::IpAddress straddr((std::string()));
    sf::IpAddress cstraddr((const char*)"");
    sf::IpAddress int8addr((sf::Uint8()), sf::Uint8(), sf::Uint8(), sf::Uint8());
    sf::IpAddress int32addr((sf::Uint32()));
    std::string str = addr.toString();
    sf::Uint32 u32 = addr.toInteger();
    addr = sf::IpAddress::getLocalAddress();
    addr = sf::IpAddress::getPublicAddress(sf::Time::Zero);
    addr = sf::IpAddress::None;
    addr = sf::IpAddress::Any;
    addr = sf::IpAddress::LocalHost;
    addr = sf::IpAddress::Broadcast;
    bool r = addr == addr;
    r = addr != addr;
    r = addr < addr;
    r = addr > addr;
    r = addr <= addr;
    r = addr >= addr;
    
    std::cout << r;
    std::cin >> r;
}
