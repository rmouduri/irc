 #include <iostream>
 #include "command.hpp"

// 0xx REPLIES
std::string RPL_WELCOME(std::string prefix) {
    return ":Welcome to the IRC Network " + prefix;
}
std::string RPL_YOURHOST(std::string servername, std::string version) {
    return ":Your host is " + servername + ", running version " + version;
}
std::string RPL_CREATED(std::string date) {
    return ":This server was created " + date;
}
std::string RPL_MYINFO(std::string servername, std::string version, std::string usermodes, std::string channelmodes) {
    return servername + " " + version + " " + usermodes + " " + channelmodes;
}
std::string RPL_BOUNCE(std::string server, std::string port) {
    return ":Try server " + server + ", port " + port;
}

// 2xx REPLIES
std::string RPL_TRACELINK(std::string version, std::string dest, std::string server) {
    return "Link " + version + " " + dest + " " + server;
}
std::string RPL_TRACECONNECTING(std::string class_, std::string server) {
    return "Try. " + class_ + " " + server;
}
std::string RPL_TRACEHANDSHAKE(std::string class_, std::string server) {
    return "H.S. " + class_ + " " + server;
}
std::string RPL_TRACEUNKNOWN(std::string class_, std::string ip) {
    return "???? " + class_ + " " + ip;
}
std::string RPL_TRACEOPERATOR(std::string class_, std::string nick) {
    return "Oper " + class_ + " " + nick;
}
std::string RPL_TRACEUSER(std::string class_, std::string nick) {
    return "User " + class_ + " " + nick;
}
std::string RPL_TRACESERVER(std::string class_, std::string int1, std::string int2, std::string server, std::string nickname, std::string username, std::string host) {
    return "Serv " + class_ + " " + int1 + "S " + int2 + "C " + server + " " + nickname + "!" + username + "@ " + host;
}
std::string RPL_TRACENEWTYPE(std::string newtype, std::string client) {
    return newtype + " 0 " + client;
}
std::string RPL_TRACELOG(std::string logfile, std::string debug) {
    return "FILE " + logfile + " " + debug;
}
std::string RPL_STATSLINKINFO(std::string linkname, std::string sendq, std::string smessage, std::string sbytes, std::string rmessage, std::string rbytes, std::string time) {
    return linkname + " " + sendq + " " + smessage + " " + sbytes + " " + rmessage + " " + rbytes + " " + time;
}
std::string RPL_STATSCOMMANDS(std::string command, std::string count) {
    return command + " " + count;
}
std::string RPL_STATSCLINE(std::string host, std::string name, std::string port, std::string class_) {
    return "C " + host + " * " + name + " " + port + " " + class_;
}
std::string RPL_STATSNLINE(std::string host, std::string name, std::string port, std::string class_) {
    return "N " + host + " * " + name + " " + port + " " + class_;
}
std::string RPL_STATSILINE(std::string host1, std::string host2, std::string port, std::string class_) {
    return "I " + host1 + " * " + host2 + " " + port + " " + class_;
}
std::string RPL_STATSKLINE(std::string host, std::string username, std::string port, std::string class_) {
    return "K " + host + " * " + username + " " + port + " " + class_;
}
std::string RPL_STATSYLINE(std::string class_, std::string ping_freq, std::string connect_freq, std::string max_sendq) {
    return "Y " + class_ + " " + ping_freq + " " + connect_freq + " " + max_sendq;
}
std::string RPL_ENDOFSTATS(std::string stats_letter) {
    return stats_letter + " :End of /STATS report";
}
std::string RPL_STATSLLINE(std::string hostmask, std::string servername, std::string maxdepth) {
    return "L " + hostmask + " * " + servername + " " + maxdepth;
}
std::string RPL_STATSUPTIME() {
    return ":Server Up %d days %d:%02d:%02d";
}
std::string RPL_STATSOLINE(std::string hostmask, std::string name) {
    return "O " + hostmask + " * " + name;
}
std::string RPL_STATSHLINE(std::string hostmask, std::string servername) {
    return "H " + hostmask + " * " + servername;
}
std::string RPL_UMODEIS(std::string user_mode) {
    return user_mode;
}
std::string RPL_LUSERCLIENT(std::string int1, std::string int2, std::string int3) {
    return ":There are " + int1 + " users and " + int2 + " invisible on " + int3 + " servers";
}
std::string RPL_LUSEROP(std::string int_) {
    return int_ + " :operator(s) online";
}
std::string RPL_LUSERUNKNOWN(std::string int_) {
    return int_ + " :unknown connection(s)";
}
std::string RPL_LUSERCHANNELS(std::string int_) {
    return int_ + " :channels formed";
}
std::string RPL_LUSERME(std::string int1, std::string int2) {
    return ":I have " + int1 + " clients and " + int2 + " servers";
}
std::string RPL_ADMINME(std::string server) {
    return server + " :Administrative info";
}
std::string RPL_ADMINLOC1(std::string admin_info) {
    return ":" + admin_info;
}
std::string RPL_ADMINLOC2(std::string admin_info) {
    return ":" + admin_info;
}
std::string RPL_ADMINEMAIL(std::string admin_info) {
    return ":" + admin_info;
}

//3xx REPLIES
std::string RPL_NONE() {
    return "";
}
std::string RPL_USERHOST(std::string replies) {
    return ":" + replies;
}
std::string RPL_ISON(std::string nicks) {
    return ":" + nicks;
}
std::string RPL_AWAY(std::string nick, std::string message) {
    return nick + " :" + message;
}
std::string RPL_UNAWAY() {
    return ":You are no longer marked as being away";
}
std::string RPL_NOWAWAY() {
    return ":You have been marked as being away";
}
std::string RPL_WHOISUSER(std::string nick, std::string user, std::string host, std::string realname) {
    return nick + " " + user + " " + host + " * :" + realname;
}
std::string RPL_WHOISSERVER(std::string nick, std::string server, std::string server_info) {
    return nick + " " + server + " :" + server_info;
}
std::string RPL_WHOISOPERATOR(std::string nick) {
    return nick + " :is an IRC operator";
}
std::string RPL_WHOISIDLE(std::string nick, std::string int_) {
    return nick + " " + int_ + " :seconds idle";
}
std::string RPL_ENDOFWHOIS(std::string nick) {
    return nick + " :End of /WHOIS list";
}
std::string RPL_WHOISCHANNELS(std::string nick, std::string channels) {
    return nick + " :" + channels;
}
std::string RPL_WHOWASUSER(std::string nick, std::string user, std::string host, std::string real_name) {
    return nick + " " + user + " " + host + " * :" + real_name;
}
std::string RPL_ENDOFWHOWAS(std::string nick) {
    return nick + " :End of WHOWAS";
}
std::string RPL_LISTSTART() {
    return "Channel :Users Name";
}
std::string RPL_LIST(std::string channel, std::string visible, std::string topic) {
    return channel + " " + visible + " :" + topic;
}
std::string RPL_LISTEND() {
    return ":End of /LIST";
}
std::string RPL_CHANNELMODEIS(std::string channel, std::string mode, std::string mode_param) {
    return channel + " " + mode + " " + mode_param;
}
std::string RPL_NOTOPIC(std::string channel) {
    return channel + " :No topic is iset";
}
std::string RPL_TOPIC(std::string channel, std::string topic) {
    return channel + " :" + topic;
}
std::string RPL_INVITING(std::string channel, std::string nick) {
    return channel + " " + nick;
}
std::string RPL_SUMMONING(std::string user) {
    return user + " :Summoning user to IRC";
}
std::string RPL_VERSION(std::string version, std::string server, std::string comments) {
    return version + " " + server + " :" + comments;
}
std::string RPL_WHOREPLY(std::string channel, std::string user, std::string host, std::string server, std::string nick, std::string state, std::string realname) {
    return channel + " " + user + " " + host + " " + server + " " + nick + " " + state + " :0 " + realname;
}
std::string RPL_ENDOFWHO(std::string name) {
    return name + " :End of /WHO list";
}
std::string RPL_NAMREPLY(std::string mod, std::string channel, std::string nicks) {
    return mod + " " + channel + " :" + nicks;
}
std::string RPL_ENDOFNAMES(std::string channel) {
    return channel + " :End of /NAMES list";
}
std::string RPL_LINKS(std::string mask, std::string server, std::string hopcount, std::string serverinfo) {
    return mask + " " + server + " :" + hopcount + " " + serverinfo;
}
std::string RPL_ENDOFLINKS(std::string mask) {
    return mask + " :End of /LINKS list";
}
std::string RPL_BANLIST(std::string channel, std::string banid) {
    return channel + " " + banid;
}
std::string RPL_ENDOFBANLIST(std::string channel) {
    return channel + " :End of channel ban list";
}
std::string RPL_INFO(std::string str) {
    return ":" + str;
}
std::string RPL_ENDOFINFO() {
    return ":End of /INFO list";
}
std::string RPL_MOTDSTART(std::string server) {
    return ":- " + server + " Message of the day - ";
}
std::string RPL_MOTD(std::string text) {
    return ":- " + text;
}
std::string RPL_ENDOFMOTD() {
    return ":End of /MOTD command";
}
std::string RPL_YOUREOPER() {
    return ":You are now an IRC operator";
}
std::string RPL_REHASHING(std::string config_file) {
    return config_file + " :Rehashing";
}
std::string RPL_TIME(std::string server, std::string local_time) {
    return server + " :" + local_time;
}
std::string RPL_USERSTART() {
    return ":UserID Terminal Host";
}
std::string RPL_USERS() {
    return ":%-8s %-9s %-8s";
}
std::string RPL_ENDOFUSERS() {
    return ":End of users";
}
std::string RPL_NOUSERS() {
    return ":Nobody logged in";
}
//4xx REPLIES (errors)
std::string ERR_NOSUCHNICK(std::string nickname) {
    return nickname + " :No such nick/channel";
}
std::string ERR_NOSUCHSERVER(std::string server) {
    return server + " :No such server";
}
std::string ERR_NOSUCHCHANNEL(std::string channel) {
    return channel + " :No such channel";
}
std::string ERR_CANNOTSENDTOCHAN(std::string channel) {
    return channel + " :Cannot send to channel";
}
std::string ERR_TOOMANYCHANNELS(std::string channel) {
    return channel + " :You have joined too many";
}
std::string ERR_WASNOSUCHNICK(std::string nickname) {
    return nickname + " :There was no such nickname";
}
std::string ERR_TOOMANYTARGETS(std::string target) {
    return target + " :Duplicate recipients. No message delivered";
}
std::string ERR_NOORIGIN() {
    return ":No origin specified";
}
std::string ERR_NORECIPIENT(std::string command) {
    return ":No recipient given (" + command + ")";
}
std::string ERR_NOTESTTOSEND() {
    return ":No text to send";
}
std::string ERR_NOTOPLEVEL(std::string mask) {
    return mask + " :No toplevel domain specified";
}
std::string ERR_WILDTOPLEVEL(std::string mask) {
    return mask + " :Wildcard in toplevel domain";
}
std::string ERR_UNKNOWNCOMMAND(std::string command) {
    return command + " :Unknown command";
}
std::string ERR_NOMOTD() {
    return ":MOTD File is missing";
}
std::string ERR_NOADMININFO(std::string server) {
    return server + " :No administrative info available";
}
std::string ERR_FILEERROR(std::string file_op, std::string file) {
    return ":File error doing " + file_op + " on " + file;
}
std::string ERR_NONICKNAMEGIVEN() {
    return ":No nickname given";
}
std::string ERR_ERRONEUSNICKNAME(std::string nickname) {
    return nickname + " :Erroneus nickname";
}
std::string ERR_NICKNAMEINUSE(std::string nickname) {
    return nickname + " :Nickname is already in use";
}
std::string ERR_NICKCOLLISION(std::string nickname) {
    return nickname + " :Nickname collision kill";
}
std::string ERR_USERNOTINCHANNEL(std::string nick, std::string channel) {
    return nick + " " + channel + " :They aren't on that channel";
}
std::string ERR_NOTONCHANNEL(std::string channel) {
    return channel + " :You're not on that channel";
}
std::string ERR_USERONCHANNEL(std::string user, std::string channel) {
    return user + " " + channel + " :is already on channel";
}
std::string ERR_NOLOGIN(std::string user) {
    return user + " :User not logged in";
}
std::string ERR_SUMMONDISABLED() {
    return ":SUMMON has been disabled";
}
std::string ERR_USERSDISABLED() {
    return ":USERS has been disabled";
}
std::string ERR_NOTREGISTERED() {
    return ":You have not registered";
}
std::string ERR_NEEDMOREPARAMS(std::string command) {
    return command + " :Not enough parameters";
}
std::string ERR_ALREADYREGISTRED() {
    return ":You may not register";
}
std::string ERR_PASSWDMISMATCH() {
    return ":Password incorrect";
}
std::string ERR_YOUREBANNEDCREEP() {
    return ":You are banned from this server";
}
std::string ERR_KEYSET(std::string channel) {
    return channel + " :Channel key already set";
}
std::string ERR_CHANNELISFULL(std::string channel) {
    return channel + " :Cannot join channel (+1)";
}
std::string ERR_UNKNOWNMODE(std::string char_) {
    return char_ + " :is unknown mode char to me";
}
std::string ERR_INVITEONLYCHAN(std::string channel) {
    return channel + " :Cannot join channel (+i)";
}
std::string ERR_BANNEDFROMCHAN(std::string channel) {
    return channel + " :Cannot join channel (+b)";
}
std::string ERR_BADCHANNELKEY(std::string channel) {
    return channel + " :Cannot join channel (+k)";
}
std::string ERR_NOPRIVILEGES() {
    return ":Permission Denied- You're not an IRC operator";
}
std::string ERR_CHANOPRIVSNEEDED(std::string channel) {
    return channel + " :You're not channel operator";
}
std::string ERR_CANTKILLSERVER() {
    return ":You cant kill a server!";
}
std::string ERR_NOOPERHOST() {
    return ":No O-lines for your host";
}
//5xx REPLIES
std::string ERR_UMODEUNKNOWNFLAG() {
    return ":Unknown MODE flag";
}
std::string ERR_USERSDONTMATCH() {
    return ":Cant change mode for other users";
}

std::string get_replies(unsigned int rpl, std::string arg1, std::string arg2, std::string arg3, std::string arg4, std::string arg5, std::string arg6, std::string arg7) {
    std::string toSend;
    switch (rpl) {
        case 001:
            return RPL_WELCOME(arg1);
        case 002:
            return RPL_YOURHOST(arg1, arg2);
        case 003:
            return RPL_CREATED(arg1);
        case 004:
            return RPL_MYINFO(arg1, arg2, arg3, arg4);
        case 005:
            return RPL_BOUNCE(arg1, arg2);
        case 200:
            return RPL_TRACELINK(arg1, arg2, arg3);
        case 201:
            return RPL_TRACECONNECTING(arg1, arg2);
        case 202:
            return RPL_TRACEHANDSHAKE(arg1, arg2);
        case 203:
            return RPL_TRACEUNKNOWN(arg1, arg2);
        case 204:
            return RPL_TRACEOPERATOR(arg1, arg2);
        case 205:
            return RPL_TRACEUSER(arg1, arg2);
        case 206:
            return RPL_TRACESERVER(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        case 208:
            return RPL_TRACENEWTYPE(arg1, arg2);
        case 211:
            return RPL_STATSLINKINFO(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        case 212:
            return RPL_STATSCOMMANDS(arg1, arg2);
        case 213:
            return RPL_STATSCLINE(arg1, arg2, arg3, arg4);
        case 214:
            return RPL_STATSNLINE(arg1, arg2, arg3, arg4);
        case 215:
            return RPL_STATSILINE(arg1, arg2, arg3, arg4);
        case 216:
            return RPL_STATSKLINE(arg1, arg2, arg3, arg4);
        case 218:
            return RPL_STATSYLINE(arg1, arg2, arg3, arg4);
        case 219:
            return RPL_ENDOFSTATS(arg1);
        case 221:
            return RPL_UMODEIS(arg1);
        case 241:
            return RPL_STATSLLINE(arg1, arg2, arg3);
        case 242:
            return RPL_STATSUPTIME();
        case 243:
            return RPL_STATSOLINE(arg1, arg2);
        case 244:
            return RPL_STATSHLINE(arg1, arg2);
        case 251:
            return RPL_LUSERCLIENT(arg1, arg2, arg3);
        case 252:
            return RPL_LUSEROP(arg1);
        case 253:
            return RPL_LUSERUNKNOWN(arg1);
        case 254:
            return RPL_LUSERCHANNELS(arg1);
        case 255:
            return RPL_LUSERME(arg1, arg2);
        case 256:
            return RPL_ADMINME(arg1);
        case 257:
            return RPL_ADMINLOC1(arg1);
        case 258:
            return RPL_ADMINLOC2(arg1);
        case 259:
            return RPL_ADMINEMAIL(arg1);
        case 261:
            return RPL_TRACELOG(arg1, arg2);
        // case 262:
        //     return RPL_TRACEEND(arg1, arg2);
        // case 263:
        //     return RPL_TRYAGAIN(arg1);
        case 300:
		    return RPL_NONE();
        case 301:
            return RPL_AWAY(arg1, arg2);
        case 302:
            return RPL_USERHOST(arg1);
        case 303:
            return RPL_ISON(arg1);
        case 305:
            return RPL_UNAWAY();
        case 306:
            return RPL_NOWAWAY();
        case 311:
            return RPL_WHOISUSER(arg1, arg2, arg3, arg4);
        case 312:
            return RPL_WHOISSERVER(arg1, arg2, arg3);
        case 313:
            return RPL_WHOISOPERATOR(arg1);
        case 314:
            return RPL_WHOWASUSER(arg1, arg2, arg3, arg4);
        case 315:
            return RPL_ENDOFWHO(arg1);
        case 317:
            return RPL_WHOISIDLE(arg1, arg2);
        case 318:
            return RPL_ENDOFWHOIS(arg1);
        case 319:
            return RPL_WHOISCHANNELS(arg1, arg2);
        case 321:
            return RPL_LISTSTART();
        case 322:
            return RPL_LIST(arg1, arg2, arg3);
        case 323:
            return RPL_LISTEND();
        case 324:
            return RPL_CHANNELMODEIS(arg1, arg2, arg3);
        // case 325:
        //     return RPL_UNIQOPIS(arg1, arg2);
        case 331:
            return RPL_NOTOPIC(arg1);
        case 332:
            return RPL_TOPIC(arg1, arg2);
        case 341:
            return RPL_INVITING(arg1, arg2);
        case 342:
            return RPL_SUMMONING(arg1);
        // case 346:
        //     return RPL_INVITELIST(arg1, arg2);
        // case 347:
        //     return RPL_ENDOFINVITELIST(arg1);
        // case 348:
        //     return RPL_EXCEPTLIST(arg1, arg2);
        case 351:
            return RPL_VERSION(arg1, arg2, arg3);
        case 352:
            return RPL_WHOREPLY(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        case 353:
            return RPL_NAMREPLY(arg1, arg2, arg3);
        case 364:
            return RPL_LINKS(arg1, arg2, arg3, arg4);
        case 365:
            return RPL_ENDOFLINKS(arg1);
        case 366:
            return RPL_ENDOFNAMES(arg1);
        case 367:
            return RPL_BANLIST(arg1, arg2);
        case 368:
            return RPL_ENDOFBANLIST(arg1);
        case 369:
            return RPL_ENDOFWHOWAS(arg1);
        case 371:
            return RPL_INFO(arg1);
        case 372:
            return RPL_MOTD(arg1);
        case 374:
            return RPL_ENDOFINFO();
        case 375:
            return RPL_MOTDSTART(arg1);
        case 376:
            return RPL_ENDOFMOTD();
        case 381:
            return RPL_YOUREOPER();
        case 382:
            return RPL_REHASHING(arg1);
        // case 383:
        //     return RPL_YOURESERVICE(arg1);
        case 391:
            return RPL_TIME(arg1, arg2);
        // case 392:
        //     return RPL_USERSSTART();
        case 393:
            return RPL_USERS();
        case 394:
            return RPL_ENDOFUSERS();
        case 395:
            return RPL_NOUSERS();

        case 401:
            return ERR_NOSUCHNICK(arg1);
        case 402:
            return ERR_NOSUCHSERVER(arg1);
        case 403:
            return ERR_NOSUCHCHANNEL(arg1);
        case 404:
            return ERR_CANNOTSENDTOCHAN(arg1);
        case 405:
            return ERR_TOOMANYCHANNELS(arg1);
        case 406:
            return ERR_WASNOSUCHNICK(arg1);
        case 407:
            return ERR_TOOMANYTARGETS(arg1);
        // case 408:
        //     return ERR_NOSUCHSERVICE(arg1);
        case 409:
            return ERR_NOORIGIN();
        case 411:
            return ERR_NORECIPIENT(arg1);
        // case 412:
        //     return ERR_NOTEXTTOSEND();
        case 413:
            return ERR_NOTOPLEVEL(arg1);
        case 414:
            return ERR_WILDTOPLEVEL(arg1);
        // case 415:
        //     return ERR_BADMASK(arg1);
        case 421:
            return ERR_UNKNOWNCOMMAND(arg1);
        case 422:
            return ERR_NOMOTD();
        case 423:
            return ERR_NOADMININFO(arg1);
        case 424:
            return ERR_FILEERROR(arg1, arg2);
        case 431:
            return ERR_NONICKNAMEGIVEN();
        case 432:
            return ERR_ERRONEUSNICKNAME(arg1);
        case 433:
            return ERR_NICKNAMEINUSE(arg1);
        case 436:
            return ERR_NICKCOLLISION(arg1);
        case 441:
            return ERR_USERNOTINCHANNEL(arg1, arg2);
        case 442:
            return ERR_NOTONCHANNEL(arg1);
        case 443:
            return ERR_USERONCHANNEL(arg1, arg2);
        case 444:
            return ERR_NOLOGIN(arg1);
        case 445:
            return ERR_SUMMONDISABLED();
        case 446:
            return ERR_USERSDISABLED();
        case 451:
            return ERR_NOTREGISTERED();

        case 461:
            return ERR_NEEDMOREPARAMS(arg1);
        case 462:
            return ERR_ALREADYREGISTRED();
        // case 463:
        //     return ERR_NOPERMFORHOST();
        case 464:
            return ERR_PASSWDMISMATCH();
        case 465:
            return ERR_YOUREBANNEDCREEP();
        case 467:
            return ERR_KEYSET(arg1);
        case 471:
            return ERR_CHANNELISFULL(arg1);
        case 472:
            return ERR_UNKNOWNMODE(arg1);
        case 473:
            return ERR_INVITEONLYCHAN(arg1);
        case 474:
            return ERR_BANNEDFROMCHAN(arg1);
        case 475:
            return ERR_BADCHANNELKEY(arg1);
        // case 476:
        //     return ERR_BADCHANMASK(arg1);
        // case 477:
        //     return ERR_NOCHANMODES(arg1);
        // case 478:
        //     return ERR_BANLISTFULL(arg1);
        case 481:
            return ERR_NOPRIVILEGES();
        case 482:
            return ERR_CHANOPRIVSNEEDED(arg1);
        case 483:
            return ERR_CANTKILLSERVER();
        // case 484:
        //     return ERR_RESTRICTED();
        // case 485:
        //     return ERR_UNIQOPPRIVSNEEDED();
        case 491:
            return ERR_NOOPERHOST();

        case 501:
            return ERR_UMODEUNKNOWNFLAG();
        case 502:
            return ERR_USERSDONTMATCH();
        default:
            return std::string();
    }
}