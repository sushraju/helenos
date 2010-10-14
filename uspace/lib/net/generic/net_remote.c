/*
 * Copyright (c) 2009 Lukas Mejdrech
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - The name of the author may not be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/** @addtogroup net
 *  @{
 */

/** @file
 *  Networking interface implementation for remote modules.
 *  @see net_interface.h
 */

#include <ipc/services.h>

#include <malloc.h>

#include <generic.h>
#include <net/modules.h>
#include <net/device.h>
#include <net_interface.h>
#include <adt/measured_strings.h>
#include <net_net_messages.h>

int net_connect_module(services_t service)
{
	return connect_to_service(SERVICE_NETWORKING);
}

void net_free_settings(measured_string_ref settings, char * data)
{
	if (settings)
		free(settings);

	if (data)
		free(data);
}

int
net_get_conf_req(int net_phone, measured_string_ref * configuration,
    size_t count, char ** data)
{
	return generic_translate_req(net_phone, NET_NET_GET_DEVICE_CONF, 0, 0,
	    *configuration, count, configuration, data);
}

int
net_get_device_conf_req(int net_phone, device_id_t device_id,
    measured_string_ref * configuration, size_t count, char ** data)
{
	return generic_translate_req(net_phone, NET_NET_GET_DEVICE_CONF,
	    device_id, 0, *configuration, count, configuration, data);
}

/** @}
 */
