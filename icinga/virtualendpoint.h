/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012 Icinga Development Team (http://www.icinga.org/)        *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software Foundation     *
 * Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.            *
 ******************************************************************************/

#ifndef VIRTUALENDPOINT_H
#define VIRTUALENDPOINT_H

namespace icinga
{

struct I2_ICINGA_API NewRequestEventArgs : public EventArgs
{
	typedef shared_ptr<NewRequestEventArgs> Ptr;
	typedef weak_ptr<NewRequestEventArgs> WeakPtr;

	Endpoint::Ptr Sender;
	JsonRpcRequest Request;
};

class I2_ICINGA_API VirtualEndpoint : public Endpoint
{
private:
	map< string, Event<NewRequestEventArgs> > m_MethodHandlers;

public:
	typedef shared_ptr<VirtualEndpoint> Ptr;
	typedef weak_ptr<VirtualEndpoint> WeakPtr;

	void RegisterMethodHandler(string method, function<int (const NewRequestEventArgs&)> callback);
	void UnregisterMethodHandler(string method, function<int (const NewRequestEventArgs&)> callback);

	virtual string GetAddress(void) const;

	virtual bool IsLocal(void) const;
	virtual bool IsConnected(void) const;

	virtual void ProcessRequest(Endpoint::Ptr sender, const JsonRpcRequest& message);
	virtual void ProcessResponse(Endpoint::Ptr sender, const JsonRpcResponse& message);

	virtual void Stop(void);
};

}

#endif /* VIRTUALENDPOINT_H */
