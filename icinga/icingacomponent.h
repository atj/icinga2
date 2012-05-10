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

#ifndef ICINGACOMPONENT_H
#define ICINGACOMPONENT_H

namespace icinga
{

class I2_ICINGA_API IcingaComponent : public Component
{
protected:
	IcingaApplication::Ptr GetIcingaApplication(void) const;
	EndpointManager::Ptr GetEndpointManager(void) const;
	ConfigHive::Ptr GetConfigHive(void) const;
};

}

#endif /* ICINGACOMPONENT_H */
