/****************************************************************************
* RetroMessenger - Serverless & Secure Instant Messenger
* build with wxWidgets gui toolkit based on libretroshare (c++)
*
* Copyright (c) 2008 Ryan Pusztai, Mahendra Panpalia and the RetroMessenger Team
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
* http://www.gnu.org/licenses/gpl-2.0.html
*
* Please report all praise, requests, bugs and problems to the project
* team & admins: http://sourceforge.net/projects/retromessenger
*
* For the libretroshare library see the updates here:
* http://sourceforge.net/projects/retroshare/
*
* You can find us listed at our projectpage. New team members are welcome.
* Please keep in touch, if you use this code for other projects.
*
* Website:
*	   http://sourceforge.net/projects/retromessenger/
*      http://retromessenger.sf.net
*****************************************************************************/

#include "NotifyTxt.h"

// RetroShare
#include <rsiface/rspeers.h>

// STL
#include <iostream>
#include <sstream>

void NotifyTxt::notifyErrorMsg( int list, int type, std::string msg )
{
	return;
}

void NotifyTxt::notifyChat()
{
	return;
}

void NotifyTxt::notifyListChange( int list, int type )
{
	std::cerr << "NotifyTxt::notifyListChange()" << std::endl;
	switch(list)
	{
		case NOTIFY_LIST_NEIGHBOURS:
			displayNeighbours();
			break;
		case NOTIFY_LIST_FRIENDS:
			displayFriends();
			break;
		case NOTIFY_LIST_DIRLIST_LOCAL:
			displayDirectories();
			break;
		case NOTIFY_LIST_SEARCHLIST:
			displaySearch();
			break;
		case NOTIFY_LIST_MESSAGELIST:
			displayMessages();
			break;
		case NOTIFY_LIST_CHANNELLIST:
			displayChannels();
			break;
		case NOTIFY_LIST_TRANSFERLIST:
			displayTransfers();
			break;
		default:
			break;
	}
	return;
}

			
			
void NotifyTxt::displayNeighbours()
{
	std::list<std::string> ids;
	std::list<std::string>::iterator it;

	rsPeers->getOthersList(ids);

	std::ostringstream out;
	for(it = ids.begin(); it != ids.end(); it++)
	{
		RsPeerDetails detail;
		rsPeers->getPeerDetails(*it, detail);

		out << "Neighbour: ";
		out << detail;
		out << std::endl;
	}
	std::cerr << out.str();
}

void NotifyTxt::displayFriends()
{
	std::list<std::string> ids;
	std::list<std::string>::iterator it;

	rsPeers->getFriendList(ids);

	std::ostringstream out;
	for(it = ids.begin(); it != ids.end(); it++)
	{
		RsPeerDetails detail;
		rsPeers->getPeerDetails(*it, detail);

		out << "Neighbour: ";
		out << detail;
		out << std::endl;
	}
	std::cerr << out.str();
}

void NotifyTxt::displayDirectories()
{
	iface->lockData(); /* Lock Interface */

	std::ostringstream out;
	std::cerr << out.str();

	iface->unlockData(); /* UnLock Interface */
}


void NotifyTxt::displaySearch()
{
	iface->lockData(); /* Lock Interface */

	std::ostringstream out;
	std::cerr << out.str();

	iface->unlockData(); /* UnLock Interface */
}


void NotifyTxt::displayMessages()
{
	iface->lockData(); /* Lock Interface */
	iface->unlockData(); /* UnLock Interface */
}

void NotifyTxt::displayChannels()
{
	iface->lockData(); /* Lock Interface */

	std::ostringstream out;
	std::cerr << out.str();

	iface->unlockData(); /* UnLock Interface */
}


void NotifyTxt::displayTransfers()
{
	iface->lockData(); /* Lock Interface */

	std::ostringstream out;
	std::cerr << out.str();

	iface->unlockData(); /* UnLock Interface */
}

