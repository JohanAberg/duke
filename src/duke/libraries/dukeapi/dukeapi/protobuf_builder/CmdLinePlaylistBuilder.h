/*
 * CmdLinePlaylistBuilder.h
 *
 *  Created on: 22 fevr. 2012
 *      Author: Guillaume Chatelet
 */

#ifndef CMDLINEPLAYLISTBUILDER_H_
#define CMDLINEPLAYLISTBUILDER_H_

#include <dukeapi/protobuf_builder/PlaylistBuilder.h>

#include <boost/noncopyable.hpp>

#include <memory>

struct CmdLinePlaylistBuilder : private boost::noncopyable {
    CmdLinePlaylistBuilder(bool useContainingSequence, const char **validExtensions);
    void process(const std::string& entry);
    duke::protocol::Playlist getPlaylist() const ;

    struct Proxy{
        Proxy(CmdLinePlaylistBuilder &ptr) : ptr(ptr){}
        inline void operator()(const std::string& entry){ ptr.process(entry); }
        CmdLinePlaylistBuilder &ptr;
    };
    inline Proxy appender(){ return Proxy(*this); }
public:
    struct Pimpl;
private:
    std::auto_ptr<Pimpl> m_Pimpl;
};

#endif /* CMDLINEPLAYLISTBUILDER_H_ */